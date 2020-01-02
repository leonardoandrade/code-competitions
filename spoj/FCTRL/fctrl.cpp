//fctrl.cpp
#include <stdio.h>
#include <unistd.h>
#include <math.h>



int main()
{
    int nlines;
    scanf("%d",&nlines);
	//printf("number lines: %d\n",nlines);
    int i;
	for(i=0; i<nlines;i++)
	{
		long int number;
		scanf("%ld", &number);
        long int tzeros=0;
        int count=1;
        long int partial=pow(5,count);
        while(partial<=number)
        {
            tzeros=tzeros+floor((double)number/(double)partial);
            ++count;
            partial=pow(5,count);
            //printf("count=%d number=%d partial=%d tzeros=%d\n",count,number,partial,tzeros);
        }
		printf("%ld\n",tzeros);
	}

}
