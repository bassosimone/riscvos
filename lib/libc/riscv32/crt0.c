//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//

extern char __stack_top[];

__attribute__((section(".text.start"))) __attribute__((naked)) void
start(void) {
    __asm__ __volatile__(
        "mv sp, %[stack_top] \n"
        "call main           \n"
        "call exit           \n" ::[stack_top] "r"(__stack_top));
}
