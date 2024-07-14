//用C语言编写一个程序，模拟实现虚拟内存管理中的先进先出(FIFO)页面置换算法和最近最少用(LRU)页面置换算法处理缺页中断。
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void generatePages(int pages[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        pages[i] = rand() % 10 + 1;
    }
}

int isPageInMemory(int page, int memory[], int capacity) {
    for (int i = 0; i < capacity; i++) {
        if (memory[i] == page) {
            return 1;
        }
    }
    return 0;
}

void printPages(int pages[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n");
}

void printMemory(int memory[], int capacity) {
    for (int i = 0; i < capacity; i++) {
        if (memory[i] == -1) {
            printf("| ");
        } else {
            printf("|%d", memory[i]);
        }
    }
    printf("|\n");
}

void fifo(int pages[], int n, int capacity) {
    int memory[capacity];
    int pageFaults = 0;
    int index = 0;

    for (int i = 0; i < capacity; i++) {
        memory[i] = -1;
    }

    printf("FIFO 过程:\n");

    for (int i = 0; i < n; i++) {
        printf("当前插入页: %d\n", pages[i]);
        if (!isPageInMemory(pages[i], memory, capacity)) {
            memory[index] = pages[i];
            index = (index + 1) % capacity;
            pageFaults++;
        }
        printMemory(memory, capacity);
    }

    printf("FIFO 页面中断次数: %d\n", pageFaults);
}

void lru(int pages[], int n, int capacity) {
    int memory[capacity];
    int pageFaults = 0;
    int age[capacity];

    for (int i = 0; i < capacity; i++) {
        memory[i] = -1;
        age[i] = 0;
    }

    printf("LRU 过程:\n");

    for (int i = 0; i < n; i++) {
        printf("当前插入页: %d\n", pages[i]);
        int minAge = i;
        int minIndex = -1;

        if (!isPageInMemory(pages[i], memory, capacity)) {
            for (int j = 0; j < capacity; j++) {
                if (memory[j] == -1) {
                    minIndex = j;
                    break;
                }
                if (age[j] < minAge) {
                    minAge = age[j];
                    minIndex = j;
                }
            }
            memory[minIndex] = pages[i];
            pageFaults++;
        }
        for (int j = 0; j < capacity; j++) {
            if (memory[j] != -1) {
                age[j]++;
            }
        }
        age[minIndex] = 0;
        printMemory(memory, capacity);
    }

    printf("LRU 页面中断次数: %d\n", pageFaults);
}

int main() {
    int capacity, n;
    printf("输入一次可以保存在内存中的页数：");
    scanf("%d", &capacity);
    printf("输入要处理的页数：");
    scanf("%d", &n);

    int pages[n];
    generatePages(pages, n);

    printf("Pages: ");
    printPages(pages, n);

    fifo(pages, n, capacity);
    lru(pages, n, capacity);

    return 0;
}

