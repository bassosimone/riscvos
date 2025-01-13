//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//
// Trap handling for RISC-V 32-bit.
//

#ifndef __RISCV32_TRAP_H__
#define __RISCV32_TRAP_H__

#include <sys/cdefs.h>
#include <sys/types.h>

// Stack frame containing the program state saved by
// the trap handler when handling a trap.
struct trap_frame {
    uint32_t ra;
    uint32_t gp;
    uint32_t tp;
    uint32_t t0;
    uint32_t t1;
    uint32_t t2;
    uint32_t t3;
    uint32_t t4;
    uint32_t t5;
    uint32_t t6;
    uint32_t a0;
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t a4;
    uint32_t a5;
    uint32_t a6;
    uint32_t a7;
    uint32_t s0;
    uint32_t s1;
    uint32_t s2;
    uint32_t s3;
    uint32_t s4;
    uint32_t s5;
    uint32_t s6;
    uint32_t s7;
    uint32_t s8;
    uint32_t s9;
    uint32_t s10;
    uint32_t s11;
    uint32_t sp;
} __attribute__((packed));

// Reads a specific Control and Status Register (CSR).
#define READ_CSR(reg)                                                          \
    ({                                                                         \
        unsigned long __tmp;                                                   \
        __asm__ __volatile__("csrr %0, " #reg : "=r"(__tmp));                  \
        __tmp;                                                                 \
    })

// Writes a specific Control and Status Register (CSR).
#define WRITE_CSR(reg, value)                                                  \
    do {                                                                       \
        uint32_t __tmp = (value);                                              \
        __asm__ __volatile__("csrw " #reg ", %0" ::"r"(__tmp));                \
    } while (0)

// Value written to `scause` CSR in case of `ECALL`.
#define SCAUSE_ECALL 8

__BEGIN_DECLS

// Invoked to handle traps.
__attribute__((naked)) __attribute__((aligned(4))) void kernel_entry(void);

__END_DECLS

#endif // __RISCV32_TRAP_H__
