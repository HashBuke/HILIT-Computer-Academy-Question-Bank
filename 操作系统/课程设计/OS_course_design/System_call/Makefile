# Makefile for compiling the hashbuke_syscall kernel module

# 设置模块名
obj-m += hashbuke_syscall.o

# 默认目标，编译模块
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

# 清理目标，删除编译生成的文件
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

