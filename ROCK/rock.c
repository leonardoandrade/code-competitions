#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORDSIZE 201

int matrix[MAXWORDSIZE][MAXWORDSIZE];
int bests[MAXWORDSIZE][MAXWORDSIZE];
int best=0;

void printmatrix(int wordlen)
{
    int i,j;
    for(i=0;i<wordlen;i++)
    {
        for(j=0;j<wordlen;j++)
        {
            printf("%d",matrix[i][j]);
        }
        printf("\n");
    }
}

void buildmatrix(char * word,  int wordlen)
{
    int i, j,k;
    for(i=0;i<wordlen+1;i++)
    {
        
        for(j=0;j<wordlen+1;j++)
        {
            int countones=0;
            for(k=i; k<j;k++)
            {
                if(word[k]=='1')
                    countones++;
                else
                    countones--;
            }
            if(countones>0)
            {
                matrix[i][j]=1;
            }
            else
            {
                matrix[i][j]=0;
            }
            bests[i][j]=-1;
           
        }
    }
}

int get_cost(int start, int end)
{
    if(matrix[start][end])
    {
        return end-start;
    }
    if(bests[start][end]!=-1)
    {
        return bests[start][end];
    }
    
    else
    {
        int partial_best=0;
        int x, tmp;
        for(x=start; x<end;x++)
        {
            tmp=get_cost(start, x)+get_cost(x+1,end);
            if(tmp>partial_best)
            {
                partial_best=tmp;
            }
        }
        bests[start][end]=partial_best;
        return partial_best;
    }
}

int main()
{
    int ncases;
    scanf("%d\n",&ncases);
    while(ncases--)
    {
        best=0;
        int wordlen;
        char word[MAXWORDSIZE];
        scanf("%d\n",&wordlen);
        scanf("%s\n",word);

        buildmatrix(word,wordlen);

        //printmatrix(wordlen); 
        printf("%d\n",get_cost(0,wordlen));
        
    }
}
