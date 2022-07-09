#include<stdio.h>
#include<stdlib.h>


void printArray(int n,int *arr)
{   int i;
    for( i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}int bin_search(int *arr,int l,int r,int s)
{
    int mid;
    if(r>l){
         mid=l+(r-l)/2;

    if(arr[mid]==s)
    {
     return mid;
    }
    if(arr[mid]<s)
    {
        return bin_search(arr,mid+1,r,s);
    }
    else
    {
        return bin_search(arr,l,mid-1,s);
    }
    }
    if(arr[r]==s)
        return r;
    else
        printf("element not found");

        return -1;
}

void selection_sort(int n,int *arr)
{
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

//void main()
//{int *arr=NULL,loc,s;
//    int n,i,ch;
//    printf("Enter the size of Array :");
//    scanf("%d",&n);
//
//    arr=(int*)malloc(n*sizeof(int));
//    if(n<0)
//       {printf("size is negative\n");
//        exit(0);
//        }
//
//    if(arr ==NULL || n==0 )
//    {
//        printf("No memory Available");
//        exit(0);
//    }
//else
//    {
//
//        for(int i=0;i<n;i++)
//            arr[i]=rand()%1000;
//        selection_sort(n,arr);
//    }
//    int l=0;
//    int r=n-1;
//    printf("Enter the element to be searched");
//    scanf("%d",&s);
//    loc=bin_search(arr,l,r,s);
//    printf("Element found at %d",loc);
//
//
//
//
//}
int main(void)
{int arr[]={5,9,15,12,41};
int n=sizeof(arr)/sizeof(arr[0]);
int x=15;
int result=bin_search(arr,0,n-1,x);
if(result !=1)
    printf("%d",result);
return 0;

}



