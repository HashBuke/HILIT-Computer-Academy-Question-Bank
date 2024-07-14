#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

// 创建新文件
void create_file(const char *filename) {
    int fd = open(filename, O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("文件创建失败");
    } else {
        printf("文件创建成功: %s\n", filename);
        close(fd);
    }
}

// 写文件
void write_file(const char *filename, const char *content) {
    int fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1) {
        perror("打开文件失败（写入）");
    } else {
        if (write(fd, content, strlen(content)) == -1) {
            perror("写入文件失败");
        } else {
            printf("写入文件成功: %s\n", filename);
        }
        close(fd);
    }
}

// 读文件
void read_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("打开文件失败（读取）");
    } else {
        char buffer[1024];
        ssize_t bytesRead;
        while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
            buffer[bytesRead] = '\0';
            printf("%s", buffer);
        }
        if (bytesRead == -1) {
            perror("读取文件失败");
        }
        close(fd);
    }
}

// 修改文件权限
void change_permissions(const char *filename, mode_t mode) {
    if (chmod(filename, mode) == -1) {
        perror("修改文件权限失败");
    } else {
        printf("文件权限修改成功: %s\n", filename);
    }
}

// 查看文件权限
void view_permissions(const char *filename) {
    struct stat fileStat;
    if (stat(filename, &fileStat) == -1) {
        perror("获取文件状态失败");
    } else {
        printf("文件 %s 的权限: \n", filename);
        printf((S_ISDIR(fileStat.st_mode)) ? "目录" : "文件");
        printf("\n");
        printf("用户权限：");
        printf((fileStat.st_mode & S_IRUSR) ? " 读取" : " -");
        printf((fileStat.st_mode & S_IWUSR) ? " 写入" : " -");
        printf((fileStat.st_mode & S_IXUSR) ? " 执行" : " -");
        printf("\n");
        printf("组权限：");
        printf((fileStat.st_mode & S_IRGRP) ? " 读取" : " -");
        printf((fileStat.st_mode & S_IWGRP) ? " 写入" : " -");
        printf((fileStat.st_mode & S_IXGRP) ? " 执行" : " -");
        printf("\n");
        printf("其它人权限：");
        printf((fileStat.st_mode & S_IROTH) ? " 读取" : " -");
        printf((fileStat.st_mode & S_IWOTH) ? " 写入" : " -");
        printf((fileStat.st_mode & S_IXOTH) ? " 执行" : " -");
        printf("\n");
    }
}

int main() {
    int choice;
    char filename[256];
    char content[1024];
    mode_t mode;

    while (1) {
        printf("\n文件工具菜单:\n");
        printf("1. 创建新文件\n");
        printf("2. 写文件\n");
        printf("3. 读文件\n");
        printf("4. 修改文件权限\n");
        printf("5. 查看文件权限\n");
        printf("6. 退出\n");
        printf("请输入您的选择: ");
        scanf("%d", &choice);
        getchar();  // 消耗缓冲区中的换行符

        switch (choice) {
            case 1:
                printf("请输入文件名: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0';  // 去除换行符
                create_file(filename);
                break;
            case 2:
                printf("请输入文件名: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0';
                printf("请输入内容: ");
                fgets(content, sizeof(content), stdin);
                content[strcspn(content, "\n")] = '\0';
                write_file(filename, content);
                break;
            case 3:
                printf("请输入文件名: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0';
                read_file(filename);
                break;
            case 4:
                printf("请输入文件名: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0';

//                printf("权限模式解释:\n");
//                printf("所有者（用户）：r(4) w(2) x(1)\n");
//                printf("组：r(4) w(2) x(1)\n");
//                printf("其他人：r(4) w(2) x(1)\n");
//                printf("例如，0755 表示所有者可读写执行，组和其他人可读执行\n");
//                printf("请输入新的权限（八进制，例如 0644 表示用户可读写，组和其他人可读）: ");
                scanf("%o", &mode);
                getchar();  // 消耗缓冲区中的换行符
                change_permissions(filename, mode);
                break;
            case 5:
                printf("请输入文件名: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0';
                view_permissions(filename);
                break;
            case 6:
                printf("退出...\n");
                exit(0);
            default:
                printf("无效选择，请重试。\n");
        }
    }

    return 0;
}
