#include <stdio.h>

struct Process {
    int id;
    int burst_time;
    int remaining_time;
};

void roundRobinScheduling(struct Process processes[], int n, int time_quantum) {
    int completed = 0;
    int current_time = 0;

    printf("Gantt Chart:\n");
    printf("--------------------------------------------------\n");
    printf("| Time | Execution\n");
    printf("--------------------------------------------------\n");

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                int execute_time = (processes[i].remaining_time < time_quantum) ? processes[i].remaining_time : time_quantum;
                processes[i].remaining_time -= execute_time;

                // Print Gantt chart for this time quantum
                printf("|  %2d  |   P%d   \n", current_time, processes[i].id);

                current_time += execute_time;

                if (processes[i].remaining_time == 0) {
                    completed++;
                }
            }
        }
    }

    printf("--------------------------------------------------\n");
}

int main() {
    int n, time_quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    roundRobinScheduling(processes, n, time_quantum);

    return 0;
}
