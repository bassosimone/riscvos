//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//

#ifndef __STDIO_H__
#define __STDIO_H__

#include <sys/cdefs.h>

__BEGIN_DECLS

int getchar(void) __NOEXCEPT;

int printf(const char *fmt, ...) __NOEXCEPT;

int putchar(int c) __NOEXCEPT;

__END_DECLS

#endif // __STDIO_H__
