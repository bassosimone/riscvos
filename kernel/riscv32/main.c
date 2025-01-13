//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//
// Kernel entry point.
//

#include <kernel/panic.h>
#include <riscv32/kernel_layout.h>
#include <riscv32/proc.h>
#include <riscv32/trap.h>
#include <sys/syscall.h>

#include <string.h>
#include <stddef.h>

extern char _binary_shell_bin_start[], _binary_shell_bin_size[];

void __kernel_main(void) {
    memset(__bss, 0, (size_t)__bss_end - (size_t)__bss);
    WRITE_CSR(stvec, (uint32_t)kernel_entry);

    idle_proc = create_process(NULL, 0);
    idle_proc->pid = -1; // idle
    current_proc = idle_proc;

    struct process *shproc = create_process(_binary_shell_bin_start, (size_t)_binary_shell_bin_size);
    shproc->capabilities |= CAP_CONSOLE_READWRITE;
    yield();
    panic("switched to idle process");
}

__attribute__((section(".text.boot"))) __attribute__((naked)) void boot(void) {
    __asm__ __volatile__(
        "mv sp, %[stack_top]\n" // Set the stack pointer
        "j __kernel_main\n"     // Jump to the kernel main function
        :
        : [stack_top] "r"(
            __stack_top) // Pass the stack top address as %[stack_top]
    );
}
