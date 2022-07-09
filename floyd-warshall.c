#include<stdio.h>
#include<malloc.h>

#define INF ~(1<<(sizeof(int)*8-1))
#define FILENAME "floydinput.txt"

int n;
char preparation();
void runfw();
int **G, **distance;

int main()
{
    printf("largest integer= INFINITY= %d \n\n", INF);
   if(preparation())
        runfw();
    else
        printf("Memory insufficient\n\n");
  return 0;
}

char preparation()
{
    int i,j;
    FILE *filename=fopen(FILENAME, "r");
    fscanf(filename, "%d", &n);
    printf("Number of vertices=%d\n\n", n);
    printf("Source vertex is 0..other vertices are ");
    for(i=1;i<n;i++)
        printf(", %d", i);
    printf("\n");

    G=(int**) malloc(n*sizeof(int*));

    if(G== NULL)
        return 0;
    else
    {
            for(printf("Input graph is:-\n"),i=0;i<n;i++)  // input graph from a file ..
            {
                G[i]=(int*)malloc(n*sizeof(int));
                if(G[i]==NULL)
                    return 0;
                else
                {
                    for(j=0;j<n;j++)
                    {
                        fscanf(filename, "%d", &G[i][j]);
                        printf("%13d ", G[i][j]);
                    }
                    printf("\n");
                }
            }
            printf("\n\n");
            fclose(filename);
            return 1;
            }
}

void runfw()
{
    int i,j,k;
    distance=(int**) malloc(n*sizeof(int*));
    for(i=0;i<n;i++)                            //copying adjacency matrix into another matrix which is going to be final distance matrix
    {
        distance[i]=(int*)malloc(n*sizeof(int));
        for(j=0;j<n;j++)
            distance[i][j]=G[i][j];
    }

    for(k=0;k<n;k++)                // core Floyd-Warshall algorithm at work
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
               if((i!=j) && (distance[i][k]!=INF) && (distance[k][j]!=INF))
                if( distance[i][j] > (distance[i][k]+distance[k][j]) )
                {
                    distance[i][j]=distance[i][k]+distance[k][j];
                }
            }
    printf("\n\nShortest cost matrix is\n\n");  //printing the shortest cost matrix for all pairs
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%13d ",distance[i][j]);
        printf("\n");
    }
}
