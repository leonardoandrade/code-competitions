#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORDSIZE 200

int sweetlen;

void partition(char * word, int wordlen, int * partitions, int numpartitions)
{
    //computing the sweet_len size
    if(numpartitions==wordlen)
    {
        return;
    }
    int index=0;
    int tmp_sweetlen=0;
    while(index<numpartitions)
    {
        int sweetcount=0;
        int start=partitions[index];
        int end;
        if(index<(numpartitions-1))
        {
            end=partitions[index+1];
        }
        else
        {
            end=wordlen;
        }
        int i;
        for(i=start; i<end; i++)
        {
            if(word[i]=='1')
            {
                sweetcount++;
            }
            else
            {
                sweetcount--;
            }
        }
        if(sweetcount>0)
        {
           tmp_sweetlen+=(end-start);
        }
        index++;
    }
    if(tmp_sweetlen>sweetlen)
    {
        sweetlen=tmp_sweetlen;
    }
    //printf("n:%d total:%d\n", numpartitions,tmp_sweetlen);
    int i;
    
    for(i=partitions[numpartitions-1]; i<wordlen;i++)
    {
        partitions[numpartitions]=i;
        partition(word, wordlen, partitions, numpartitions+1);
    }
    //partitioning
    
}

int main()
{
    int ncases;
    scanf("%d\n",&ncases);
    while(ncases--)
    {
        sweetlen=0;
        int wordlen;
        char word[MAXWORDSIZE];
        scanf("%d\n",&wordlen);
        scanf("%s\n",word);
        
        printf("%d %s\n", (int)strlen(word), (char*)word);
        
        int partitions[MAXWORDSIZE];
        int numpartitions=2;
        partitions[0]=0;
        int i;
        for(i=0; i<wordlen; i++)
        {
            partitions[1]=i;
            partition(word,  wordlen, partitions, numpartitions);
        }
        printf("%d\n",sweetlen);
        
    }
}
