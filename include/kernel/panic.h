//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//

#ifndef __KERNEL_PANIC_H__
#define __KERNEL_PANIC_H__

#include <stdio.h> // IWYU pragma: keep

// Aborts the kernel execution with a console message.
#define panic(fmt, ...)                                                        \
    do {                                                                       \
        printf("panic: %s:%d: " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__);  \
        while (1) {                                                            \
            ;                                                                  \
        }                                                                      \
    } while (0)

#endif // __KERNEL_PANIC_H__
