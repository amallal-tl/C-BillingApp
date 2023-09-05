#pragma once

// Include the necessary namespaces
using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;

// Define a class that is singleton and manages the HTTP socket connection
ref class HttpSocketManager
{
private:
    // Declare a static instance of the class
    HttpSocketManager^ instance;

    // Declare a socket object
    Socket^ sock;

    // Declare a host name and an IP address
    String^ host;
    int port;
    IPAddress^ address;

    // Declare an endpoint with the IP address and port 80
    IPEndPoint^ endPoint;

public:
    // Declare a private constructor that initializes the socket and the endpoint
    HttpSocketManager(String^ host, int port);

    // Declare a public method that connects to the server
    void Connect();

    // Declare a public method that sends a request to the server
    void SendRequest(String^ httpMethod, String^ path, String^ body);

    // Declare a public method that receives a response from the server
    String^ ReceiveResponse();

    String^ HttpSocketManager::parseResponse(String^ response);

    //array<Byte>^ HttpSocketManager::Combine(array<Byte>^ a, array<Byte>^ b);

    // Declare a public method that closes the connection
    void Close();
};
