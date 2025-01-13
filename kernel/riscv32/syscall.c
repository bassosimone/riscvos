//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//

#include <kernel/panic.h>
#include <riscv32/proc.h>
#include <riscv32/trap.h>
#include <sys/errno.h>
#include <sys/syscall.h>

#include <stdio.h>

static void sys_putchar(struct trap_frame *f) {
    if ((current_proc->capabilities & CAP_CONSOLE_READWRITE) == 0) {
        f->a0 = -EPERM;
        return;
    }
    putchar(f->a0);
}

static void sys_getchar(struct trap_frame *f) {
    if ((current_proc->capabilities & CAP_CONSOLE_READWRITE) == 0) {
        f->a0 = -EPERM;
        return;
    }
    while (1) {
        long ch = getchar();
        if (ch >= 0) {
            f->a0 = ch;
            return;
        }
        yield();
    }
}

static void sys_exit(struct trap_frame *f) {
    (void)f; // TODO(bassosimone): save the exit code
    printf("process %d exited\n", current_proc->pid);
    current_proc->state = PROC_EXITED;
    yield();
    panic("unreachable");
}

void handle_syscall(struct trap_frame *f) {
    switch (f->a3) {
    case SYS_PUTCHAR:
        sys_putchar(f);
        return;

    case SYS_GETCHAR:
        sys_getchar(f);
        return;

    case SYS_EXIT:
        sys_exit(f);
        return;

    default:
        f->a0 = -ENOSYS;
        return;
    }
}
