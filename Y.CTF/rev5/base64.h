#pragma once
static const char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

unsigned char base64_decode_char(char c) {
	if (c >= 'A' && c <= 'Z') return c - 'A';
	if (c >= 'a' && c <= 'z') return c - 'a' + 26;
	if (c >= '0' && c <= '9') return c - '0' + 52;
	if (c == '+') return 62;
	if (c == '/') return 63;
	return 0;
}

void base64_decode(const char* input, unsigned char* output) {
	int input_length = strlen(input);
	int output_length = 0;
	unsigned char char_array_4[4], char_array_3[3];

	for (int i = 0; i < input_length; i += 4) {
		for (int j = 0; j < 4; j++) {
			char_array_4[j] = base64_decode_char(input[i + j]);
		}
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

		char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
		char_array_3[1] = ((char_array_4[1] & 0x0F) << 4) + ((char_array_4[2] & 0x3C) >> 2);
		char_array_3[2] = ((char_array_4[2] & 0x03) << 6) + char_array_4[3];

		for (int j = 0; j < 3; j++) {
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
			output[output_length++] = char_array_3[j];
		}
	}
}