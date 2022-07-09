#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int m=1,f=0,e=5,x=0;

void main()
{int n;
void producer();
void consumer();
int wait(int);
int signal(int);
printf("\n1.Producer\n2.Consumer\n3.Exit");
while(1)
{
printf("\nEnter your choice ");
scanf("%d",&n);
switch(n)
{
case 1:if(m==1&&e!=0)
producer();
else
printf("\nBuffer is full");
break;

case 2:if(m==1&&f!=0)
consumer();
else
printf("\nBuffer is empty");

break;
case 3:exit(0);
}
}

}
int wait(int s)
{
return --s;
}

int signal(int s)
{
return(++s);
}

void producer()
{
m=wait(m);
f=signal(f);
e=wait(e);
x++;
printf("Producer produces the item %d\n",x);
m=signal(m);

}

void consumer()
{
m=wait(m);

f=wait(f);
e=signal(e);
printf("Consumer consumes item %d\n",x);
x--;
m=signal(m);
}
