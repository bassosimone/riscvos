//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//
// SBI means Supervisor Binary Interface. It is a standard
// interface between the kernel and the firmware.
//

#ifndef __RISCV32_SBI_H__
#define __RISCV32_SBI_H__

#include <sys/cdefs.h>

// Value returned by SBI `ECALL` calls.
struct sbiret {
    long error;
    long value;
};

__BEGIN_DECLS

// Calls the Supervisor Binary Interface (SBI) using `ECALL`.
struct sbiret sbi_call(long arg0, long arg1, long arg2, long arg3, long arg4,
                       long arg5, long fid, long eid) __NOEXCEPT;

__END_DECLS

#endif // __RISCV32_SBI_H__
