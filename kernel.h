#ifndef __KERNEL_H__
#define __KERNEL_H__

#include "common.h"

struct sbiret {
    long error;
    long value;
};

#define panic(fmt, ...)                                                        \
    do {                                                                       \
        printk("panic: %s:%d: " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__);  \
        while (1) {}                                                           \
    } while (0)

#endif // __KERNEL_H__
