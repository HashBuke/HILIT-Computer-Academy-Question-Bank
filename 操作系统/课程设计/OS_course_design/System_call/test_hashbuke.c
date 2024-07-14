// test_hashbuke.c
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

#define __NR_hashbuke 400  // 使用您的实际系统调用号

int main()
{
    long res = syscall(__NR_hashbuke);
    if (res == 0)
    {
        printf("系统调用失败！\n");
    }
    else
    {
        printf("系统调用成功！\n");
    }
    return 0;
}

