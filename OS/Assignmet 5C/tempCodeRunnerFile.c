#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int is_completed;
};

void calculateTimesSJF(struct Process processes[], int n) {
    int current_time = 0;
    int completed = 0;
    
    while (completed != n) {
        int idx = -1;
        int min_burst = 9999;
        
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].is_completed == 0) {
                if (processes[i].burst_time < min_burst) {
                    min_burst = processes[i].burst_time;
                    idx = i;
                }
                if (processes[i].burst_time == min_burst) {
                    if (processes[i].arrival_time < processes[idx].arrival_time) {
                        min_burst = processes[i].burst_time;
                        idx = i;
                    }
                }
            }
        }
        
        if (idx != -1) {
            processes[idx].completion_time = current_time + processes[idx].burst_time;
            processes[idx].turnaround_time = processes[idx].completion_time - processes[idx].arrival_time;
            processes[idx].waiting_time = processes[idx].turnaround_time - processes[idx].burst_time;
            
            processes[idx].is_completed = 1;
            completed++;
            current_time = processes[idx].completion_time;
        } else {
            current_time++;
        }
    }
}

void displayProcesses(struct Process processes[], int n) {
    printf("\nProcess Execution Details:\n");
    printf("+---------+--------------+------------+----------------+----------------+--------------+\n");
    printf("| Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |\n");
    printf("+---------+--------------+------------+----------------+----------------+--------------+\n");
    
    for (int i = 0; i < n; i++) {
        printf("| P%-6d | %-12d | %-10d | %-14d | %-14d | %-12d |\n",
               processes[i].pid,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].completion_time,
               processes[i].turnaround_time,
               processes[i].waiting_time);
    }
    printf("+---------+--------------+------------+----------------+----------------+--------------+\n");
    
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    
    printf("\nAverage Waiting Time = %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time = %.2f\n", avg_turnaround_time);
}

void displayGanttChart(struct Process processes[], int n) {
    int i, j;
    int total_burst_time = 0;
    int current_time = 0;
    int completed = 0;
    int execution_order[100];
    int execution_time[100];
    int count = 0;
    
    struct Process temp_processes[n];
    for (i = 0; i < n; i++) {
        temp_processes[i] = processes[i];
        temp_processes[i].is_completed = 0;
    }
    
    while (completed != n) {
        int idx = -1;
        int min_burst = 9999;
        
        for (i = 0; i < n; i++) {
            if (temp_processes[i].arrival_time <= current_time && temp_processes[i].is_completed == 0) {
                if (temp_processes[i].burst_time < min_burst) {
                    min_burst = temp_processes[i].burst_time;
                    idx = i;
                }
                if (temp_processes[i].burst_time == min_burst) {
                    if (temp_processes[i].arrival_time < temp_processes[idx].arrival_time) {
                        min_burst = temp_processes[i].burst_time;
                        idx = i;
                    }
                }
            }
        }
        
        if (idx != -1) {
            execution_order[count] = temp_processes[idx].pid;
            execution_time[count] = current_time;
            
            current_time += temp_processes[idx].burst_time;
            temp_processes[idx].is_completed = 1;
            completed++;
            count++;
        } else {
            execution_order[count] = 0; // Idle time
            execution_time[count] = current_time;
            current_time++;
            count++;
        }
    }
    execution_time[count] = current_time; // Final time
    
    printf("\nGantt Chart:\n");
    printf(" ");
    
    for (i = 0; i < count; i++) {
        for (j = 0; j < execution_time[i+1] - execution_time[i]; j++) {
            printf("-");
        }
        printf(" ");
    }
    printf("\n|");
    
    for (i = 0; i < count; i++) {
        if (execution_order[i] == 0) {
            for (j = 0; j < execution_time[i+1] - execution_time[i] - 1; j++) {
                printf(" ");
            }
            printf("X");
        } else {
            for (j = 0; j < execution_time[i+1] - execution_time[i] - 1; j++) {
                printf(" ");
            }
            printf("%d", execution_order[i]);
        }
        printf("|");
    }
    
    printf("\n ");
    for (i = 0; i < count; i++) {
        for (j = 0; j < execution_time[i+1] - execution_time[i]; j++) {
            printf("-");
        }
        printf(" ");
    }
    
    printf("\n");
    
    for (i = 0; i <= count; i++) {
        if (execution_time[i] < 10) {
            printf("%d", execution_time[i]);
        } else {
            printf("%d", execution_time[i]);
        }
        
        if (i < count) {
            for (j = 0; j < execution_time[i+1] - execution_time[i]; j++) {
                printf(" ");
            }
        }
    }
    
    printf("\n\nNote: 'X' indicates CPU idle time\n");
}

int main() {
    int n;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process processes[n];
    
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("\nEnter details for Process P%d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].is_completed = 0;
    }
    
    calculateTimesSJF(processes, n);
    displayProcesses(processes, n);
    displayGanttChart(processes, n);
    
    return 0;
}