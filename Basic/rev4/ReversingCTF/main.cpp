#include <stdio.h>
#include <windows.h>

int main()
{
	int a;
	BlockInput(TRUE);
	printf("Input: ");
	scanf("%d", &a);
	return 0;
}