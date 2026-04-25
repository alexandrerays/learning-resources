#include<stdio.h>
#include<stdlib.h>

//funcao que calculo o quadrado de num
int calculo(int x)
{     
printf("o quadrado de num e: %d\n",(x*x));
return(0);
}
           
main(){
       //variavel
       int num;
       
       //entrada
       printf("entre com num\n");
       scanf("%d", &num);
       
       //chamando a função
       calculo(num);
       
       system("pause");       
       }
           
       
       
       
