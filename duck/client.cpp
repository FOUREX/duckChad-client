#include "client.h"

SOCKET Connection;
std::string clientLastError;

int runClient()
{
    WSADATA wsaData;
    int iResult;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        clientLastError = "Error, lol. WSA startup err.";
        return 1;
    }

    SOCKADDR_IN addr;
    addr.sin_addr.S_un.S_addr = inet_addr(ADDR);
    addr.sin_port = htons(PORT);
    addr.sin_family = AF_INET;

    Connection = socket(AF_INET, SOCK_STREAM, NULL);
    iResult = connect(Connection, (SOCKADDR*)&addr, sizeof(addr));
    if (iResult != 0) {
        clientLastError = "Error, lol. Connect err.";
        return 1;
    }

    return 0;
}
