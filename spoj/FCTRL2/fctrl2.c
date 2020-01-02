
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>

int MAX_DIGITS=500;

char * factorial(int f)
{
    //printf("computing factoria for %d\n",f);

    int ret[MAX_DIGITS];
    int i;
    //padding the array
    for(i=0; i<MAX_DIGITS; i++)
    {
        ret[i]=0;
    }
    
    //placing one digit per index
    int count=0;
    int j, digit;
    ret[MAX_DIGITS-1]=1;
    for(i=2;i<=f;i++)
    {
        int rem, digit;
        rem=0;
        for(j=MAX_DIGITS-1;j>=0;j--)
        {
           digit=ret[j]*i+rem;
           rem=0;
           if(digit <= 9)
           {
               ret[j]=digit;
               
           }
           else
           {
               ret[j]=digit%10;
               rem=digit/10;
           }
        }
    }
    int k;
    
    //remove trailing zeros
    int flag=0;
    for(k=0;k<MAX_DIGITS;k++)
    {
        if(ret[k]!=0 || flag==1)
        {
            printf("%d",ret[k]);
            flag=1;
        }
    }
    printf("\n");
    return "boda";

}

int main()
{

    struct timeval startTime;
    struct timeval endTime;

    gettimeofday(&startTime, NULL);
    int nlines;
    scanf("%d",&nlines);
	//printf("number lines: %d\n",nlines);
    int i;
	for(i=0; i<nlines;i++)
	{
		int number;
		scanf("%d", &number);
		char * fact=factorial(number);
		//printf("%s\n",fact);
	}
	
	gettimeofday(&endTime, NULL);
    double tS = startTime.tv_sec*1000000 + (startTime.tv_usec);
    double tE = endTime.tv_sec*1000000  + (endTime.tv_usec);
    //printf("total time taken  %G usec\n",(tE-tS)/1000000);
}
    
    
