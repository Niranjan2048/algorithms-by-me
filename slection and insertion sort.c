#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArray(int n,int *arr)
{   int i;
    for( i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
void selection_sort(int n,int *arr){
    int i,j,index,temp;
    for(i=0;i<n;i++)
    {
        index=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[index])
            {
                index=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[index];
        arr[index]=temp;
    }
    printArray(n,arr);

}
void insertion_sort(int n,int *arr){
    int i,j,key;
    for(i=1;i<n;i++)
    {
        j=i-1;
        key=arr[i];
        while(j>=0 && arr[j]> key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    printArray(n,arr);
}
void main()
{
    int *arr;
    int n,i,ch;
    printf("Enter the size of Array :");
    scanf("%d",&n);

    arr=(int*)malloc(n*sizeof(int));
    if(n<0)
       {printf("size is negative\n");
        exit(0);
        }

    /*if(n>pow(2,sizeof(double)))
    {
       printf("very large size of array");
       exit(0);
    }*/

    if(arr ==NULL || n==0 )
    {
        printf("No memory Available");
        exit(0);
    }

    else
    {
        printf("Enter Elements of array :");
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        do
        {
            printf("\n\n1:Selection Sort\n2:Insertion Sort\n3:Print array\n4:Exit");
            printf("\nEnter Your choice : ");
            scanf("%d",&ch);
            switch(ch){
            case 1:
                selection_sort(n,arr);
                break;
            case 2:
                insertion_sort(n,arr);
                break;
            case 3:
                printArray(n,arr);
                break;

            case 4:
                exit(0);
            }
        }while(ch!=4);

    }


}
