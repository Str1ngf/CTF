#pragma once
#include "base64.h"
HMODULE hUser32 = LoadLibrary(L"user32.dll");

typedef enum _PROCESSINFOCLASS
{
    ProcessBasicInformation = 0,
    ProcessQuotaLimit,
    ProcessIoCounters,
    ProcessVmCounters,
    ProcessTimes,
    ProcessBasePriority,
    ProcessraisePriority,
    ProcessDebugPort = 7,				// 0x7
    ProcessExceptionPort,
    ProcessAccessToken,
    ProcessLdtInformation,
    ProcessLdtSize,
    ProcessDefaultHardErrorMode,
    ProcessIoPortHandlers,
    ProcessPooledUsageAndLimits,
    ProcessWorkingSetWatch,
    ProcessUserModeIOPL,
    ProcessEnalbeAlignmentFaultFixup,
    ProcessPriorityClass,
    ProcessWx86Information,
    ProcessHandleCount,
    ProcessAffinityMask,
    ProcessPriorityBoost,
    MaxProcessInfoClass,
    ProcessWow64Inforamtion = 26,
    ProcessImageFileName = 27,
    ProcessDebugObjectHandle = 30,		// 0x1E
    ProcessDebugFlags = 31,             // 0x1F	
} PROCESSINFOCLASS, * PPROCESSINFOCLASS;


typedef NTSTATUS(WINAPI* PNtQUERYINFORMATIONPROCESS) (
	_In_       HANDLE ProcessHandle,
	_In_       PROCESSINFOCLASS ProcessInformationClass,
	_Out_      PVOID ProcessInformation,
	_In_       ULONG ProcessInformationLength,
	_Out_opt_  PULONG ReturnLength
	);

typedef DWORD(WINAPI* PFZWSETINFORMATIONTHREAD) (
	HANDLE		ThreadHandle,
	DWORD		ThreadInformationClass,
	PVOID		ThreadInformation,
	ULONG		ThreadInformationLength
	);


void NTAPI __stdcall tls_callback(PVOID, DWORD dwReason, PVOID Reserved)
{
	BOOL result = FALSE;
	DWORD Buffer;

	PNtQUERYINFORMATIONPROCESS pNtQueryInformationProcess;
	HMODULE h_ntdll = LoadLibraryA("ntdll.dll");
	pNtQueryInformationProcess = (PNtQUERYINFORMATIONPROCESS)GetProcAddress(h_ntdll, "NtQueryInformationProcess");
	pNtQueryInformationProcess(GetCurrentProcess(), ProcessDebugPort, &Buffer, 4, 0);
	if (Buffer == 0) {

	}
	else {
		MessageBoxA(NULL, "Detect", "", MB_OK);
		exit(EXIT_FAILURE);
	}
    return ;
}

