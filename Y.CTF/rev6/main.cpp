#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string>
#include "File.h"

int main() {
    DWORD dwBytesRead;
    char buffer[100] = { 0 };

    HMODULE hKernel32 = LoadLibrary(L"kernel32.dll");
    if (hKernel32 == NULL) {
        return 1;
    }

    __asm {
        mov ebx, RealG
        push ebx
        xor ebx, ebx
        jnz Fake_G
        retn
        Fake_G :
        _emit 0xe8
    }
RealG:

    HANDLE(WINAPI * createFileA)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE) =
        (HANDLE(WINAPI*)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE))GetProcAddress(hKernel32, "CreateFileA");

    __asm {
        mov ebx, RealH
        push ebx
        xor ebx, ebx
        jnz Fake_H
        retn
        Fake_H :
        _emit 0xe8
    }
RealH:

    if (createFileA == NULL) {
        FreeLibrary(hKernel32);
        return 1;
    }

    __asm {
        mov ebx, RealI
        push ebx
        xor ebx, ebx
        jnz Fake_I
        retn
        Fake_I :
        _emit 0xe8
    }
RealI:

    BOOL(WINAPI * readFile)(HANDLE, LPVOID, DWORD, LPDWORD, LPOVERLAPPED) =
        (BOOL(WINAPI*)(HANDLE, LPVOID, DWORD, LPDWORD, LPOVERLAPPED))GetProcAddress(hKernel32, "ReadFile");

    __asm {
        mov ebx, RealJ
        push ebx
        xor ebx, ebx
        jnz Fake_J
        retn
        Fake_J :
        _emit 0xe8
    }
RealJ:
    if (readFile == NULL) {
        FreeLibrary(hKernel32);
        return 1;
    }

    __asm {
        mov ebx, RealA
        push ebx
        xor ebx, ebx
        jnz Fake_A
        retn
        Fake_A :
        _emit 0xe8
    }
RealA:
    HANDLE hFile = createFileA("l1ceN5e34FajSD4Sd", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    __asm {
        mov ebx, RealB
        push ebx
        xor ebx, ebx
        jnz Fake_B
        retn
        Fake_B :
        _emit 0xe8
    }
RealB:
    if (hFile == INVALID_HANDLE_VALUE) {
        return 0;
    }

    if (!readFile(hFile, buffer, sizeof(buffer), &dwBytesRead, NULL)) {
        CloseHandle(hFile);
        return 0;
    }

    __asm {
        mov ebx, RealC
        push ebx
        xor ebx, ebx
        jnz Fake_C
        retn
        Fake_C :
        _emit 0xe8
    }
RealC:
    if (buffer[5] == 'c' && buffer[9] == '2' && buffer[6] == '_' && buffer[0] == 'c' && buffer[8] == 'm' && buffer[7] == 'k')
    {
        __asm {
            mov ebx, RealD
            push ebx
            xor ebx, ebx
            jnz Fake_D
            retn
            Fake_D :
            _emit 0xe8
        }
    RealD:
        decode_image("image1.png", "image_1.png", 0x55);
        __asm {
            mov ebx, RealE
            push ebx
            xor ebx, ebx
            jnz Fake_E
            retn
            Fake_E :
            _emit 0xe8
        }
    RealE:
        printf("Try decoding image2,3 directly. It is the same logic as decoding image1.\n");
        __asm {
            mov ebx, RealF
            push ebx
            xor ebx, ebx
            jnz Fake_F
            retn
            Fake_F :
            _emit 0xe8
        }
    RealF:
        printf("\n");
    }
    CloseHandle(hFile);
    return 0;
}