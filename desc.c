#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int sort(int *arr,int n);
int main(){
      int *array,n,i,p;
      printf("enter size of array");
      scanf("%d",&n);
      array=(int *)malloc(sizeof(int)*n);
      printf("enter array");
      for (int i=0;i<n;i++)
        {
                scanf("%d",&p);
                array[i]=p;
        }
     array=sort(array,n);
     for(i=0;i<n;i++){
         printf("%d ",array[i]);
     }

 }


int sort(int *arr,int n){
    int i,j,temp;
       for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]<arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }

    }

     return arr;
      }


