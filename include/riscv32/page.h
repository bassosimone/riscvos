//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//
// Page table management for RISC-V 32-bit.
//

#ifndef __RISCV32_PAGE_H__
#define __RISCV32_PAGE_H__

// Size in bytes of a page.
#define PAGE_SIZE 4096

// Supervisor Address Translation and Protection (SATP) register.
//
// SV32 is the 32-bit virtual addressing mode.
#define SATP_SV32 (1u << 31)

// "Valid" bit (entry is enabled)
#define PAGE_V (1 << 0)

// Readable
#define PAGE_R (1 << 1)

// Writable
#define PAGE_W (1 << 2)

// Executable
#define PAGE_X (1 << 3)

// User (accessible in user mode)
#define PAGE_U (1 << 4)

#endif // __RISCV32_PAGE_H__
