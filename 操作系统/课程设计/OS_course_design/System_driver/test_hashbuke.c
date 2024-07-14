#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE "/dev/hashbuke"

// 将数字转换为二进制字符串的函数
void to_binary(long n, char *binary_str) {
    int i;
    for (i = 0; i < 64; i++) {
        binary_str[63 - i] = (n & 1) ? '1' : '0';
        n >>= 1;
    }
    binary_str[64] = '\0';
}

int main() {
    int fd;
    char buffer[256];
    ssize_t ret;
    long number;

    fd = open(DEVICE, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return 1;
    }

    // Read from the device
    ret = read(fd, buffer, sizeof(buffer));
    if (ret < 0) {
        perror("Failed to read the message from the device");
        return 1;
    }
    printf("Current time in seconds since 1970-01-01: %s", buffer);

    // Write to the device
    printf("Enter a number: ");
    scanf("%ld", &number);
    snprintf(buffer, sizeof(buffer), "%ld", number);
    ret = write(fd, buffer, strlen(buffer));
    if (ret < 0) {
        perror("Failed to write the message to the device");
        return 1;
    }

    // 显示输入数字的二进制表示
    char binary_str[65];
    to_binary(number, binary_str);
    printf("Binary representation: %s\n", binary_str);

    close(fd);
    return 0;
}

