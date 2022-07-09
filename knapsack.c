#include<stdio.h>

struct object
{
    int profit;
    int weight;
};

struct  object a[100];
int n, capacity;

void insertionsortobjects()
{
    int i,j;
    struct object tempobject;

    for(i=1;i<n;i++)
    {
        tempobject=a[i];
        for(j=i-1;j>=0;j--)
        {
            if( ((float)tempobject.profit/tempobject.weight) > ((float)a[j].profit/a[j].weight))
            {
                a[j+1]=a[j];
            }
            else
                break;
        }
        a[j+1]=tempobject;
    }
    printf("\n\t Objects sorted decreasingly according to profit/weight ratio:-\n");
    for(i=0;i<n;i++)
    {
        printf("[%d] profit=%d weight=%d profit/weight(rounddown)=%f\n", i, a[i].profit, a[i].weight, (float)a[i].profit/a[i].weight);
    }
    printf("\n\n");

}

int main()
{
    int i, rcapacity, totalprofit, collectionweight=0, maxachievableprofit=0;

    scanf("%d", &n, printf("Enter number of object <100: "));
    for(i=0;i<n;i++)
    {
        printf("Enter object[%d] profit:- ", i);
        scanf("%d", &a[i].profit);
        printf("Enter object[%d] weight :- ",i);
        scanf("%d", &a[i].weight);
        collectionweight=collectionweight+a[i].weight;
        maxachievableprofit=maxachievableprofit+a[i].profit;
    }

    insertionsortobjects();
    printf("Total collection weight=%d  Max achievable profit=%d \n Enter the sack capacity:- ", collectionweight, maxachievableprofit);
    scanf("%d", &capacity);
    rcapacity=capacity; totalprofit=0;
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(a[i].weight<=rcapacity)
        {
            rcapacity=rcapacity-a[i].weight;
            totalprofit=totalprofit+a[i].profit;
            printf("Object %d picked up fully with full profit %d and remaining capacity=%d\n", i, a[i].profit, rcapacity);
        }
        else
            break;
    }
    if(rcapacity!=0)
    {
        totalprofit=totalprofit+ (a[i].profit * rcapacity)/a[i].weight;
        printf("Object %d picked up %d percent with Fractional profit= %d\n\n", i, (float)rcapacity*100/a[i].weight, (float)a[i].profit*rcapacity/a[i].weight);
    }
    printf("Total profit = %d\n\n", totalprofit);
  return 0;
}
