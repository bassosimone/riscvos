//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//

#ifndef __SYS_SYSCALL_H__
#define __SYS_SYSCALL_H__

#include <sys/cdefs.h>
#include <sys/types.h>

// Allows a process to read/write the console.
#define CAP_CONSOLE_READWRITE (1 << 0)

// Writes the given character to the console.
//
// This syscall is an alias for SYS_PORT_WRITE with PORT_CONSOLE.
#define SYS_PUTCHAR 1

// Reads a character from the console.
//
// This syscall is an alias for SYS_PORT_READ with PORT_CONSOLE.
#define SYS_GETCHAR 2

// Exits the current process.
#define SYS_EXIT 3

// Reads from a well-known I/O port.
#define SYS_PORT_READ 4

// Writes to a well-known I/O port.
#define SYS_PORT_WRITE 5

// Well-known I/O port for the serial console.
#define PORT_CONSOLE 1

// Forward declare the trap frame structure.
struct trap_frame;

__BEGIN_DECLS

// Invoke a syscall with three register-size arguments.
register_t __syscall3(register_t sysno, register_t arg0, register_t arg1,
                      register_t arg2) __NOEXCEPT;

// Handles a given system call inside the kernel.
void handle_syscall(struct trap_frame *f) __NOEXCEPT;

__END_DECLS

#endif // __SYS_SYSCALL_H__