void BlockKeyboard(int depth) {
	if (depth < 10) {
		// 재귀적으로 함수 호출
		BlockKeyboard(depth + 1);
	}
	else if (depth == 10) {
		__asm {
			mov al, al
			mov ah, ah
			mov dl, dl
			mov dh, dh
			mov cl, cl
			mov ch, ch
			mov ax, ax
			mov bl, bl
			mov bh, bh
			mov esi, esi
			mov ebx, ebx
			mov edi, edi
			mov edx, edx
			mov ecx, ecx
			mov eax, eax
			mov al, al
			mov ah, ah
			mov dl, dl
			mov dh, dh
			mov cl, cl
			mov ch, ch
			mov ax, ax
			mov bl, bl
			mov bh, bh
			mov esi, esi
			mov ebx, ebx
			mov edi, edi
			mov edx, edx
			mov ecx, ecx
			mov eax, eax
			mov al, al
			mov ah, ah
			mov dl, dl
			mov dh, dh
			mov cl, cl
			mov ch, ch
			mov ax, ax
			mov bl, bl
			mov bh, bh
			mov esi, esi
			mov ebx, ebx
			mov edi, edi
			mov edx, edx
			mov ecx, ecx
			mov eax, eax
			mov al, al
			mov ah, ah
			mov dl, dl
			mov dh, dh
			mov cl, cl
			mov ch, ch
			mov ax, ax
			mov bl, bl
			mov bh, bh
			mov esi, esi
			mov ebx, ebx
			mov edi, edi
			mov edx, edx
			mov ecx, ecx
			mov eax, eax
			mov al, al
			mov ah, ah
			mov dl, dl
			mov dh, dh
			mov cl, cl
			mov ch, ch
			mov ax, ax
			mov bl, bl
			mov bh, bh
			mov esi, esi
			mov ebx, ebx
			mov edi, edi
			mov edx, edx
			mov ecx, ecx
			mov eax, eax
		}
		__asm {
			mov ebx, Block
			push ebx
			xor ebx, ebx
			jnz Fake
			retn
			Fake :
			_emit 0xe8
		}
Block:
		BOOL(WINAPI * pBlockInput)(BOOL) = (BOOL(WINAPI*)(BOOL))GetProcAddress(hUser32, "BlockInput");
		pBlockInput(TRUE);
		__asm {
			mov ebx, Block2
			push ebx
			xor ebx, ebx
			jnz Fake2
			retn
			Fake2 :
			_emit 0xe8
		}
Block2:
		__asm {
			mov al, al
			mov ah, ah
			mov dl, dl
			mov dh, dh
			mov cl, cl
			mov ch, ch
			mov ax, ax
			mov bl, bl
			mov bh, bh
			mov esi, esi
			mov ebx, ebx
			mov edi, edi
			mov edx, edx
			mov ecx, ecx
			mov eax, eax
			mov al, al
			mov ah, ah
			mov dl, dl
			mov dh, dh
			mov cl, cl
			mov ch, ch
			mov ax, ax
			mov bl, bl
			mov bh, bh
			mov esi, esi
			mov ebx, ebx
			mov edi, edi
			mov edx, edx
			mov ecx, ecx
			mov eax, eax
			mov al, al
			mov ah, ah
			mov dl, dl
			mov dh, dh
			mov cl, cl
			mov ch, ch
			mov ax, ax
			mov bl, bl
			mov bh, bh
			mov esi, esi
			mov ebx, ebx
			mov edi, edi
			mov edx, edx
			mov ecx, ecx
			mov eax, eax
			mov al, al
			mov ah, ah
			mov dl, dl
			mov dh, dh
			mov cl, cl
			mov ch, ch
			mov ax, ax
			mov bl, bl
			mov bh, bh
			mov esi, esi
			mov ebx, ebx
			mov edi, edi
			mov edx, edx
			mov ecx, ecx
			mov eax, eax
			mov al, al
			mov ah, ah
			mov dl, dl
			mov dh, dh
			mov cl, cl
			mov ch, ch
			mov ax, ax
			mov bl, bl
			mov bh, bh
			mov esi, esi
			mov ebx, ebx
			mov edi, edi
			mov edx, edx
			mov ecx, ecx
			mov eax, eax
		}
	}
	FreeLibrary(hUser32);
}

void flag1() {
	__asm {
		mov ebx, RealL
		push ebx
		xor ebx, ebx
		jnz Fake_L
		retn
		Fake_L :
		_emit 0xe8
	}
RealL:
	if (!IsDebuggerPresent()) { //IsDebuggerPresent Fake
		exit(EXIT_FAILURE);
	}
	__asm {
		mov ebx, RealM
		push ebx
		xor ebx, ebx
		jnz Fake_M
		retn
		Fake_M :
		_emit 0xe8
	}
RealM:
	const char* encoded = "RkxBR3s0N0hfIXNfZkkxM18xMVNfSEAxcnJPcl8yeEBtcDEyXzJ9";
	unsigned char decoded[100];

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
	base64_decode(encoded, decoded);

	for (int i = 0; i < strlen(encoded) / 4 * 3; i++) {
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
		printf("%c", decoded[i]);
	}
	printf("\n");
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
    BlockKeyboard(1);
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
	return;
}

void rflag() {
	__asm {
		mov ebx, RealK
		push ebx
		xor ebx, ebx
		jnz Fake_K
		retn
		Fake_K :
		_emit 0xe8
	}
RealK:
	const char* encoded = "X1RoMXNfaXNfckVAMV9mMUBn";
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
	unsigned char decoded[100];

	base64_decode(encoded, decoded);

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
	for (int i = 0; i < strlen(encoded) / 4 * 3; i++) {
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
		printf("%c", decoded[i]);
	}
	printf("\n");
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
	return;
}

int DummyFunc1(int a, int b) {
	return a + b * a;
}


void Dettach_Process()
{
	//VMProtectBeginUltra("Dettach_Process");
	PFZWSETINFORMATIONTHREAD pfZwSetInformationThread;
	pfZwSetInformationThread(GetCurrentThread(), 0x11, 0, 0);
	//VMProtectEnd();
}