#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define CYLINDERS 10
#define TRACKS 20

typedef struct {
    int cylinder;       // 柱面号
    int track;          // 磁道号
    int record;         // 物理记录号
    bool is_allocated;  // 分配状态
} Block;

Block disk[CYLINDERS][TRACKS];

void initialize_disk() {
    for (int i = 0; i < CYLINDERS; i++) {
        for (int j = 0; j < TRACKS; j++) {
            disk[i][j].cylinder = i;
            disk[i][j].track = j;
            disk[i][j].record = i * TRACKS + j; // 物理记录号按照顺序分配
            disk[i][j].is_allocated = false;
        }
    }
}

void display_disk() {
    printf("\n磁盘空间:\n");
    for (int i = 0; i < CYLINDERS; i++) {
        printf("|");
        for (int j = 0; j < TRACKS; j++) {
            if (disk[i][j].is_allocated) {
                printf("+");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf("\n");
}

bool allocate_blocks(int blocks) {
    int count = 0;
    for (int i = 0; i < CYLINDERS; i++) {
        for (int j = 0; j < TRACKS; j++) {
            if (!disk[i][j].is_allocated) {
                count++;
                if (count == blocks) {
                    // 分配块
                    for (int k = 0; k < blocks; k++) {
                        disk[i][j - k].is_allocated = true;
                        printf("分配块: 柱面号=%d, 磁道号=%d, 物理记录号=%d\n", disk[i][j - k].cylinder, disk[i][j - k].track, disk[i][j - k].record);
                    }
                    return true;
                }
            } else {
                count = 0;
            }
        }
    }
    return false;
}

void free_blocks(int cylinder, int track, int record, int length) {
    int count = 0;
    for (int i = cylinder; i < CYLINDERS; i++) {
        for (int j = (i == cylinder ? track : 0); j < TRACKS; j++) {
            if (disk[i][j].is_allocated && disk[i][j].record == record + count) {
                disk[i][j].is_allocated = false;
                printf("释放块: 柱面号=%d, 磁道号=%d, 物理记录号=%d\n", disk[i][j].cylinder, disk[i][j].track, disk[i][j].record);
                count++;
                if (count == length) {
                    return;
                }
            }
        }
    }
    printf("释放失败: 找不到足够的块或块未分配\n");
}

int main() {
    initialize_disk();
    int choice, blocks, length;
    int cylinder, track, record;
    
    while (1) {
        printf("\n菜单:\n1. 显示磁盘空间\n2. 分配空间\n3. 释放空间\n4. 退出\n选择功能（1-4）：");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                display_disk();
                break;
            case 2:
                printf("请输入要分配的块数: ");
                scanf("%d", &blocks);
                if (allocate_blocks(blocks)) {
                    printf("分配成功\n");
                } else {
                    printf("分配失败，磁盘空间不足或无法找到连续的空闲块\n");
                }
                break;
            case 3:
                printf("请输入要释放的块的柱面号、磁道号、物理记录号和删除长度: ");
                scanf("%d %d %d %d", &cylinder, &track, &record, &length);
                free_blocks(cylinder, track, record, length);
                break;
            case 4:
                return 0;
            default:
                printf("无效选择\n");
        }
    }
    
    return 0;
}

