#include<stdio.h>
#include<conio.h>
#include<math.h>

main(){
       int v[5];
       int x=0;
       int mult=0;
       
       for(int i=0; i<=4; i++){
               printf("Entre com a0, a1, a2, a3, a4: ");
               scanf("%d ", v[i]);        
               
               }
               
       printf("Entre com o valor de x: ");
       scanf("%d ", &x);
       
       for(int j=0; j<=4; j++){
               mult=v[j]*x;
               printf("%d ", mult);
               }
       getch();
       
       
       }
