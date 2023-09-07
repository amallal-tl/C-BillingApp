// Include the header file
#include "HttpSocketManager.h"

// Define the static instance of the class as null

// Define the private constructor that initializes the socket and the endpoint
HttpSocketManager::HttpSocketManager(String^ host, int port)
{
    // Create a TCP socket
    sock = gcnew Socket(AddressFamily::InterNetworkV6, SocketType::Stream, ProtocolType::Tcp);

    // Resolve the host name to an IP address
    this->host = host;//"192.168.1.10"
    this->port = port;//8081
    IPHostEntry^ hostEntry = Dns::GetHostEntry(host);
    address = hostEntry->AddressList[0];

    // Create an endpoint with the IP address and port 80
    endPoint = gcnew IPEndPoint(address, port);
}

// Define the public method that connects to the server
void HttpSocketManager::Connect()
{
    // Connect to the server
    sock->Connect(endPoint);
    Console::WriteLine("Connected to {0}", sock->RemoteEndPoint);
}


// Define the public method that sends a request to the server
void HttpSocketManager::SendRequest(String^ httpMethod, String^ path, String^ body)
{
    //array<Byte>^ jsonBytes = Encoding::ASCII->GetBytes(requestBody);
    String^ request = httpMethod +" "+ path + " HTTP/1.1\r\nHost: " + host + ":" + port + "\r\nContent-Type: application/json\r\nContent-Length: "
        + body->Length + "\r\n\r\n" + body;

    //String^ request = "POST /newsales HTTP/1.1\r\nHost: localhost:8081\r\nContent-Type: application/json\r\nContent-Length: 115\r\n\r\n{ \"uniqueSaleId\":\"fadsf\",\"saleItem\":\"sadfafd\",\"saleQuantity\":\"dafsdf\",\"saleAmount\":12}";

    array<Byte>^ requestBytes = Encoding::ASCII->GetBytes(request);
    //requestBytes = Combine(requestBytes, jsonBytes); // Combine is a helper function that concatenates two byte arrays

    // Send the request
    sock->Send(requestBytes);
    Console::WriteLine("Sent {0} bytes", requestBytes->Length);
}

// Define the public method that receives a response from the server
String^ HttpSocketManager::ReceiveResponse()
{
    // Receive the response
    array<Byte>^ responseBytes = gcnew array<Byte>(4096);
    int bytesReceived = 0;
    StringBuilder^ response = gcnew StringBuilder();

    // Loop until the server closes the connection
    while ((bytesReceived = sock->Receive(responseBytes)) > 0)
    {
        // Append the received bytes to the response string
        response->Append(Encoding::ASCII->GetString(responseBytes, 0, bytesReceived));
    }

    // Return the response string
     return response->ToString();
}

String^ HttpSocketManager::parseResponse(String^ response) {
    array<Char>^ delimiter = { '\r', '\n' };
    array<System::String^>^ result = response->Split(delimiter, System::StringSplitOptions::RemoveEmptyEntries);
    String^ cropped = result[5];
    return cropped;
}

// Define the public method that closes the connection
void HttpSocketManager::Close()
{
    // Close the socket
    sock->Close();
    Console::WriteLine("Closed the connection");
}

// A helper function that concatenates two byte arrays into one array
array<Byte>^ Combine(array<Byte>^ arr1, array<Byte>^ arr2)
{
    // Create a new array with the size equal to the sum of the sizes of the two input arrays
    int size = arr1->Length + arr2->Length;
    array<Byte>^ result = gcnew array<Byte>(size);

    // Copy the elements of the first array into the new array starting from index 0
    for (int i = 0; i < arr1->Length; i++)
    {
        result[i] = arr1[i];
    }

    // Copy the elements of the second array into the new array starting from the index equal to the size of the first array
    for (int i = 0; i < arr2->Length; i++)
    {
        result[arr1->Length + i] = arr2[i];
    }

    // Return the new array
    return result;
}
