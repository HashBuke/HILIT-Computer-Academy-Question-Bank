#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int pid; // 进程ID
    int arrival_time; // 到达时间
    int burst_time; // 执行时间
    int priority; // 优先级
    int wait_time; // 等待时间
    int turnaround_time; // 周转时间
    int remaining_time; // 剩余时间，用于RR算法
} Process;

// 按到达时间对进程进行排序的函数
void sortByArrival(Process p[], int n) {
    Process temp;
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-1-i; j++) {
            if(p[j].arrival_time > p[j+1].arrival_time) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

// 先来先服务（FCFS）算法
void FCFS(Process p[], int n) {
    int time = 0;
    for(int i=0; i<n; i++) {
        if(time < p[i].arrival_time) {
            time = p[i].arrival_time;
        }
        p[i].wait_time = time - p[i].arrival_time; // 计算等待时间
        time += p[i].burst_time; // 更新时间
        p[i].turnaround_time = p[i].wait_time + p[i].burst_time; // 计算周转时间
    }
}

// 最短作业优先（SJF）算法
void SJF(Process p[], int n) {
    int time = 0, completed = 0, min_index;
    int visited[MAX] = {0}; // 访问标记数组
    while(completed != n) {
        min_index = -1;
        for(int i=0; i<n; i++) {
            if(!visited[i] && (min_index == -1 || p[i].burst_time < p[min_index].burst_time) && p[i].arrival_time <= time) {
                min_index = i;
            }
        }
        if(min_index != -1) {
            visited[min_index] = 1;
            time += p[min_index].burst_time;
            p[min_index].wait_time = time - p[min_index].arrival_time - p[min_index].burst_time;
            p[min_index].turnaround_time = time - p[min_index].arrival_time;
            completed++;
        } else {
            time++;
        }
    }
}

// 时间片轮转（RR）算法
void RR(Process p[], int n, int quantum) {
    int time = 0, completed = 0;
    while(completed != n) {
        int all_done = 1; // 标记是否所有进程都完成
        for(int i=0; i<n; i++) {
            if(p[i].remaining_time > 0 && p[i].arrival_time <= time) {
                all_done = 0;
                if(p[i].remaining_time > quantum) {
                    time += quantum;
                    p[i].remaining_time -= quantum;
                } else {
                    time += p[i].remaining_time;
                    p[i].remaining_time = 0;
                    p[i].turnaround_time = time - p[i].arrival_time;
                    p[i].wait_time = p[i].turnaround_time - p[i].burst_time;
                    completed++;
                }
            }
        }
        if (all_done) { // 如果所有进程都完成，跳出循环
            break;
        }
        time++;
    }
}

// 优先级调度算法
void Priority(Process p[], int n) {
    int time = 0, completed = 0, min_index;
    int visited[MAX] = {0};
    while(completed != n) {
        min_index = -1;
        for(int i=0; i<n; i++) {
            if(!visited[i] && (min_index == -1 || p[i].priority < p[min_index].priority) && p[i].arrival_time <= time) {
                min_index = i;
            }
        }
        if(min_index != -1) {
            visited[min_index] = 1;
            time += p[min_index].burst_time;
            p[min_index].wait_time = time - p[min_index].arrival_time - p[min_index].burst_time;
            p[min_index].turnaround_time = time - p[min_index].arrival_time;
            completed++;
        } else {
            time++;
        }
    }
}

// 计算平均等待时间和周转时间的函数
void calculateAverageTimes(Process p[], int n, const char *algorithm) {
    int total_wait_time = 0, total_turnaround_time = 0;
    for(int i=0; i<n; i++) {
        total_wait_time += p[i].wait_time;
        total_turnaround_time += p[i].turnaround_time;
    }
    printf("%s算法：\n", algorithm); // 打印算法名称
    printf("平均等待时间：%.3f\n", (float)total_wait_time / n); // 打印平均等待时间
    printf("平均周转时间：%.3f\n\n", (float)total_turnaround_time / n); // 打印平均周转时间
}

int main() {
    int n = 10, quantum = 2;
    Process p[] = {
        {1, 0, 5, 1, 0, 0, 5},
        {2, 1, 3, 3, 0, 0, 3},
        {3, 2, 8, 2, 0, 0, 8},
        {4, 3, 6, 4, 0, 0, 6},
        {5, 4, 2, 1, 0, 0, 2},
        {6, 5, 4, 3, 0, 0, 4},
        {7, 6, 7, 2, 0, 0, 7},
        {8, 7, 3, 4, 0, 0, 3},
        {9, 8, 1, 1, 0, 0, 1},
        {10, 9, 5, 3, 0, 0, 5}
    };

    // 为FCFS和SJF按到达时间排序
    sortByArrival(p, n);

    // 执行FCFS算法并计算平均等待时间和周转时间
    Process temp[MAX];
    memcpy(temp, p, n * sizeof(Process));
    FCFS(temp, n);
    calculateAverageTimes(temp, n, "FCFS");

    // 执行SJF算法并计算平均等待时间和周转时间
    memcpy(temp, p, n * sizeof(Process));
    SJF(temp, n);
    calculateAverageTimes(temp, n, "SJF");

    // 执行RR算法并计算平均等待时间和周转时间
    memcpy(temp, p, n * sizeof(Process));
    RR(temp, n, quantum);
    calculateAverageTimes(temp, n, "RR");

    // 执行优先级调度算法并计算平均等待时间和周转时间
    memcpy(temp, p, n * sizeof(Process));
    Priority(temp, n);
    calculateAverageTimes(temp, n, "Priority");
    printf("By:HashBuke\n");
    return 0;
}

