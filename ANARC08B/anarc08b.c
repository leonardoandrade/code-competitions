#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define DIGITS 10
#define CALC_SIZE 1000
char * binary_numbers[DIGITS];//{"1011111","","","","","","","","",""};
char  decimal_numbers_str[DIGITS][4];
int decimal_numbers_int[DIGITS];

void build_arrays()
{
    //printf("1\n");
    int i;
    for( i=0; i<DIGITS; i++)
    {
        int number_int=(int)strtol(binary_numbers[i],NULL,2);
        decimal_numbers_int[i]=number_int;
        char  s[4];
        if(number_int < 10)
        {
          sprintf(decimal_numbers_str[i],"00%d\0",number_int);
          
        }
        else if(number_int < 100)
        {
           sprintf(decimal_numbers_str[i],"0%d\0",number_int);
        }
        else
        {
          sprintf(decimal_numbers_str[i],"%d\0",number_int);  
        }
        
       
    
    }
    //printf("2\n");
}

void print_arrays()
{
    int i;
     for( i=0; i<DIGITS; i++)
    {
        printf("%d-> %s %d %s\n", i, binary_numbers[i], decimal_numbers_int[i], decimal_numbers_str[i]);
    }
}

int get_digit(char * s)
{   
    int i;
    for( i=0; i<DIGITS; i++)
    {
        if(strcmp(s,decimal_numbers_str[i])==0)
        {
            return i;
        }
    }
}

int get_int(char * s)
{
    char n[CALC_SIZE];
    memset(n,'\0',CALC_SIZE);
    int k=0, i;
    for( i=0; i<(strlen(s)); i+=3)
    {
        char ddd[4];
        ddd[0]=s[i];
        ddd[1]=s[i+1];
        ddd[2]=s[i+2];
        ddd[3]='\0';
        n[k]=(char)get_digit(ddd)+48;
        //printf("  ddd=%s\n",ddd);
        k++;
    }
    //printf("n=%s\n",n);
    return atoi(n);
}
char ret[CALC_SIZE];
char * get_digits(int n)
{
   
    char number[CALC_SIZE];
    memset(ret,'\0',CALC_SIZE);
    memset(number,'\0',CALC_SIZE);
   
    
    sprintf(number,"%d\0",n);
    int c=0, i;  
    for(i=0; i<strlen(number); i++)
    {
        ret[c]  =decimal_numbers_str[(int)number[i]-48][0];
        ret[c+1]=decimal_numbers_str[(int)number[i]-48][1];
        ret[c+2]=decimal_numbers_str[(int)number[i]-48][2];
        c=c+3;
    }
    return ret;
}

int main()
{
    binary_numbers[0]=(char*)"0111111";
    binary_numbers[1]=(char*)"0001010";
    binary_numbers[2]=(char*)"1011101";
    binary_numbers[3]=(char*)"1001111";
    binary_numbers[4]=(char*)"1101010";
    binary_numbers[5]=(char*)"1100111";
    binary_numbers[6]=(char*)"1110111";
    binary_numbers[7]=(char*)"0001011";
    binary_numbers[8]=(char*)"1111111";
    binary_numbers[9]=(char*)"1101011";
    build_arrays();
    //print_arrays();
    
    while(1)
    {
        char calc[CALC_SIZE];
        memset(calc,'\0',CALC_SIZE);
        scanf("%s",calc);
        if(strcmp(calc,"BYE")==0)
        {
            return 0;
        }
        char number1[CALC_SIZE];
        char number2[CALC_SIZE];
        memset(number1,'\0',CALC_SIZE);
        memset(number2,'\0',CALC_SIZE);
        int count=0;
        while(1)
        {
            char c = calc[count];
            if(c=='+')   
                break;    
            
            number1[count]=calc[count];           
            count++;
        }
        count++;
        int count_n=0;
        while(1){
            char c = calc[count]; 
            if(c=='=')   
               break;    
            number2[count_n]=calc[count];
            count_n++; count++;    
        }
        
        
        
        //printf("number1=%s, get_int(number1)=%d\n",number1, get_int(number1));
        //printf("number2=%s, get_int(number2)=%d\n",number2, get_int(number2));
        //printf("\n\n");

        int total=get_int(number1)+get_int(number2);
        printf("%s%s\n", calc, get_digits(total));
        
        
        //printf("number 1=%s number2=%s\n",number1, number2);       
               
               
    }
}
