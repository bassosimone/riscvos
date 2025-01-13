//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//

#include <sys/syscall.h>

register_t __syscall3(register_t sysno, register_t arg0, register_t arg1,
                      register_t arg2) {
    register register_t a0 __asm__("a0") = arg0;
    register register_t a1 __asm__("a1") = arg1;
    register register_t a2 __asm__("a2") = arg2;
    register register_t a3 __asm__("a3") = sysno;

    __asm__ __volatile__("ecall"
                         : "=r"(a0)
                         : "r"(a0), "r"(a1), "r"(a2), "r"(a3)
                         : "memory");

    return a0;
}
