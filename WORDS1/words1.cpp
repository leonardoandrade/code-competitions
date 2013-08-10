#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>



#define ALPHABET_SIZE 26
#define MAX_WORD_SIZE 1024


int partitions[ALPHABET_SIZE];

void print_degrees(int in[ALPHABET_SIZE], int out[ALPHABET_SIZE])
{
    for(int i=0;i<ALPHABET_SIZE;i++)
    {
        printf("%c-->%d %d (%d)\n",i+97,in[i],out[i], partitions[i]);
    }
}

void print_partition()
{
    for(int i=0;i<ALPHABET_SIZE;i++)
    {
        printf("%c-->%d \n",i+97, partitions[i]);
    } 
}

void update_partition(int old, int niu)
{
    for(int i=0;i<ALPHABET_SIZE;i++)
    {
       if(partitions[i]==old)
       {
            partitions[i]=niu;
       }
    }  
}

int count_partitions()
{
    int max=-1;
    for(int i=0;i<ALPHABET_SIZE;i++)
    {
        if(partitions[i]>max)
        {
            max=partitions[i]; 
        }
    }
    return max;
}

void set_partition(int first,int  last)
{
    int max=-1;
    for(int i=0;i<ALPHABET_SIZE;i++)
    {
        if(partitions[i]>max)
        {
            max=partitions[i]; 
        }
    }
    if(max==-1)
    {
        partitions[first]=0;
        partitions[last]=0;
    }
    else
    {   
        //new partition
        if(partitions[first]==partitions[last] && partitions[first]==-1)
        {
            partitions[first]=max+1;
            partitions[last]=max+1;
        }
        //partition already exists
        else if(partitions[first]==partitions[last])
        {
            return;
        }
        else if(partitions[first]==-1)
        {
            partitions[first]=partitions[last];
        }
        else if(partitions[last]==-1)
        {
            partitions[last]=partitions[first];
        }
        else if(partitions[first]!=partitions[last])
        {
            if(partitions[first]>partitions[last])
            {
                update_partition(partitions[first],partitions[last]);
            }
            else
            {
               update_partition(partitions[last],partitions[first]); 
            }
        }
    }
  
}

int main()
{
	int ncases;
	scanf("%d",&ncases);
	for(int i=0; i< ncases; i++)
	{
	
	        
        int in_degrees[ALPHABET_SIZE];
        int out_degrees[ALPHABET_SIZE];
    
    
        for(int i=0; i<ALPHABET_SIZE;i++)
        {
            in_degrees[i]=0;
            out_degrees[i]=0;
            partitions[i]=-1;
        }

	
	  
        int nwords;
	    
	    scanf("%d",&nwords);
	    for(int j=0;j<nwords;j++)
	    {
	        char tmp_word[MAX_WORD_SIZE];
            scanf("%s",tmp_word);
            
            int first_letter = tmp_word[0]-97;
            int last_letter  = tmp_word[(int)(strlen(tmp_word)-1)]-97;
            in_degrees[first_letter]++;
            out_degrees[last_letter]++;
            
            set_partition(first_letter, last_letter);
	    }
	    //print_partition();
	    int unmatched=0;
	    
        for(int j=0; j<ALPHABET_SIZE; j++)
        {
            if(abs(in_degrees[j]-out_degrees[j])==1)
            {
                unmatched++;
            }
            else if(abs(in_degrees[j]-out_degrees[j])>1) 
            {
               unmatched=99;
            }
        }
        
        
        
        //print_degrees(in_degrees, out_degrees);

        if(unmatched<=2 && count_partitions()==0)
        {
            printf("Ordering is possible.\n");    
        }
        else
        {
            printf("The door cannot be opened.\n");
        }
	}
	
	
}
