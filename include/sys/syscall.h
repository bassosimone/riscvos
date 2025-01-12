//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//

#ifndef __SYS_SYSCALL_H__
#define __SYS_SYSCALL_H__

#include <sys/cdefs.h>

// Syscall IDs.
#define SYS_PUTCHAR 1
#define SYS_GETCHAR 2
#define SYS_EXIT 3

__BEGIN_DECLS

// Invoke a syscall with three arguments.
int __syscall3(int sysno, int arg0, int arg1, int arg2) __NOEXCEPT;

__END_DECLS

#endif // __SYS_SYSCALL_H__
