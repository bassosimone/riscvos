//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//

#ifndef __SYS_CDEFS_H__
#define __SYS_CDEFS_H__

#ifdef __cplusplus
#define __BEGIN_DECLS extern "C" {
#define __END_DECLS }
#define __NOEXCEPT noexcept
#else
#define __BEGIN_DECLS /* nothing */
#define __END_DECLS /* nothing */
#define __NOEXCEPT /* nothing */
#endif

#endif // __SYS_CDEFS_H__
