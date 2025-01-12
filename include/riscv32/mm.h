//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//
// Memory management functions for RISC-V 32-bit.
//

#ifndef __RISCV32_MM_H__
#define __RISCV32_MM_H__

#include <asm/types.h>
#include <sys/cdefs.h>

// Physical and virtual addresses are 32-bit wide.
typedef uint32_t paddr_t;
typedef uint32_t vaddr_t;

__BEGIN_DECLS

// Allocates the given number of pages and returns
// the physical address of the first page.
paddr_t alloc_pages(uint32_t n) __NOEXCEPT;

// Maps a virtual address to a physical address in the
// given page table with the given flags.
void map_page(uint32_t *table1, uint32_t vaddr, paddr_t paddr,
              uint32_t flags) __NOEXCEPT;

__END_DECLS

#endif // __RISCV32_MM_H__
