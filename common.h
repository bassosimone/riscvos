#ifndef __COMMON_H__
#define __COMMON_H__

#define va_list  __builtin_va_list
#define va_start __builtin_va_start
#define va_end   __builtin_va_end
#define va_arg   __builtin_va_arg

void printk(const char *fmt, ...);

#endif // __COMMON_H__
