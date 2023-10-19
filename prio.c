#include <stdio.h>

struct Process {
    int id;
    int priority;
    int burst_time;
};

void swap(struct Process *xp, struct Process *yp) {
    struct Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void priorityScheduling(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter priority and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].priority, &processes[i].burst_time);
    }

    priorityScheduling(processes, n);

    printf("\nProcess\tPriority\tBurst Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", processes[i].id, processes[i].priority, processes[i].burst_time);
    }

    return 0;
}
