//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//
// Console API.
//

#ifndef __KERNEL_CONSOLE_H__
#define __KERNEL_CONSOLE_H__

#include <sys/cdefs.h>
#include <sys/types.h>

__BEGIN_DECLS

register_t console_write(register_t ch) __NOEXCEPT;

register_t console_read(void) __NOEXCEPT;

__END_DECLS

#endif // __KERNEL_CONSOLE_H__
