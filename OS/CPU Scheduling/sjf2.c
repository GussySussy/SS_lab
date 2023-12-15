#include <stdio.h>
#include <stdbool.h>

// Structure to represent a process
struct Process
{
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    bool is_completed;
};

// Function to perform SJF scheduling
void sjf(struct Process processes[], int n)
{
    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < n)
    {
        int shortest_index = -1;
        int shortest_burst = 999999;

        for (int i = 0; i < n; i++)
        {
            if (!processes[i].is_completed && processes[i].arrival_time <= current_time && processes[i].burst_time < shortest_burst)
            {
                shortest_index = i;
                shortest_burst = processes[i].burst_time;
            }
        }

        if (shortest_index == -1)
        {
            current_time++;
        }
        else
        {
            processes[shortest_index].completion_time = current_time + processes[shortest_index].burst_time;
            processes[shortest_index].turnaround_time = processes[shortest_index].completion_time - processes[shortest_index].arrival_time;
            processes[shortest_index].waiting_time = processes[shortest_index].turnaround_time - processes[shortest_index].burst_time;
            processes[shortest_index].is_completed = true;
            completed_processes++;
            current_time = processes[shortest_index].completion_time;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++)
    {
        processes[i].process_id = i;
        printf("Enter arrival time for process P%d: ", i);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process P%d: ", i);
        scanf("%d", &processes[i].burst_time);
        processes[i].is_completed = false;
    }

    sjf(processes, n);

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time,
               processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time,
               processes[i].waiting_time);
    }

    return 0;
}
