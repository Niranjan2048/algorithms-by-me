//#include<stdio.h>
//
//void main(){
//int i,j;
//for(i=4;i<300;i++)
//{for(j=2;j<i-1;j++){
//if(i%j==0)
//    {
//break;
//}
//else{
//        printf("\n%d",i);
//}}
//
//}}

#include<stdio.h>

void main()
{
    int i,j,n;

    printf("Enter the number till which you want prime numbers\n");
    scanf("%d",&n);

    printf("Prime numbers are:-\n");
    for(i=2;i<=n;i++)
    {
        int c=0;
        for(j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                c++;
            }
        }

       if(c==2)
        {
            printf("%d ",i);
        }
    }
}
