#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define sz 205  
struct data{  
 int one,zero;  
}a[sz];  
  
char s[sz];  
int n,ans[sz];  
bool isSoll[sz][sz];  
  
int max(int a,int b){  
 if(a>b)  
  return a;  
 return b;  
}  
  
bool isSol(int f, int t){  
 if(a[t].one - a[f-1].one > a[t].zero - a[f-1].zero)  
  return true;  
 return false;  
}  
int f(int i)  
{  
  
  int best = 0;  
  if(i>n)  
   return 0;  
  if(ans[i] != -1)  
   return ans[i];  
  for( int j=n;j>=i;j--)  
    if(isSoll[i][j])  
      best = max(best, j-i+1+f(j+1));  
  ans[i] = best = max(best, f(i+1)); // don't include this piece  
  return best;  
}  
  
void init(){  
 int i,j;  
 for(i=1;s[i-1];i++){  
  a[i] = a[i-1];  
  (s[i-1] == '1')?a[i].one++ : a[i].zero++;  
 }  
 for(i=1;i<=n;i++){  
  ans[i] = -1;  
  for(j=i;j<=n;j++){  
   isSoll[i][j] = isSol(i,j);  
  }  
 }  
  
}  
  
int main(){  
 int i,j,k,l,t;  
  
 //freopen("i.txt","r",stdin);  
 scanf("%d",&t);  
 while(t--){  
  scanf("%d",&n);  
  scanf("%s",s);  
  init();  
  printf("%d\n",f(1));  
 }  
  
 return 0;  
}  
