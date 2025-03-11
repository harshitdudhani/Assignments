// #include<stdio.h>

// struct Process 
// {
//     int pid;     // Process ID
//     int bt;      // Burst Time
//     int at;      // Arrival Time
//     int wt;      // Waiting Time
//     int tat;     // Turnaround Time
// };

// void sort_by_arrival(struct Process p[],int n) 
// {
//     struct Process temp;
//     for(int i=0;i<n-1;i++) 
//     {
//         for(int j=i+1;j<n;j++) 
//         {
//             if(p[i].at>p[j].at) 
//             {
//                 temp=p[i];
//                 p[i]=p[j];
//                 p[j]=temp;
//             }
//         }
//     }
// }

// void sort_by_burst(struct Process p[],int n) 
// {
//     struct Process temp;
//     for(int i=1;i<n;i++) 
//     {
//         for(int j=i+1;j<n;j++) 
//         {
//             if(p[i].bt>p[j].bt) 
//             {
//                 temp=p[i];
//                 p[i]=p[j];
//                 p[j]=temp;
//             }
//         }
//     }
// }

// void calculate_times(struct Process p[],int n) 
// {
//     p[0].wt=0;
//     p[0].tat=p[0].bt;

//     for(int i=1;i<n;i++) 
//     {
//         p[i].wt = (p[i-1].wt+p[i-1].bt)-p[i].at;
//         if(p[i].wt<0)
//         {
//             p[i].wt=0;
//         }
//         p[i].tat = p[i].wt+p[i].bt;
//     }
// }

// void display_results(struct Process p[],int n) 
// {
//     float totalWT=0,totalTAT=0;
//     printf("\nPID\tAT\tBT\tWT\tTAT\n");
//     for(int i=0;i<n;i++) 
//     {
//         printf("%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].wt,p[i].tat);
//         totalWT+=p[i].wt;
//         totalTAT+=p[i].tat;
//     }
//     printf("\nAverage Waiting Time: %.2f",totalWT/n);
//     printf("\nAverage Turnaround Time: %.2f\n",totalTAT/n);
// }

// int main() 
// {
//     int n;
//     printf("Enter the number of processes : ");
//     scanf("%d",&n);
    
//     struct Process p[n];

//     printf("Enter Arrival Time and Burst Time for each process:\n");
//     for(int i=0;i<n;i++) 
//     {
//         p[i].pid=i+1;
//         printf("Process %d - Arrival Time: ",i+1);
//         scanf("%d",&p[i].at);
//         printf("Process %d - Burst Time: ",i+1);
//         scanf("%d",&p[i].bt);
//     }

//     // FCFS Scheduling
//     printf("\n==== FCFS Scheduling ====\n");
//     sort_by_arrival(p,n);
//     calculate_times(p,n);
//     display_results(p,n);

//     // SJF Scheduling
//     printf("\n==== SJF Scheduling ====\n");
//     sort_by_burst(p,n);
//     calculate_times(p,n);
//     display_results(p,n);

// }


#include <stdio.h>

struct Process {
    int pid;     // Process ID
    int bt;      // Burst Time
    int at;      // Arrival Time
    int wt;      // Waiting Time
    int tat;     // Turnaround Time
};

// Function to sort processes based on Arrival Time (for FCFS)
void sortByArrival(struct Process p[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// Function to sort processes based on Burst Time (for SJF)
void sortByBurst(struct Process p[], int n) {
    struct Process temp;
    for (int i = 1; i < n; i++) { // Start from 1 since first process executes first
        for (int j = i + 1; j < n; j++) {
            if (p[i].bt > p[j].bt) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// Function to calculate Waiting Time and Turnaround Time
void calculateTimes(struct Process p[], int n) {
    p[0].wt = 0; // First process has no waiting time
    p[0].tat = p[0].bt; // Turnaround time = burst time for first process

    for (int i = 1; i < n; i++) {
        p[i].wt = (p[i - 1].wt + p[i - 1].bt) - p[i].at;
        if (p[i].wt < 0) p[i].wt = 0; // Ensure no negative waiting time
        p[i].tat = p[i].wt + p[i].bt;
    }
}

// Function to display results
void displayResults(struct Process p[], int n) {
    float totalWT = 0, totalTAT = 0;
    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].wt, p[i].tat);
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
    }
    printf("\nAverage Waiting Time: %.2f", totalWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTAT / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process p[n];

    // Taking input for processes
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Process %d - Arrival Time: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Process %d - Burst Time: ", i + 1);
        scanf("%d", &p[i].bt);
    }

    // FCFS Scheduling
    printf("\n==== FCFS Scheduling ====\n");
    sortByArrival(p, n);  // Sort by arrival time
    calculateTimes(p, n);
    displayResults(p, n);

    // SJF Scheduling
    printf("\n==== SJF Scheduling ====\n");
    sortByBurst(p, n); // Sort by burst time after first process execution
    calculateTimes(p, n);
    displayResults(p, n);

    return 0;
}
