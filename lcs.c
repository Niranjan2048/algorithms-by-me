#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

void calculatelcs(char *argv[]);
void input();
char *x, *y;
unsigned **store, xlength=0, ylength=0;

int main(int argc, char * argv[])
{
    int i;


    if(argv[1] && argv[2])
    {
        xlength=strlen(argv[1]);
        ylength=strlen(argv[2]);

        store=(unsigned **)malloc((xlength+1)*sizeof(unsigned *));
        for(i=0;i<=xlength;i++)
            store[i]=(unsigned *)malloc(sizeof(unsigned)*(ylength+1));
        for(i=0;i<=ylength;i++)
            store[0][i]=0;
        for(i=0;i<=xlength;i++)
            store[i][0]=0;

        calculatelcs(argv);
    }
    else
        printf("\n\t At least one of thee strings empty\n");

  return 0;
}

void calculatelcs(char *argv[])
{
    char * lcsstring;
    unsigned i,j,lcslength;
    for(i=1;i<=xlength;i++)
    {
        for(j=1;j<=ylength;j++)
        {
            if(argv[1][i-1]==argv[2][j-1])
                store[i][j]=store[i-1][j-1]+1;
            else
                store[i][j]=store[i][j-1]> store[i-1][j]? store[i][j-1]:store[i-1][j];
            printf("%u ", store[i][j]);
        }
        printf("\n");
    }

    lcslength=store[xlength][ylength]; i=xlength;j=ylength;
    if(lcslength>0)
    {
        printf("LCS of %s and %s is of length %u and is = ", argv[1], argv[2], lcslength);
        lcsstring=(char*)malloc(sizeof(char)*lcslength);
        lcsstring[lcslength]='\0';
        while(lcslength>0)
        {
            if((store[i][j]> store[i][j-1]) && (store[i][j]> store[i-1][j]))
            {
                lcsstring[lcslength-1]=argv[1][i-1];
                lcslength--;
                i--;j--;
            }
            else
                if(store[i-1][j]> store[i][j-1])
                    i--;
                else
                    j--;
        }
        printf(" %s \n\n", lcsstring);
    }
    else
        printf("\n\tNo common subsequence\n");
}


