#include <stdio.h>
#include <stdlib.h>

// Structure to represent a process
typedef struct
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int completed;
} process;

void display(process p[], int n)
{
    printf("\nPid\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
}

void main()
{
    int n, tot_tat = 0, tot_wt = 0;

    printf("\nEnter the number of p : ");
    scanf("%d", &n);

    process p[n];

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i;
        printf("\nEnter the arrival time of process %d : ", i);
        scanf("%d", &p[i].at);
        printf("\nEnter the burst time of process %d : ", i);
        scanf("%d", &p[i].bt);
        p[i].completed = 0;
    }

    // sorting by burst time
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[j].bt < p[i].bt)
            {
                process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int time = p[0].at;

    // finding lowest arrival time and storing it in time
    for (int i = 0; i < n; i++)
    {
        if (p[i].at < time)
        {
            time = p[i].at;
        }
    }

    int count = n;
    while (count)
    {
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= time && !p[i].completed)
            {
                time += p[i].bt;
                p[i].ct = time;
                p[i].tat = p[i].ct - p[i].at;
                p[i].wt = p[i].tat - p[i].bt;
                p[i].completed = 1;
                tot_tat += p[i].tat;
                tot_wt += p[i].wt;
                break;
            }
        }
        count--;
    }

    display(p, n);
    printf("\nAverage Waiting Time : %0.2f\nAverage Waiting Time : %0.2f", ((float)tot_tat / 2), ((float)tot_wt / 2));
}
