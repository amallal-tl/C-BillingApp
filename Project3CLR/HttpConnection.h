#pragma once
class HttpConnection {
    // Data members
private:
    std::string url; // The URL for the request
    std::string method; // The HTTP method (GET, POST, etc.)
    std::string data; // The data to send in the request body
    std::vector<std::string> headers; // The HTTP headers to send with the request
    // Member functions
public:
    HttpRequest(std::string url, std::string method, std::string data, std::vector<std::string> headers); // Constructor
    ~HttpRequest(); // Destructor
    int send(); // Send the request and return the result
};

