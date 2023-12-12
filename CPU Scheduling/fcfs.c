#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int pid, at, bt, wt, tat, ct;
} process;

void sort(process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void fcfs(process p[], int n)
{
    int time = p[0].at;
    for (int i = 0; i < n; i++)
    {
        time += p[i].bt;
        p[i].ct = time;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
}

void display(process p[], int n)
{
    int tot_tat = 0, tot_wt = 0;
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tCompletion Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].ct, p[i].tat);
        tot_tat += p[i].tat;
        tot_wt += p[i].wt;
    }
    printf("\nAverage Waiting Time : %d\nAverage Turnaround Time : %d", (tot_wt / n), (tot_tat / n));
}

void main()
{
    int n;

    printf("\nEnter number of processes : ");
    scanf("%d", &n);
    process p[n];

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i;
        printf("\nEnter the arrival time of process %d : ", i);
        scanf("%d", &p[i].at);
        printf("\nEnter the burst time of process %d : ", i);
        scanf("%d", &p[i].bt);
    }
    sort(p, n);
    fcfs(p, n);
    display(p, n);
}