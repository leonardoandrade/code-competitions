#include <cstdio>
#include <stdio.h>
#include <unistd.h>

	#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
	#define min( a, b ) ( ((a) < (b)) ? (a) : (b) )


#define BASE_SIEVE_SIZE 31623
#define SEGMENT_SIEVE_SIZE 100001
#define LIMIT 1000000001

//#define WORD_BITS (8 * sizeof(unsigned int))
//#define SIEVE_SIZE_BYTES ((SIEVE_SIZE/WORD_BITS)+1)


bool base_sieve[BASE_SIEVE_SIZE];
bool segment_sieve[SEGMENT_SIEVE_SIZE];

void build_segment_sieve(int first, int last)
{

	for(int i=0; i<SEGMENT_SIEVE_SIZE; i++)
		{	
		segment_sieve[i]=true;			
	}
	int next_number=1;
	while(true)
	{

		next_number++;	
		for(int i=next_number; i<BASE_SIEVE_SIZE;i++)
		{
			if(base_sieve[i]==true)
			{
				next_number=i;
				break;		
			}
			if((next_number==BASE_SIEVE_SIZE-1) || (next_number>last))
			{
				return;
			}
		}

		if((next_number*2)>last)
		{
			continue;
		}
		int initial=max(next_number*(first/next_number),(next_number*2));
		//initial=next_number+next_number;
		//printf("initial i=%d next=%d first=%d last=%d\n",initial,next_number, first, last);
		for(int i=initial;((i<=last) && (i<LIMIT));i=i+next_number)
		//for(int i=next_number*2;((i<=last) && (i<LIMIT));i=i+next_number)
		{
			//printf("burning %d\n",i);
			if((i>=first) && (i<=last))
			{
				segment_sieve[i-first]=false;
			}
		}
	}
}

void build_base_sieve()
{
	
	for(int i=0; i<BASE_SIEVE_SIZE; i++)
	{	
		base_sieve[i]=true;			
	}

	base_sieve[0]=false;
	base_sieve[1]=false;
	
	int next_number=1;
	while(true)
	{
	
		int old_next_number=next_number;	
		for(int i=next_number+1; i<BASE_SIEVE_SIZE;i++)
		{
			if(base_sieve[i]==true)
			{
				next_number=i;
				break;		
			}
		}
		//printf("nn=%d\n",next_number);
		if(old_next_number==next_number)
		{
			//printf("break at nn=%d\n",next_number);
			break;
		}
		for(int i=next_number+next_number;i<BASE_SIEVE_SIZE;i=i+next_number)
		{
			//printf("i=%d\n",i);
			if(i<BASE_SIEVE_SIZE)
			{
				base_sieve[i]=false;
			}
		}
	}
	//sleep(10);
}

void print_sieve(int first, int last)
{
	return;
	printf("base sieve:\n");	
	for(int i=0; i<BASE_SIEVE_SIZE && i<=last;i++)
	{
		printf("%d %d\n",i,base_sieve[i]);
	}

	printf("\n\nsegment sieve:\n");
	for(int i=first; i<SEGMENT_SIEVE_SIZE && i<=last;i++)
	{
		printf("%d %d\n",i,segment_sieve[i-first]);
	}
	
}

int main()
{
//	printf("word_bits=%d, vector_size=%d\n",WORD_BITS,(SIEVE_SIZE/WORD_BITS)+1);
	
	build_base_sieve();
	//sleep(10);
	//print_sieve();
	int nlines,i;
	
	scanf("%d",&nlines);
	//printf("number lines: %d\n",nlines);
	for(i=0; i<nlines;i++)
	{
		int first, last;
		scanf("%d %d", &first, &last);
		int j;
		build_segment_sieve(first, last);
		print_sieve(first, last);
		for(j=first; j<last+1; j++)
		{
			if(segment_sieve[j-first]==true && j!=1)
			{
				printf("%d\n",j);
			}
		}
		printf("\n");
	}
}
