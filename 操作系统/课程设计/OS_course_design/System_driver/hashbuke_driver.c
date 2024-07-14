#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/time.h>
#include <linux/device.h>  // 添加这个头文件
#include <linux/kdev_t.h>  // 添加这个头文件

#define DEVICE_NAME "hashbuke"
#define CLASS_NAME "hashbuke_class"

static int major_number;
static struct class* hashbuke_class = NULL;
static struct device* hashbuke_device = NULL;

static ssize_t hashbuke_read(struct file *filep, char *buffer, size_t len, loff_t *offset);
static ssize_t hashbuke_write(struct file *filep, const char *buffer, size_t len, loff_t *offset);
static int hashbuke_open(struct inode *inodep, struct file *filep);
static int hashbuke_release(struct inode *inodep, struct file *filep);

static struct file_operations fops = {
    .open = hashbuke_open,
    .read = hashbuke_read,
    .write = hashbuke_write,
    .release = hashbuke_release,
};

static int __init hashbuke_init(void) {
    printk(KERN_INFO "Hello, HashBuke\n");

    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "\n");
        return major_number;
    }

    hashbuke_class = class_create(CLASS_NAME);
    if (IS_ERR(hashbuke_class)) {
        unregister_chrdev(major_number, DEVICE_NAME);
        printk(KERN_ALERT "注册设备类别失败\n");
        return PTR_ERR(hashbuke_class);
    }

    hashbuke_device = device_create(hashbuke_class, NULL, MKDEV(major_number, 0), NULL, DEVICE_NAME);
    if (IS_ERR(hashbuke_device)) {
        class_destroy(hashbuke_class);
        unregister_chrdev(major_number, DEVICE_NAME);
        printk(KERN_ALERT "创建设备失败\n");
        return PTR_ERR(hashbuke_device);
    }

    printk(KERN_INFO "HashBuke: 设备类创建正确\n");
    return 0;
}

static void __exit hashbuke_exit(void) {
    device_destroy(hashbuke_class, MKDEV(major_number, 0));
    class_unregister(hashbuke_class);
    class_destroy(hashbuke_class);
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Bye, HashBuke\n");
}

static int hashbuke_open(struct inode *inodep, struct file *filep) {
    printk(KERN_INFO "HashBuke:设备已打开 \n");
    return 0;
}

static int hashbuke_release(struct inode *inodep, struct file *filep) {
    printk(KERN_INFO "HashBuke: 设备成功关闭\n");
    return 0;
}

static ssize_t hashbuke_read(struct file *filep, char *buffer, size_t len, loff_t *offset) {
    struct timespec64 current_time;
    char time_buffer[30];
    int error_count;

    ktime_get_real_ts64(&current_time);
    snprintf(time_buffer, sizeof(time_buffer), "%lld\n", current_time.tv_sec);

    error_count = copy_to_user(buffer, time_buffer, strlen(time_buffer));

    if (error_count == 0) {
        printk(KERN_INFO "HashBuke:将当前时间发送给用户 \n");
        return 0;
    } else {
        printk(KERN_INFO "HashBuke: 无法将当前时间发送给用户\n");
        return -EFAULT;
    }
}

static ssize_t hashbuke_write(struct file *filep, const char *buffer, size_t len, loff_t *offset) {
    char input_buffer[10];
    long number;
    int error_count;

    error_count = copy_from_user(input_buffer, buffer, len);
    if (error_count != 0) {
        printk(KERN_INFO "HashBuke: 无法接收用户的输入\n");
        return -EFAULT;
    }

    input_buffer[len] = '\0';
    if (kstrtol(input_buffer, 10, &number) != 0) {
        printk(KERN_INFO "HashBuke:无法将输入转换为长整型 \n");
        return -EINVAL;
    }
    printk(KERN_INFO "HashBuke:已收到 %ld, 二进制表示: %lx\n", number, number);

    return len;
}

module_init(hashbuke_init);
module_exit(hashbuke_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("一个简单的 Linux 字符驱动程序 HashBuke");
MODULE_VERSION("1.0");


