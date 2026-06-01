#include<stdio.h>
#include<stdlib.h>

float rdr(float b,int e){
    if(e==0)
      return 1;
    else
    return (b*rdr(b,e-1));
    }

main(){
    float b,x;
    int e;
    puts("digite a base");
    scanf("%f",&b);
    puts("digite o expoente");
    scanf("%d",&e);
    x=rdr(b,e);
    printf("%f \n",x);
    system("pause");
       }
