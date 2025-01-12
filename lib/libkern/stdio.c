//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//

#include <stdarg.h>
#include <stdio.h>

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
