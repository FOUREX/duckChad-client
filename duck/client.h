#pragma once

#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "Ws2_32.lib")
#pragma warning(disable: 4996)

#define ADDR "127.0.0.1"
#define PORT 25565

extern SOCKET Connection;
extern std::string clientLastError;

int runClient();
