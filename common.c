//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//

#include "common.h"

// <string.h> - string manipulation functions

void *memcpy(void *dst, const void *src, size_t n) {
    uint8_t *d = (uint8_t *)dst;
    const uint8_t *s = (const uint8_t *)src;
    while (n--) {
        *d++ = *s++;
    }
    return dst;
}

void *memset(void *buf, int c, size_t n) {
    uint8_t *p = (uint8_t *)buf;
    while (n--) {
        *p++ = (char)c;
    }
    return buf;
}

char *strcpy(char *dst, const char *src) {
    char *d = dst;
    while (*src) {
        *d++ = *src++;
    }
    *d = '\0';
    return dst;
}

int strcmp(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        if (*s1 != *s2) {
            break;
        }
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

// <stdio.h> - standard I/O functions

// Forward declaration: this is actually implemented either by
// the kernel or by user space depending on what we're building.
void putchar(char ch);

static int printf_string(const char *s) {
    while (*s) {
        putchar(*s);
        s++;
    }
    // TODO(bassosimone): return the number of characters printed
    return 0;
}

static int printf_decimal(int value) {
    if (value < 0) {
        putchar('-');
        value = -value;
    }

    int divisor = 1;
    while (value / divisor > 9) {
        divisor *= 10;
    }

    while (divisor > 0) {
        putchar('0' + value / divisor);
        value %= divisor;
        divisor /= 10;
    }
    // TODO(bassosimone): return the number of characters printed
    return 0;
}

static int printf_hex(int value) {
    for (int i = 7; i >= 0; i--) {
        int nibble = (value >> (i * 4)) & 0xf;
        putchar("0123456789abcdef"[nibble]);
    }
    // TODO(bassosimone): return the number of characters printed
    return 0;
}

int printf(const char *fmt, ...) {
    va_list vargs;
    va_start(vargs, fmt);

    for (; *fmt; fmt++) {
        // Handle the case of a normal character
        if (*fmt != '%') {
            putchar(*fmt);
            continue;
        }

        // Skip '%'
        fmt++;

        // Read the next character
        switch (*fmt) {

        // '%' at the end of the format string
        case '\0':
            putchar('%');
            goto end;

        // Print '%'
        case '%':
            putchar('%');
            break;

        // Print a NULL-terminated string.
        case 's':
            (void)printf_string(va_arg(vargs, const char *));
            break;

        // Print an integer in decimal.
        case 'd':
            (void)printf_decimal(va_arg(vargs, int));
            break;

        // Print an integer in hexadecimal.
        case 'x':
            (void)printf_hex(va_arg(vargs, int));
            break;
        }
    }

end:
    va_end(vargs);
    // TODO(bassosimone): return the number of characters printed
    return 0;
}
