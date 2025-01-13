//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//

#include <kernel/console.h>
#include <kernel/panic.h>
#include <riscv32/proc.h>
#include <riscv32/trap.h>
#include <sys/errno.h>
#include <sys/syscall.h>

[[noreturn]] static void sys_exit(register_t arg2) {
    (void)arg2; // TODO(bassosimone): save the exit code
    current_proc->state = PROC_EXITED;
    yield();
}

static register_t sys_port_read(register_t arg0, register_t arg1,
                                register_t arg2) {
    switch (arg1) {
    case PORT_CONSOLE:
        (void)arg0, (void)arg2;
        return console_read();
    default:
        return -EINVAL;
    }
}

static register_t sys_port_write(register_t arg0, register_t arg1,
                                 register_t arg2) {
    switch (arg1) {
    case PORT_CONSOLE:
        (void)arg0;
        return console_write(arg2);
    default:
        return -EINVAL;
    }
}

void handle_syscall(struct trap_frame *f) {
    switch (f->a3) {
    case SYS_PUTCHAR:
        f->a0 = sys_port_write(0, PORT_CONSOLE, f->a0);
        return;

    case SYS_GETCHAR:
        f->a0 = sys_port_read(0, PORT_CONSOLE, 0);
        return;

    case SYS_EXIT:
        sys_exit(f->a2);
        panic("unreachable code");
        /* NOTREACHED */

    case SYS_PORT_READ:
        f->a0 = sys_port_read(f->a0, f->a1, f->a2);
        return;

    case SYS_PORT_WRITE:
        f->a0 = sys_port_write(f->a0, f->a1, f->a2);
        return;

    default:
        f->a0 = -ENOSYS;
        return;
    }
}
