#include<stdio.h>
struct process{
    int id;
    int bt;
    int priority;
    int wt;
    int tat;
};
void sortprocesses(struct process proc[],int n)
{
    struct process temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(proc[i].priority > proc[j].priority)
            {
                temp=proc[i];
                proc[i]=proc[j];
                proc[j]=temp;
            }
        }
    }
}
void calculatetimes(struct process proc[],int n)
{
    proc[0].wt=0;
    for(int i=1;i<n;i++){
        proc[i].wt=proc[i-1].wt+proc[i-1].bt;
    }
    for(int i=0;i<n;i++){
        proc[i].tat=proc[i].bt+proc[i].wt;
    }
}
void dispalyprocess(struct process proc[],int n)
{
    printf("\nPriority Scheduling Process Execution Order:\n");
    printf("PID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", 
        proc[i].id, proc[i].bt, proc[i].priority, proc[i].wt, proc[i].tat);
    }
    float avgwt=0;
    float avgtat=0;
    for (int i = 0; i < n; i++) {
        avgwt += proc[i].wt;
        avgtat += proc[i].tat;
    }
    avgwt /= n;
    avgtat /= n;
    printf("\nAverage Waiting Time: %.2f", avgwt);
    printf("\nAverage Turnaround Time: %.2f", avgtat);
}
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    struct process proc[n];
    for(int i=0;i<n;i++)
    {
        proc[i].id=i+1;
        printf("Enter the burst time and priority for process %d: ",proc[i].id);
        scanf("%d",&proc[i].bt);
        scanf("%d",&proc[i].priority);
    }
    sortprocesses(proc,n);
    calculatetimes(proc,n);
    dispalyprocess(proc,n);
    return 0;
}