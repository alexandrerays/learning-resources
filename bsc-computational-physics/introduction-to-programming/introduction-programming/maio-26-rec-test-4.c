#include<stdio.h>
#include<stdlib.h>

int prod(int a,int b){
    if(a==0 || b==0)
      return 0;
    else
      if(b==1)
       return a;
      else
       return a+prod(a,b-1);
    }

main(){
    int a,b,x;
    puts("digite o valor 1");
    scanf("%d",&a);
    puts("digite o valor 2");
    scanf("%d",&b);
    x=prod(a,b);
    printf("o produto eh\n%d \n",x);
    system("pause");
       }
