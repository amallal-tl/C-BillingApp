#include "HttpConnection.h"
#include "curl/curl.h"

HttpConnection::HttpRequest(std::string url, std::string method, std::string data, std::vector<std::string> headers) {
    // Initialize the data members with the parameters
    this->url = url;
    this->method = method;
    this->data = data;
    this->headers = headers;
}

int HttpConnection::send() {
    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        // Set the URL for the request using the url data member
        curl_easy_setopt(curl, CURLOPT_URL, this->url.c_str());
        // Set the POST method using the method data member
        if (this->method == "POST") {
            curl_easy_setopt(curl, CURLOPT_POST, 1);
        }
        // Set the POST data using the data data member
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, this->data.c_str());
        // Set the POST data size (optional)
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, this->data.length());
        // Set the HTTP headers using the headers data member
        struct curl_slist* headers = NULL;
        for (auto& header : this->headers) {
            headers = curl_slist_append(headers, header.c_str());
        }
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        // Perform the request and check the result
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
        }
        // Clean up
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
    else {
        res = -1;
    }
    return res;
}


const char* data = "{\"mainSaleId\": \"124\",\"uniqueSaleId\" : \"124\"," +
+\"totalAmount\" : 1.0,\"userId\" : \"123\",\"machineId\" : \"123\",\"salestatus\" : 1}";