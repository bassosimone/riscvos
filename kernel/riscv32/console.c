//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//

#include <kernel/console.h>
#include <riscv32/sbi.h>
#include <riscv32/proc.h>
#include <sys/errno.h>
#include <sys/syscall.h>

#include <stdio.h>

int putchar(int ch) {
    sbi_call(ch, 0, 0, 0, 0, 0, 0, 1 /* Console Putchar */);
    return 0;
}

register_t console_write(register_t ch) {
    if ((current_proc->capabilities & CAP_CONSOLE_READWRITE) == 0) {
        return -EPERM;
    }
    return putchar(ch);
}

int getchar(void) {
    struct sbiret ret = sbi_call(0, 0, 0, 0, 0, 0, 0, 2 /* Console Getchar */);
    return ret.error;
}

register_t console_read(void) {
    if ((current_proc->capabilities & CAP_CONSOLE_READWRITE) == 0) {
        return -EPERM;
    }
    while (1) {
        register_t ch = getchar();
        if (ch >= 0) {
            return ch;
        }
        yield();
    }
}
