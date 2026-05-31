#include<stdio.h>
#include<conio.h>
#include<math.h>

main(){
       float b=0;
       int e=0;
       float r=0;
       
       printf("Entre com a base: ");
       scanf("%f",&b);
       printf("Entre com o expoente: ");
       scanf("%d",&e);
       
       r=pow(b,e);
       printf("\n%.2f", r);     
       
              
       
       
       getch();
       }
