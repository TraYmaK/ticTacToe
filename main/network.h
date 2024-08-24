#ifndef NETWORK_H
#define NETWORK_H

#include <winsock2.h>
#include <iostream>

class NetworkGame {
public:
    NetworkGame();
    ~NetworkGame();

    bool InitializeServer();
    bool InitializeClient(const std::string& ipAddress);

    bool SendData(const char* data, int size);
    bool ReceiveData(char* buffer, int size);

private:
    SOCKET serverSocket;
    SOCKET clientSocket;
    WSADATA wsaData;
};

#endif