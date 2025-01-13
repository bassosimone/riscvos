//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//
// Machine-independent process management.
//

#ifndef __KERNEL_PROC_H__
#define __KERNEL_PROC_H__

#include <asm/proc.h>

// Allows a process to read/write the console.
#define CAP_CONSOLE_READWRITE (1 << 0)

#endif // __KERNEL_PROC_H__
