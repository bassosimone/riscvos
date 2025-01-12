//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//
// Standard definitions.
//

#ifndef __STDDEF_H__
#define __STDDEF_H__

#include <sys/types.h>

#define NULL ((void *)0)

#define offsetof(type, member) __builtin_offsetof(type, member)

#endif // __STDDEF_H__
