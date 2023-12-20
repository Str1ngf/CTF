#include <stdio.h>
#include <Windows.h>
#include <string.h>

void D9F8D9FD823HDFGH(); //dec flag


int main() {
    HANDLE hFile;
    DWORD dwBytesRead;
    char buffer[100] = { 0 };

    hFile = CreateFile("example", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        printf("keyfile invalid!\n");
        return 1;
    }

    if (!ReadFile(hFile, buffer, sizeof(buffer), &dwBytesRead, NULL)) {
        CloseHandle(hFile);
        return 1;
    }

    if (buffer[0] == 'c' && buffer[1] == '1' && buffer[2] == 'r' && buffer[3] == '2' && buffer[4] == '3'
        && buffer[5] == 'c' && buffer[6] == '_' && buffer[7] == 'k' && buffer[8] == 'm' && buffer[9] == '2')
    {
        D9F8D9FD823HDFGH();
        printf("\n");
    }
    else
    {
        printf("key Failed!\n");
    }
    system("PAUSE");

    CloseHandle(hFile);

    return 0;
}


void D9F8D9FD823HDFGH() // dec flag
{
    const char* flag = "CIDB~wZ6s@wV6h@Z6d0|$$x";
    int i;
    for (i = 0; i < strlen(flag); i++) {
        printf("%c", flag[i] ^ 5);
    }
}

