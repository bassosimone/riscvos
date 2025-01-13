#!/bin/bash
set -euxo pipefail

# QEMU file path
QEMU=qemu-system-riscv32

CC=/opt/homebrew/opt/llvm/bin/clang
CFLAGS="-std=c17 -O2 -g3 -Wall -Wextra --target=riscv32 -ffreestanding -nostdlib -I include"

OBJCOPY=/opt/homebrew/opt/llvm/bin/llvm-objcopy

# Build the shell (application)
$CC $CFLAGS -Wl,-Tlib/libc/riscv32/user.ld -Wl,-Map=shell.map -o shell.elf bin/shell/shell.c lib/libkern/stdio.c lib/libkern/string.c lib/libc/riscv32/syscall.c lib/libc/riscv32/crt0.c lib/libc/stdio.c lib/libc/stdlib.c
$OBJCOPY --set-section-flags .bss=alloc,contents -O binary shell.elf shell.bin
$OBJCOPY -Ibinary -Oelf32-littleriscv shell.bin shell.bin.o

# Build the kernel
$CC $CFLAGS -Wl,-Tkernel/riscv32/kernel.ld -Wl,-Map=kernel.map -o kernel.elf lib/libkern/stdio.c lib/libkern/string.c kernel/riscv32/console.c kernel/riscv32/main.c kernel/riscv32/mm.c kernel/riscv32/proc.c kernel/riscv32/sbi.c kernel/riscv32/syscall.c kernel/riscv32/trap.c shell.bin.o

# Start QEMU
$QEMU -machine virt -bios default -nographic -serial mon:stdio --no-reboot -kernel kernel.elf
