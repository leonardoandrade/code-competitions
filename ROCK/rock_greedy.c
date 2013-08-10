#include<stdio.h>
int main()
{
    int t,i,j,k,temp,n,count,len;
    char s[201],arr[201][201]={0};
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",s);
        for(i=1;i<=n;i++)
        {
            for(j=i;j<=n;j++)
            {
                count=0;
                for(k=i-1;k<=j-1;k++)
                   if(s[k]=='1')
                        count++;
                len=j-i+1;
                if(count>len-count)
                    arr[i][j]=len;
                else
                    arr[i][j]=count;
            }
        }
        for(j=4;j<=n;j++)
        {
            for(i=1;i<=n-j+1;i++)
            {

               for(k=i;k<j+i-1;k++)
               {
                   temp=arr[i][k]+arr[k+1][j+i-1];
                   if(arr[i][j+i-1]<temp)
                   arr[i][i+j-1]=temp;
               }
       
       
            }
        }
    /*for(i=1;i<=n;i++)
    {
    for(j=1;j<=n;j++)
    {
    if(i<=j)printf("%d ",arr[i][j]);
    else printf("  ");}printf("\n");
    }*/
        
        printf("%d\n",arr[1][n]);
    }
    return 0;
}
