#include <stdio.h>

struct Process {
    int id;
    int burst_time;
};

void fcfsScheduling(struct Process processes[], int n) {
    int waiting_time[n];
    int turnaround_time[n];

    waiting_time[0] = 0;
    turnaround_time[0] = processes[0].burst_time;

    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + processes[i - 1].burst_time;
        turnaround_time[i] = waiting_time[i] + processes[i].burst_time;
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, waiting_time[i], turnaround_time[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for process P%d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
    }

    fcfsScheduling(processes, n);

    return 0;
}
