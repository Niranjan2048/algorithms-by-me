#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *p, int *a, int*b, int n)
{
int i, j,t;
for (i = 0; i < n; i++)
{
for (j = i + 1; j < n; j++)
{
if (*(a + j) < *(a + i))
{
t = *(a + i);
*(a + i) = *(a + j);
*(a + j) = t;

t = *(b + i);
*(b + i) = *(b + j);
*(b + j) = t;

t = *(p + i);
*(p + i) = *(p + j);
*(p + j) = t;
}
}
}
}

void ganttChart(int *p,int *a, int*b, int n)
{

int i, j, k, t = a[0];

printf("\n\nGANTT CHART:\n");

for(i = 0; i < n; i++)
printf("-------");
printf("-\n");

for(i = 0; i < n; i++)
printf("| P%d ",p[i]);
printf("|\n");

for(i = 0; i < n; i++)
printf("-------");
printf("-\n");

for(i = 0; i <= n; i++)
{
(t<10)?printf("%d ",t):printf("%d ",t);
t += b[i];
}
printf("\n");
}

void waitingTime(int *p,int *a, int*b, int n)
{
int i, wt, t = a[0];
float twt = 0.0;
printf("WAITING TIME = RESPONSE TIME - ARRIVAL TIME\n");
for(i = 0; i< n; i++)
{
wt = t-a[i];

printf(" P%d = %d - %d = %d units\n",p[i],t,a[i],wt);
t += b[i];
twt += wt;
}

printf("\nAVERAGE WAITING TIME = %f units", twt/n);
}

void turnAroundTime(int *p,int *a, int*b, int n)
{
int i, tat, t = a[0];
float atat = 0.0;
printf("\n\nTURN AROUND TIME = WAITING TIME + BURST TIME\n");
for(i = 0; i< n; i++)
{
tat = t-a[i]+b[i];
printf(" P%d = %d + %d = %d units \n",p[i],t-a[i],b[i],tat);
t += b[i];
atat += tat;
}

printf("\nAVERAGE TURNAROUND TIME = %f units", atat/n);
}

void throughput(int *p,int *a, int*b, int n)
{
int i, t=0;
for(i=0;i<n;i++)
t +=b[i];
float tp = n/(float)(t-a[0]);
printf("\n\nTHROUGHPUT = TOTAL NUMBER OF PROCESSES / ((END TIME OF EXECUTION)-(START TIME OF EXECUTION))");

printf("\nTHROUGHPUT = %d / (%d - %d) = %f units",n,t,a[0],tp);
}

int main()
{
int *at, *bt, *wt, *tat, *process;
int n, i;
float AWT, ATAT, TP;
printf("******FCFS****** \n");
printf("Enter the number of processes: ");
scanf("%d", &n);

process = (int*)malloc(sizeof(int) * n);
at = (int*)malloc(sizeof(int)*n);
bt = (int*)malloc(sizeof(int)*n);
if((process != NULL) && (at != NULL) && (bt != NULL))
{
for(i=0; i<n; i++)
{
printf("*****DATA ENTRY*****\n");
printf("Process Number (eg. P1 so enter 1) : ");
scanf("%d",&process[i]);
printf("Arrival Time: ");
scanf("%d",&at[i]);
printf("Burst Time: ");
scanf("%d",&bt[i]);
}
bubbleSort(process,at,bt,n);
ganttChart(process,at,bt,n);
waitingTime(process,at,bt,n);
turnAroundTime(process,at,bt,n);
throughput(process,at,bt,n);

}
else
printf("NO MEMORY ALLOCATED");
return 0;
}
