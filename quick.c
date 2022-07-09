#include <stdio.h>
#include <stdlib.h>

int partition(int x[],int lb,int ub)
{
	int pivot,temp,up,down;
	pivot=x[lb];
	down=lb;
	up=ub;
	while(down<up)
	{
		while(x[down]<=pivot && down<ub)
		{
			down++;
		}
		while(x[up]>pivot)
		{
			up--;
		}
		if(down<up)
		{
			temp=x[down];
			x[down]=x[up];
			x[up]=temp;
		}
	}
	x[lb]=x[up];
	x[up]=pivot;
	return up;
}
void quick(int lb,int ub,int x[])
{
	int j;
	if(lb<ub)
	{
		j=partition(x,lb,ub);
		quick(lb,j-1,x);
		quick(j+1,ub,x);
	}
}
int random_array(int n,int *array){
    int j;
    printf("Enter modulus: ");
    scanf("%d", &j);
    for(int i=0;i<n;i++){
        array[i]=rand()%j;
    }
    printf("\nQ: ");
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}
void main(){
    int n,ch;
    int *array=NULL;
    printf("Enter size of Array :");
    scanf("%d",&n);
    array=(int*)malloc(sizeof(int)*n);
    if(n<0)
       {printf("size is negative\n");
        exit(0);
        }
    if(array == NULL || n==0){
        printf("No memory Available");
    }
    else{





                random_array(n,array);
                quick(0,n-1,array);
                printf("A: ");
                for(int i=0; i<n;i++){
                    printf("%d ",array[i]);
                }



        }


    }
