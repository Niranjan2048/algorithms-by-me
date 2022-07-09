#include <stdio.h>
#include <stdlib.h>


void merge_sort(int l,int r ,int *array){

   if(l<r){
    int mid=l+(r-l)/2;
    merge_sort(l,mid,array);
    merge_sort(mid+1,r,array);

    merge(array,l,mid,r);
   }

}
void merge(int *array,int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int i=0,j=0,k=l;
    int *right,*left;

    left=(int*)malloc(sizeof(int)*n1);
    right=(int*)malloc(sizeof(int)*n2);

    for(i=0;i<n1;i++){
        left[i]=array[l+i];
    }
    for(i=0;i<n2;i++){
        right[i]=array[m+1+i];
    }
     i=0;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
                array[k]=left[i];
                i++;
        }
        else{
            array[k]=right[j];
            j++;
        }
        k++;

    }
    while(i<n1){
        array[k]=left[i];
        k++;
        i++;
    }
    while(j<n2){
        array[k]=right[j];
        k++;
        j++;
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
                merge_sort(0,n-1,array);
                for(int i=0; i<n;i++){
                    printf("%d ",array[i]);
                }



            }

        }




