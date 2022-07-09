#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define FILENAME "priminputgraph.txt"

const char* message[]={
                    "largest int= %d represents infinity and absence of edge between i and j of G[i][j] is this value\n",
                    "\nEnter the number of vertices: ",
                    ">2 vertices .. But Not enough memory for storing graph\n\n",
                    "\nVertex set for the graph is V={",
                    " }\n\n",
                    "\t\t(Make sure input file is in the same directory where .c source file is)\n\n\t\t Input graph is: \n\n",
                    "\n\nEmpty graph with ZERO vertices\n",
                    "\n\nTrivial graph of 1 vertex...G itself is MST \n\n"
                 };

int **G=NULL;                // maintains adjacency matrix of G as a lower triangular matrix to save space
char * mstvertexset=NULL;  // array maintaining status of vertices currently part of growing MST..1 means is in current MST.. 0 means outside
int * finaltree=NULL;      // used to print final MST
int n;

void runprim();
char inputgraph();  // reads graph and its adjacency matrix from a file. File format is explained in sample input file.

int main()
{
    printf(message[0], ~(1<<(sizeof(int)*8-1)));
    if(inputgraph())
       runprim();
    else
       printf(n>2?message[2]:"Run Again\n\n");

    return 0;
}

char inputgraph() //read the graph from input file.. make sure input file is in same directory..else full path of file needs to be given.
{
    FILE* file = fopen(FILENAME, "r");
    int i,j, rowsize;

    fscanf(file, "%d", &n);
    if(n<2)
    {
       printf(n==0?message[6]:message[7]);
       return 0;
    }
    finaltree=(int*)malloc(2*(n-1)*sizeof(int));
    G=(int **)malloc(n* sizeof(int*));

    if(G && finaltree)
    {
        for(i=0;i<n;i++)
        {
            rowsize=i+1;
            G[i]=(int *)malloc(rowsize*sizeof(int));
            if(G[i])
            {
                for(j=0;j<(rowsize-1);j++)
                {
                    fscanf(file, "%d", &G[i][j]);
                }
                G[i][j]=~(1<<(sizeof(int)*8-1));
            }
            else return 0;
        }
        for(printf(message[3]),i=0;i<n;i++)
            printf("%d, ", i);
        printf(message[4]);

        for(printf(message[5]),printf("Node/Node"), i=0;i<n;i++)
            printf("%10d ", i);
        printf("\n\n");
        for(i=0;i<n;i++)
        {
            for(printf("%10d ", i),j=0;j<=i;j++)
                printf(" %10d ", G[i][j]);
            printf("\n");
        }

        fclose(file);
        return 1;
    }
    else
        return 0;
}

void runprim()
{
    int count,i,j,cmin, cminnode, mstw=0, k=0, source=0, rowsize;

    mstvertexset=(char*)malloc(n*sizeof(char));
    for(i=1;i<n;i++)
        mstvertexset[i]=0;
    mstvertexset[0]=1;
    count=1;
        while(count<n)
        {
            cmin=  ~(1<<(sizeof(int)*8-1));  // largest possible value in an int
           for(i=0;i<n;i++)
            {
                if(mstvertexset[i]==1)
                {
                    for(j=0;j<i;j++)
                    {
                        if( (mstvertexset[j]==0) && (G[i][j] < cmin) )
                        {
                            cmin=G[i][j];
                            cminnode=j;
                            source=i;
                        }
                    }
                    for(j=i+1;j<n;j++)
                    {
                        if( (mstvertexset[j]==0) && (G[j][i] < cmin) )
                        {
                            cmin=G[j][i];
                            cminnode=j;
                            source=i;
                        }
                    }
                 }
            }
            mstvertexset[cminnode]=1;
            mstw=mstw+ cmin;
            count++;
            finaltree[k]=source; k++; finaltree[k++]=cminnode;
        }

  printf("\n\ncost of MST= %d\n\n", mstw);
  printf("MST is \n", mstw);
  for(i=0; i<k; i+=2)
    printf("{%d, %d} ", finaltree[i], finaltree[i+1]);

  printf("\n\n");
}
