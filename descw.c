#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 int sort(int *,int n);
 int main(){
      int *a,n,i;
      scanf("%d",&n);
      a=(int *)malloc(n *sizeof(int));
      for(i=0;i<n;i++){
          scanf("%d",a[i]);
     }
     sort(a,n);
     for(i=0;i<n;i++){
         printf("%d ",(a[i]));
     }
     return 0;
 }


int sort(int *l,int n){
    int i,j,t;
      for(i=0;i<n;i++){
          for(j=0;j<=i;j++){
              if(((l+i))<((l+j))){
                  t=*(l+i);
                  (l+i)=(l+j);
                  *(l+i)=t;
              }
          }
      }
                 return 0;
                 }
