//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//
// Process control block (PCB) for RISC-V 32-bit architecture.
//

#ifndef __RISCV32_PROC_H__
#define __RISCV32_PROC_H__

#include <riscv32/mm.h>
#include <sys/cdefs.h>

// Maximum number of processes
#define PROCS_MAX 8

// Unused process control structure
#define PROC_UNUSED 0

// Runnable process
#define PROC_RUNNABLE 1

// Terminated process
#define PROC_EXITED 2

// Process control block (PCB).
struct process {
    // Process ID.
    int pid;

    // Process state: PROC_UNUSED, PROC_RUNNABLE, ...
    int state;

    // Stack pointer
    vaddr_t sp;

    // Page table first level
    uint32_t *page_table;

    // Kernel stack
    uint8_t stack[8192];
};

// The base virtual address of an application image. This needs
// to match the starting address defined in `user.ld`.
#define USER_BASE 0x1000000

// Supervisor Previous Interrupt Enable (SPIE) is a bit in the
// `sstatus` CSR that enables interrupts when the RISC-V processor
// is running in user mode.
#define SSTATUS_SPIE (1 << 5)

// Currently running proc.
extern struct process *current_proc;

// Idle proc.
extern struct process *idle_proc;

__BEGIN_DECLS

// Creates a new PCB for a process.
struct process *create_process(const void *image, size_t image_size) __NOEXCEPT;

// Yields the CPU to the next runnable process.
void yield(void) __NOEXCEPT;

__END_DECLS

#endif // __RISCV32_PROC_H__
