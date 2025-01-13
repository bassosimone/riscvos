//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//

#ifndef __SYS_SYSCALL_H__
#define __SYS_SYSCALL_H__

#include <sys/cdefs.h>

// Allows a process to read/write the console.
#define CAP_CONSOLE_READWRITE (1 << 0)

// Writes the given character to the console.
//
// Requires CAP_CONSOLE_READWRITE.
#define SYS_PUTCHAR 1

// Reads a character from the console.
//
// Requires CAP_CONSOLE_READWRITE.
#define SYS_GETCHAR 2

// Exits the current process.
#define SYS_EXIT 3

// Forward declare the trap frame structure.
struct trap_frame;

__BEGIN_DECLS

// Invoke a syscall with three arguments.
int __syscall3(int sysno, int arg0, int arg1, int arg2) __NOEXCEPT;

// Handles a given system call inside the kernel.
void handle_syscall(struct trap_frame *f) __NOEXCEPT;

__END_DECLS

#endif // __SYS_SYSCALL_H__
