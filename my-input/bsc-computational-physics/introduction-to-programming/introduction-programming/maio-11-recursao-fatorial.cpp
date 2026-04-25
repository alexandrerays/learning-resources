#include<stdio.h>
#include<stdlib.h>

int fat(int n){
    if(n==0)
            return(1); //criterio de parada
    else
            return(n*fat(n-1));  // chamada recursiva //chamada da funcao dentro dela mesma            
    
    }
    
    
main(){
       int num,y;
       
       printf("escolha um numero\n");
       scanf("%d", &num);
       
       y=fat(num);
       
       printf("%d\n", y);
       
       system("pause");
       
       
       }
