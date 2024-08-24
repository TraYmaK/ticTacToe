#include "network.h"
#include <Ws2tcpip.h>  // для inet_pton если вы решите использовать его
#include <iostream>
#define _WINSOCK_DEPRECATED_NO_WARNINGS

NetworkGame::NetworkGame() : serverSocket(INVALID_SOCKET), clientSocket(INVALID_SOCKET) {
    WSAStartup(MAKEWORD(2, 2), &wsaData);
}

NetworkGame::~NetworkGame() {
    if (clientSocket != INVALID_SOCKET) closesocket(clientSocket);
    if (serverSocket != INVALID_SOCKET) closesocket(serverSocket);
    WSACleanup();
}

bool NetworkGame::InitializeServer() {
    sockaddr_in serverAddr;
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) return false;

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(54000);

    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) return false;
    listen(serverSocket, SOMAXCONN);

    sockaddr_in clientAddr;
    int clientSize = sizeof(clientAddr);
    clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientSize);
    return clientSocket != INVALID_SOCKET;
}

bool NetworkGame::InitializeClient(const std::string& ipAddress) {
    sockaddr_in serverAddr;
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) return false;

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(54000);
    inet_pton(AF_INET, ipAddress.c_str(), &serverAddr.sin_addr);

    return connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) != SOCKET_ERROR;
}

bool NetworkGame::SendData(const char* data, int size) {
    return send(clientSocket, data, size, 0) != SOCKET_ERROR;
}

bool NetworkGame::ReceiveData(char* buffer, int size) {
    return recv(clientSocket, buffer, size, 0) != SOCKET_ERROR;
}
