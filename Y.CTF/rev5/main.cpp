#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//#include "VMProtectSDK.h"
#include "trap.h"
#include "base64.h"
//#pragma comment(lib, "VMProtectSDK32.lib")

#ifdef _M_IX86
#pragma comment (linker, "/INCLUDE:__tls_used")
#else
#pragma comment (linker, "/INCLUDE:_tls_used")
#endif
EXTERN_C
#ifdef _M_X64
#pragma const_seg (".CRT$XLB")
const
#else
#pragma data_seg (".CRT$XLB")
#endif

//tls import
PIMAGE_TLS_CALLBACK p_thread_callback = tls_callback;
#pragma data_seg ()
#pragma const_seg ()
//end
char str[10];


int main() {
	printf("FLAG{u1m_M2ye55!1_t2H1S_1S_r3@1_f!AG_!}\n");
	str[0] = 'R';
	__asm {
		mov ebx, Real1
		push ebx
		xor ebx, ebx
		jnz Fake_1
		retn
		Fake_1:
		_emit 0xe8   
	}
Real1:
	__asm {
		mov ebx, Real10
		push ebx
		xor ebx, ebx
		jnz Fake_10
		retn
		Fake_10 :
		_emit 0xe8
	}
Real10:
	flag1();
	str[1] = 'H';
	__try 
	{
		__asm {
			mov ebx, Real2
			push ebx
			xor ebx, ebx
			jnz Fake_2
			retn
		Fake_2 :
		_emit 0xe8
		}
Real2:
		__asm {
			mov ebx, Real11
			push ebx
			xor ebx, ebx
			jnz Fake_11
			retn
			Fake_11 :
			_emit 0xe8
		}
Real11:
		__asm {
			mov ebx, Real12
			push ebx
			xor ebx, ebx
			jnz Fake_12
			retn
			Fake_12 :
			_emit 0xe8
		}
Real12:
		__asm {
			mov ebx, Real13
			push ebx
			xor ebx, ebx
			jnz Fake_13
			retn
			Fake_13 :
			_emit 0xe8
		}
Real13:
		int n = 10;
		int r = 5;
		DummyFunc1(n,r);
		str[2] = 'C';
		__asm {
			mov ebx, Real14
			push ebx
			xor ebx, ebx
			jnz Fake_14
			retn
			Fake_14 :
			_emit 0xe8
		}
	Real14:
		HMODULE hModule = GetModuleHandleA("Kernel32.dll");
		__asm {
			mov ebx, Real3
			push ebx
			xor ebx, ebx
			jnz Fake_3
			retn
			Fake_3 :
			_emit 0xe8
		}
Real3:
		int addr = (int)GetProcAddress(hModule, "WinExec");
		__asm {
			pushad
			push   ebp
			mov    ebp, esp
			push   ebx
			xor ebx, ebx
			jz LABEL1
			_emit 0xE8
			LABEL1:
			push   edi
			mov    ecx, edx
			add    ecx, eax
			add    edi,edi
			pop    edi
			dec    ebx
			push   0x1
			push   0x0
			call   eax
			pop    ebx
			mov    esp, ebp
			pop    ebp
			popad
			}
		n += r;
		n -= r;
		DummyFunc1(n, r);
		str[3] = 'N';
		__asm {
			mov ebx, Real4
			push ebx
			xor ebx, ebx
			jnz Fake_4
			retn
			Fake_4 :
			_emit 0xe8
		}
Real4:
		str[4] = 'P';
		int* ptr = NULL;
		*ptr = 12;  //NULL 포인터 접근으로 예외 발생
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		BOOL DebugCheck;
		__asm {
			mov ebx, Real5
			push ebx
			xor ebx, ebx
			jnz Fake_5
			retn
			Fake_5 :
			_emit 0xe8
		}
	Real5:
		__asm {
			mov ebx, Real15
			push ebx
			xor ebx, ebx
			jnz Fake_15
			retn
			Fake_15 :
			_emit 0xe8
		}
Real15:
		__asm {
			mov ebx, Real16
			push ebx
			xor ebx, ebx
			jnz Fake_16
			retn
			Fake_16 :
			_emit 0xe8
		}
Real16:
		__asm {
			mov ebx, Real17
			push ebx
			xor ebx, ebx
			jnz Fake_17
			retn
			Fake_17 :
			_emit 0xe8
		}
Real17:
		CheckRemoteDebuggerPresent(GetCurrentProcess(), &DebugCheck);
		str[5] = 'F';
		__asm {
			mov ebx, Real8
			push ebx
			xor ebx, ebx
			jnz Fake_8
			retn
			Fake_8 :
			_emit 0xe8
		}
Real8:
		if (DebugCheck)
			return 0;
	}
	Dettach_Process();
	str[5] = 'G';
	__asm {
		mov ebx, Real6
		push ebx
		xor ebx, ebx
		jnz Fake_6
		retn
		Fake_6 :
		_emit 0xe8
	}
Real6:
	LABEL4:
	printf("FLAG{th@15_1S_vEry_Angry_Examp1e_!}\n");
	str[6] = 'H';
	__asm {
		mov ebx, Real7
		push ebx
		xor ebx, ebx
		jnz Fake_7
		retn
		Fake_7 :
		_emit 0xe8
	}
Real7:
	__asm {
		mov ebx, Real9
		push ebx
		xor ebx, ebx
		jnz Fake_9
		retn
		Fake_9 :
		_emit 0xe8
	}
Real9:
	str[7] = 'I';

	for (int i = 0; i < 7; i++) {
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
		printf("%c", str[i]);
	}
	rflag();
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
	return 0;
}