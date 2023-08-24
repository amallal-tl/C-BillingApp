// Include the header file
#include "HttpSocketManager.h"

// Define the static instance of the class as null

// Define the private constructor that initializes the socket and the endpoint
HttpSocketManager::HttpSocketManager()
{
    // Create a TCP socket
    sock = gcnew Socket(AddressFamily::InterNetworkV6, SocketType::Stream, ProtocolType::Tcp);

    // Resolve the host name to an IP address
    host = "192.168.1.10";
    IPHostEntry^ hostEntry = Dns::GetHostEntry(host);
    address = hostEntry->AddressList[0];

    // Create an endpoint with the IP address and port 80
    endPoint = gcnew IPEndPoint(address, 8081);
}

// Define the public static method that returns the instance of the class
HttpSocketManager^ HttpSocketManager::GetInstance()
{
    // If the instance is null, create a new one
    if (instance == nullptr)
    {
        instance = gcnew HttpSocketManager();
    }

    // Return the instance
    return instance;
}

// Define the public method that connects to the server
void HttpSocketManager::Connect()
{
    // Connect to the server
    sock->Connect(endPoint);
    Console::WriteLine("Connected to {0}", sock->RemoteEndPoint);
}

// Define the public method that sends a request to the server
void HttpSocketManager::SendRequest(String^ path)
{
    // Create a GET request for the given path
    String^ request = "POST " + path + " HTTP/1.1\r\nHost: " + host + "\r\nConnection: close\r\n\r\n";
    array<Byte>^ requestBytes = Encoding::ASCII->GetBytes(request);

    // Send the request
    sock->Send(requestBytes);
    Console::WriteLine("Sent {0} bytes", requestBytes->Length);
}

// Define the public method that receives a response from the server
String^ HttpSocketManager::ReceiveResponse()
{
    // Receive the response
    array<Byte>^ responseBytes = gcnew array<Byte>(1024);
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

// Define the public method that closes the connection
void HttpSocketManager::Close()
{
    // Close the socket
    sock->Close();
    Console::WriteLine("Closed the connection");
}
