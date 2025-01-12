#ifndef __USER_H__
#define __USER_H__

[[noreturn]] void exit(void);
int getchar(void);
int syscall(int sysno, int arg0, int arg1, int arg2);

#endif // __USER_H__
