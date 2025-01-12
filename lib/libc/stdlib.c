//
// SPDX-License-Identifier: MIT
//
// Adapted from: https://github.com/nuta/operating-system-in-1000-lines
//

#include <sys/syscall.h>
#include <stdlib.h>

[[noreturn]] void exit(int exitcode) {
    (void)exitcode;
    __syscall3(SYS_EXIT, 0, 0, 0);
    for (;;); // Just in case!
}
