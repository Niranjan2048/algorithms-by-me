#include<stdio.h>

int main(){
int a[]={41,30,9,40,15,6};
int *p[]={a,a+1,a+2,a+3,a+4,a+5};
int **pp;
pp=p;
pp++;
printf("%d\t%d\t%d\n",pp-p,*pp-a,**pp);
*pp++;
printf("%d\t%d\t%d\n",pp-p,*pp-a,**pp);
++*pp;
printf("%d\t%d\t%d\n",pp-p,*pp-a,**pp);
++**pp;
printf("%d\t%d\t%d\n",pp-p,*pp-a,**pp);
return 0;
}


