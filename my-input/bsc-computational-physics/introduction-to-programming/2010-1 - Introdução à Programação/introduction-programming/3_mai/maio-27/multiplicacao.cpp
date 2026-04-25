#include<stdio.h>
#include<conio.h>
#include<math.h>
//MULTIPLICAÇÃO ENTRE DOIS NUMEROS USANDO RECURSÃO
//A>=0 E B>=0

int produto(int A, int B){
    int y=0;
    if(A==0)
    return(1);
    else{
         y=B*produto(A-1);
         return(y);
         
         }
    
    
    }


main(){
       int a=0, b=0;
       float x=0;
       
       printf("Entre com a: "); scanf("%d",&a);
       printf("Entre com b: "); scanf("%d",&b);
       
      /* x=a*b;
       
       printf("%.2f",x);*/
       
       x=produto(a,b);
       printf("%f",x);
       

       
       getch();
       }
