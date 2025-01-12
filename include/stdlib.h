//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//

#ifndef __STDLIB_H__
#define __STDLIB_H__

#include <sys/cdefs.h>

__BEGIN_DECLS

[[noreturn]] void exit(int exitcode) __NOEXCEPT;

__END_DECLS

#endif // __STDLIB_H__
