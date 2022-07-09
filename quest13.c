#include<stdio.h>
#define print(a) printf("%d",a)
int a;
void A(int p)
{
    p+=a;
    print(p);

}
void B(int *q)
{
    int p=*q+3;
    A(p);
    *q=p-2;
    print(a);
}
main (void)
{
    a=6;
    B(&a);
    print(a);

}
