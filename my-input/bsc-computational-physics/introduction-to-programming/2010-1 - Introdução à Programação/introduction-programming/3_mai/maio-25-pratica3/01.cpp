#include<stdio.h>
#include<stdlib.h>
//A FUNCAO TROCA O CONTEUDO DE DUAS VARIAVEIS
int troca(int *n1, int *n2){        
    int temp=*n1;
    *n1 = *n2;
    *n2 = temp;    
    //printf("a = %d\nb = %d\n", *n1, *n2);  
    }

main(){     
       int a=0;
       int b=0;     
       
       printf("entre com a: ");
       scanf("%d", &a);
       printf("entre com b: ");
       scanf("%d", &b);
       
       troca(&a,&b);        
       printf("a = %d\nb = %d\n", a, b);       
       system("pause");   
       
       }
