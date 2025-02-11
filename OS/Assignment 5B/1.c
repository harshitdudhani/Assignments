#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

struct GanttEntry {
    int pid;
    int start_time;
    int end_time;
};

void calculateTimesWithGantt(struct Process processes[], int n, int quantum, 
                           struct GanttEntry gantt[], int *gantt_size) {
    int time = 0;
    int done = 0;
    *gantt_size = 0;
    
    for(int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
    }
    
    while(done < n) {
        for(int i = 0; i < n; i++) {
            if(processes[i].remaining_time > 0) {
                gantt[*gantt_size].pid = processes[i].pid;
                gantt[*gantt_size].start_time = time;
                
                if(processes[i].remaining_time > quantum) {
                    time += quantum;
                    processes[i].remaining_time -= quantum;
                }
                else {
                    time += processes[i].remaining_time;
                    processes[i].completion_time = time;
                    processes[i].remaining_time = 0;
                    done++;
                    
                    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                }
                
                gantt[*gantt_size].end_time = time;
                (*gantt_size)++;
            }
        }
    }
}

void displayGanttChart(struct GanttEntry gantt[], int size) {
    printf("\nGantt Chart:\n");
    
    printf(" ");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < 6; j++) printf("-");
        printf(" ");
    }
    printf("\n");
    
    printf("|");
    for(int i = 0; i < size; i++) {
        printf(" P%d  |", gantt[i].pid);
    }
    printf("\n");
    
    printf(" ");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < 6; j++) printf("-");
        printf(" ");
    }
    printf("\n");
    
    printf("0");
    for(int i = 0; i < size; i++) {
        if(gantt[i].end_time < 10)
            printf("      %d", gantt[i].end_time);
        else
            printf("     %d", gantt[i].end_time);
    }
    printf("\n");
}

void displayResults(struct Process processes[], int n) {
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    
    printf("\nProcess\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               processes[i].pid,
               processes[i].burst_time,
               processes[i].arrival_time,
               processes[i].completion_time,
               processes[i].turnaround_time,
               processes[i].waiting_time);
               
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }
    
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    
    printf("\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    int n, quantum;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process processes[n];
    struct GanttEntry *gantt = malloc(sizeof(struct GanttEntry) * 100);
    int gantt_size;
    
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    
    for(int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("\nFor Process %d:\n", i + 1);
        printf("Enter Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Enter Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
    }
    
    calculateTimesWithGantt(processes, n, quantum, gantt, &gantt_size);
    displayResults(processes, n);
    displayGanttChart(gantt, gantt_size);
    
    free(gantt);
    return 0;
}