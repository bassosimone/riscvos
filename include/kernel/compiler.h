//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//
// Taking advantage of compiler builtins.
//

#ifndef __KERNEL_COMPILER_H__
#define __KERNEL_COMPILER_H__

#define align_up(value, align) __builtin_align_up(value, align)

#define is_aligned(value, align) __builtin_is_aligned(value, align)

#endif // __KERNEL_COMPILER_H__
