#include<stdio.h>
#include<malloc.h>

#define INF ~(1<<(sizeof(int)*8-1))
#define FILENAME "sssp1.txt"

char * closed;
int *d=NULL;
int *parent=NULL;
int n, tentativeparent;
char preparation();
void rundijkstra();
void findv2bclosed();
void reestimate(int);
int **G;
int v2bclosed;

int main()
{
    printf("largest integer= INFINITY= %d \n\n", INF);
   if(preparation())
        rundijkstra();
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
    if(G==NULL)
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
            d=(int*)malloc(n*sizeof(int));
            closed=(char*)malloc(n*sizeof(char));
            parent=(int*)malloc(n*sizeof(int));
            if(d && closed && parent)  // currently distance to source is known and others are not finalized
            {
                closed[0]=0;
                d[0]=0;
                parent[0]=0;
                for(i=1;i<n;i++)
                {
                     d[i]= INF;
                     closed[i]=0;
                }
            }
            else
                return 0;

            return 1;
            }

}

void rundijkstra()
{
    int count=0,i,k;
    while(count<n)
    {
        findv2bclosed();  // it set value of v2bclosed to recently found vertex to be closed for inspection
        closed[v2bclosed]=1;
        count++;
        printf("\nshortest path to %d finalized ", v2bclosed);
        reestimate(v2bclosed);
    }
    printf("\n\n");
    for(i=1;i<n;i++)
        printf("\tShortest Path cost from source=0 to %d= %d\n", i, d[i]);
    for(i=1;i<n;i++)
    {
            k=i;
            printf("\n the backward shortest path from 0 to %d is :- %d ", i, i);
            while(k!= parent[k])
            {
                printf("%d ", parent[k]);
                k=parent[k];
            }
    }
    printf("\n");
}

void findv2bclosed()
{
    int mindistance,i,j;
    mindistance=INF;

        for(i=0;i<n;i++)
        {
            if(closed[i]==0)
            {
                if( d[i] < mindistance)
                {
                    v2bclosed=i;
                    mindistance=d[i];
                }
            }
        }
}

void reestimate(int v)
{
    int i,j, currentestimate;
    printf("\n\tdistance array= ");
    for(j=1;j<n;j++)
    {
        if((closed[j]==0)&& (G[v][j]!=INF) )
        {
            currentestimate=d[v]+G[v][j];
            if(currentestimate < d[j] )
            {
                d[j]=currentestimate;
                parent[j]=v;
            }
        }
        printf("%d ", d[j]);
    }
}
