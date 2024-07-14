#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/unistd.h>
#include <linux/sched.h>
  
MODULE_LICENSE("Dual BSD/GPL");
 
#define SYS_CALL_TABLE_ADDRESS 0xffffffff99200300 // 确认该地址正确
#define NUM 400  // 系统调用号为400
int orig_cr0;  // 用来存储cr0寄存器原来的值
unsigned long *sys_call_table_my = 0;
static int(*anything_saved)(void);  // 定义一个函数指针，用来保存一个系统调用

static int clear_cr0(void) // 使cr0寄存器的第17位设置为0（内核空间可写）
{
    unsigned int cr0 = 0;
    unsigned int ret;
    asm volatile("movq %%cr0, %%rax":"=a"(cr0));
    ret = cr0;
    cr0 &= 0xfffffffffffeffff; // 将cr0变量值中的第17位清0
    asm volatile("movq %%rax, %%cr0"::"a"(cr0));
    return ret;
}

static void setback_cr0(int val) // 使cr0寄存器设置为内核不可写
{
    asm volatile("movq %%rax, %%cr0"::"a"(val));
}

asmlinkage long sys_mycall(void) // 定义自己的系统调用
{   
    printk(KERN_INFO "By: HashBuke - sys_mycall called\n");
    return 1;    
}

static int __init call_init(void)
{
    sys_call_table_my = (unsigned long*)(SYS_CALL_TABLE_ADDRESS);
    printk(KERN_INFO "HashBuke: Module loaded\n");
    printk(KERN_INFO "HashBuke: System call table address: %p\n", sys_call_table_my);

    anything_saved = (int(*)(void))(sys_call_table_my[NUM]);
    orig_cr0 = clear_cr0();
    sys_call_table_my[NUM] = (unsigned long)&sys_mycall;
    setback_cr0(orig_cr0);

    printk(KERN_INFO "HashBuke: System call %d replaced\n", NUM);
    return 0;
}

static void __exit call_exit(void)
{
    orig_cr0 = clear_cr0();
    sys_call_table_my[NUM] = (unsigned long)anything_saved;
    setback_cr0(orig_cr0);
    printk(KERN_INFO "HashBuke: Module unloaded\n");
}

module_init(call_init);
module_exit(call_exit);

