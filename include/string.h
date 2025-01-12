//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//

#ifndef __STRING_H__
#define __STRING_H__

#include <sys/cdefs.h>
#include <sys/types.h>

__BEGIN_DECLS

void *memset(void *buf, int c, size_t n) __NOEXCEPT;

void *memcpy(void *dst, const void *src, size_t n) __NOEXCEPT;

[[deprecated]] char *strcpy(char *dst, const char *src) __NOEXCEPT;

int strcmp(const char *s1, const char *s2) __NOEXCEPT;

__END_DECLS

#endif // __STRING_H__
