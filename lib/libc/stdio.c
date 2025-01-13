//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//

#include <sys/syscall.h>

#include <stdio.h>

int putchar(int c) {
    register_t retval = __syscall3(SYS_PORT_WRITE, 0, PORT_CONSOLE, c);
    if (retval < 0) {
        // TODO(bassosimone): how do we deal with errno?
        return EOF;
    }
    return c;
}

int getchar(void) {
    register_t retval = __syscall3(SYS_PORT_WRITE, 0, PORT_CONSOLE, 0);
    if (retval < 0) {
        // TODO(bassosimone): how do we deal with errno?
        return EOF;
    }
    return retval;
}
