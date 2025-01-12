//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//
// Support for invoking functions with variadic arguments.
//

#ifndef __STDARG_H__
#define __STDARG_H__

#define va_list __builtin_va_list
#define va_start __builtin_va_start
#define va_end __builtin_va_end
#define va_arg __builtin_va_arg

#endif // __STDARG_H__
