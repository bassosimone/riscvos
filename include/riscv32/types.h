//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//
// Type definitions for RISC-V 32-bit.
//

#ifndef __RISCV32_TYPES_H__
#define __RISCV32_TYPES_H__

// Standard integer types used by the kernel.
typedef unsigned char uint8_t;
typedef char int8_t;
typedef unsigned short uint16_t;
typedef short int16_t;
typedef unsigned int uint32_t;
typedef int int32_t;
typedef unsigned long long uint64_t;
typedef long long int64_t;
typedef uint32_t size_t;
typedef int32_t ssize_t;
typedef int32_t register_t;

#endif // __RISCV32_TYPES_H__
