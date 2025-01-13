//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//
// Standard input/output definitions.
//

#ifndef __STDIO_H__
#define __STDIO_H__

#include <sys/cdefs.h>

// Indicates that the end of the file has been reached.
#define EOF (-1)

__BEGIN_DECLS

int getchar(void) __NOEXCEPT;

int printf(const char *fmt, ...) __NOEXCEPT;

int putchar(int c) __NOEXCEPT;

__END_DECLS

#endif // __STDIO_H__
