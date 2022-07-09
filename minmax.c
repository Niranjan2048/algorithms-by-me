#include <stdio.h>
#include <stdlib.h>

typedef struct minmax{
    int min;
    int max;
}pair;

pair getMinMax(int *array,int low,int high){
    pair minmax,minmaxleft,minmaxright;
    int mid;

    if (low==high){
        minmax.min=array[low];
        minmax.max=array[low];

        return minmax;
    }
    else if(high==low+1){
        if(array[low]>array[high]){
            minmax.min=array[high];
            minmax.max=array[low];
        }
        else{
            minmax.min=array[low];
            minmax.max=array[high];
        }

        return minmax;
    }
    else{
        mid=low+(high-low)/2;
        minmaxleft=getMinMax(array,low,mid);
        minmaxright=getMinMax(array,mid+1,high);

        if(minmaxleft.min<minmaxright.min){
            minmax.min=minmaxleft.min;
        }
        else{
            minmax.min=minmaxright.min;
        }

        if(minmaxleft.max<minmaxright.max){
            minmax.max=minmaxright.max;
        }
        else{
            minmax.max=minmaxleft.max;
        }

        return minmax;
    }

};
int random_array(int *array,int n){
    for(int i=0;i<n;i++){
        array[i]=rand()%1000;
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }

}
int main()
{
    int array_size,ch;
    int *array=NULL;
    printf("Enter array Size :");
    scanf("%d",&array_size);
    array= (int*)malloc(array_size*sizeof(int));
    if(array_size<0)
       {printf("size is negative\n");
        exit(0);
        }
    if(array==NULL || array_size==0){
        printf("No Memory Available");
    }
    else{

            printf("\n--------------Find Min and Max(recursive)-------------\n");




                random_array(array,array_size);
                pair minmax=getMinMax(array,0,array_size-1);
                printf("\n\nSmallest Element :%d",minmax.min);
                printf("\nLargest Element :%d",minmax.max);



                //random_array(array,array_size);
                //pair minmax2=getMinMax_iterative(array,array_size);
                //printf("\n\nSmallest Element :%d",minmax2.min);
                //printf("\nLargest Element :%d",minmax2.max);
                //break;



    }


    return 0;
}
