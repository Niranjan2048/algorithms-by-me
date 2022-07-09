#include<stdio.h>

struct sjf
{
int bt,at,wt,st,pno,tt,cbt;
};

void waitingTime(struct sjf arr[], int n)
{
int i;
float twt = 0.0;
printf("\nWAITING TIME = RESPONSE TIME - ARRIVAL TIME\n");
for(i = 0; i < n; i++)
{
printf(" P%d = %d units\n", arr[i].pno, arr[i].wt);
twt += arr[i].wt;
}
printf("\nAVERAGE WAITING TIME = %f units", twt/n);
}

void turnAroundTime(struct sjf arr[], int n)
{
int i;
float atat = 0.0;
printf("\n\nTURN AROUND TIME = WAITING TIME + BURST TIME\n");
for(i = 0; i< n; i++)
{
printf(" P%d = %d units \n", arr[i].pno, arr[i].tt);

atat += arr[i].tt;
}

printf("\nAVERAGE TURNAROUND TIME = %f units", atat/n);
}

void throughput(int *si, int n, int c)
{
int i;
float tp = n/(float)(si[c] - si[0]);
printf("\n\nTHROUGHPUT = TOTAL NUMBER OF PROCESSES / ((END TIME OF EXECUTION)-(START TIME OF EXECUTION))");
printf("\nTHROUGHPUT = %f units",tp);
}

int get(struct sjf arr[],int t,int n)
{
int imin,min=9999,i;
for(i=0;i<n;i++)
{
if(arr[i].at<=t&&arr[i].st==0)
if(min>arr[i].bt)
{
min=arr[i].bt;
imin=i;
}
}
return imin;
}

void ganttChart(struct sjf arr[],int p[],int n,int nop)

{
int i,a[100],s=0, si[100], process[100],c=0;
float avgtt=0,avgwt=0;
printf("\n\nGANTT CHART:\n");

si[0] = 0;
for(i = 0; i < n-1; i++)
{
while((i < n-1) && (p[i] == p[i+1]))
{
s++;
i++;
}
s++;
process[c] = arr[p[i]].pno;
si[c] = s ;
c++;
arr[p[i]].wt = s - arr[p[i]].at - arr[p[i]].tt;
}

for(i = c; i >=0; i--)
si[i] = si[i-1];
si[0] = arr[0].at;

for(i = 0; i < c; i++)
printf("-------");
printf("-\n");

for(i = 0; i < c; i++)
printf("| P%d ",process[i]);

printf("|\n");

for(i = 0; i < c; i++)
printf("-------");
printf("-\n");

for(i = 0; i <= c; i++)
(si[i] < 10)? printf("%d ", si[i]):printf("%d ", si[i]);
printf("\n");

for(i=0;i<nop;i++)
{
arr[i].tt+=arr[i].wt;
avgwt+=arr[i].wt;
avgtt+=arr[i].tt;
}
waitingTime(arr,nop);
turnAroundTime(arr,nop);
throughput(si, nop, c);
return;
}

int isComplete(struct sjf arr[],int n)
{
int i;
for(i=0;i<n;i++)
if(arr[i].st==0)
return 0;
return 1;
}

int main()
{
int n,i,a,t=0;
int p[100];
float avgwt=0,avgtt=0;
struct sjf arr[100];
printf("******SJF****** \n");
printf("Enter the number of processes: ");
scanf("%d",&n);

for(i=0;i<n;i++)
{
printf("*****DATA ENTRY*****\n");
printf("Process Number (e.g. P1 so enter 1) : ");
scanf("%d",&arr[i].pno);
printf("Arrival Time: ");
scanf("%d",&arr[i].at);
printf("Burst Time: ");
scanf("%d",&arr[i].bt);
arr[i].cbt = arr[i].bt;
arr[i].st=0;
arr[i].tt=arr[i].bt;
arr[i].wt=0;
}
i=0;
while(1)
{
if(isComplete(arr,n))
break;

a=get(arr,t,n);
p[i]=a;
arr[a].bt-=1;
if(arr[a].bt==0)
arr[a].st=1;
t=t+1;
i++;
}
ganttChart(arr,p,i,n);
return 0;
}
