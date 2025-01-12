//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//
// Kernel memory layout defined by kernel.ld.
//

#ifndef __RISCV32_KERNEL_LAYOUT_H__
#define __RISCV32_KERNEL_LAYOUT_H__

// Start of kernel code
extern char __kernel_base[];

// Start of BSS section
extern char __bss[];

// End of BSS section
extern char __bss_end[];

// Top of kernel stack
extern char __stack_top[];

// Start of free memory
extern char __free_ram[];

// End of free memory
extern char __free_ram_end[];

#endif // __RISCV32_KERNEL_LAYOUT_H__
