#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void calculateTimes(struct Process processes[], int n) {
    processes[0].completion_time = processes[0].arrival_time + processes[0].burst_time;
    processes[0].turnaround_time = processes[0].completion_time - processes[0].arrival_time;
    processes[0].waiting_time = processes[0].turnaround_time - processes[0].burst_time;
    
    for (int i = 1; i < n; i++) {
        if (processes[i].arrival_time > processes[i-1].completion_time) {
            processes[i].completion_time = processes[i].arrival_time + processes[i].burst_time;
        } else {
            processes[i].completion_time = processes[i-1].completion_time + processes[i].burst_time;
        }
        
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
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

void sortByArrivalTime(struct Process processes[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void displayGanttChart(struct Process processes[], int n) {
    int time_scale = 2;
    int total_burst_time = 0, current_time = 0;
    int timeline[100] = {0};
    int execution_order[100] = {0};
    int execution_count = 0;
    
    for (int i = 0; i < n; i++) {
        if (processes[i].arrival_time > current_time) {
            for (int j = current_time; j < processes[i].arrival_time; j++) {
                timeline[execution_count] = 1;
                execution_order[execution_count] = 0;
                execution_count++;
            }
            current_time = processes[i].arrival_time;
        }
        
        for (int j = 0; j < processes[i].burst_time; j++) {
            timeline[execution_count] = 1;
            execution_order[execution_count] = processes[i].pid;
            execution_count++;
        }
        
        current_time += processes[i].burst_time;
    }
    
    printf("\nGantt Chart:\n");
    
    printf(" ");
    for (int i = 0; i < execution_count; i++) {
        for (int j = 0; j < time_scale; j++) {
            printf("-");
        }
        printf(" ");
    }
    printf("\n|");
    
    for (int i = 0; i < execution_count; i++) {
        if (execution_order[i] == 0) {
            for (int j = 0; j < time_scale - 1; j++) {
                printf(" ");
            }
            printf("X");
        } else {
            for (int j = 0; j < time_scale - 1; j++) {
                printf(" ");
            }
            printf("%d", execution_order[i]);
        }
        printf("|");
    }
    printf("\n ");
    
    for (int i = 0; i < execution_count; i++) {
        for (int j = 0; j < time_scale; j++) {
            printf("-");
        }
        printf(" ");
    }
    
    printf("\n");
    printf("0");
    current_time = 0;
    
    for (int i = 0; i < execution_count; i++) {
        for (int j = 0; j < time_scale; j++) {
            printf(" ");
        }
        current_time += timeline[i];
        if (current_time < 10) {
            printf("%d", current_time);
        } else {
            printf("%d", current_time);
        }
    }
    printf("\n");
    
    printf("\nNote: 'X' indicates CPU idle time\n");
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
    }
    
    sortByArrivalTime(processes, n);
    calculateTimes(processes, n);
    displayProcesses(processes, n);
    displayGanttChart(processes, n);
    
    return 0;
}