#include<iostream>  
#include<cstdio>  
using namespace std;  
void radix(int t){  
    if(t){  
        radix((t-1)/26);  
        putchar(65+(t-1)%26);  
    }  
}  
int main(){  
    int n,x,y;  
    char str[20],*p;  
    scanf("%d ",&n);  
    while(n--){  
        gets(str);  
        if(sscanf(str,"%*c%d%*c%d",&x,&y)==2){  
            radix(y);  
            printf("%d\n",x);  
        }  
        else  
        {  
            for(x=0,p=str;*p>64;p++)  
            {  
                x=x*26+*p-64;  
            }  
            printf("R%sC%d\n",p,x);  
        }  
    }  
    return 0;  
}  