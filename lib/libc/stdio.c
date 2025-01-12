//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//

#include <sys/syscall.h>

int putchar(int c) {
    __syscall3(SYS_PUTCHAR, c, 0, 0);
    return 0;
}

int getchar(void) {
    return __syscall3(SYS_GETCHAR, 0, 0, 0);
}
