#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

    int number;
    while(1)
    {
        scanf("%d",&number);
        if(number==0 || number > 100)
        {
            exit(0);
        }
	    int total=0;
	    int i;
	    for(i=1; i<=number;i++)
	    {
	        total=total+(i*i);
	    }
	    printf("%d\n",total);
	    
    }
}
