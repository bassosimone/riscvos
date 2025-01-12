//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//

#ifndef __COMMON_H__
#define __COMMON_H__

// <asm/types.h> - architecture specific types
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef uint32_t size_t;

#ifdef __kernel__
typedef uint32_t paddr_t;
typedef uint32_t vaddr_t;
#endif // __kernel__

// <stdbool.h> - boolean type and values
#ifndef __cplusplus
typedef int bool;
#define true 1
#define false 0
#endif // __cplusplus

// <stddef.h> - NULL and offsetof
#define NULL ((void *)0)
#define offsetof(type, member) __builtin_offsetof(type, member)

// <kernel/compiler.h> - compiler specific code
#define align_up(value, align) __builtin_align_up(value, align)
#define is_aligned(value, align) __builtin_is_aligned(value, align)

// <stdarg.h> - variable arguments functions
#define va_list __builtin_va_list
#define va_start __builtin_va_start
#define va_end __builtin_va_end
#define va_arg __builtin_va_arg

// <string.h> - string manipulation functions
void *memset(void *buf, int c, size_t n);
void *memcpy(void *dst, const void *src, size_t n);
[[deprecated]] char *strcpy(char *dst, const char *src);
int strcmp(const char *s1, const char *s2);

// <stdio.h> - standard I/O functions
int printf(const char *fmt, ...);
int putchar(int c);

// <asm/page.h> - paging specific code
#define PAGE_SIZE 4096

// <sys/syscall.h> - system call numbers
#define SYS_PUTCHAR 1
#define SYS_GETCHAR 2
#define SYS_EXIT 3

#endif // __COMMON_H__
