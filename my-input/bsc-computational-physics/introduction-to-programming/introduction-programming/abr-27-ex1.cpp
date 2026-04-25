#include<stdio.h>
#include<stdlib.h>

main(){
       //variaveis
       int a[10]={1,2,3,4,5,6,7,8,9};
       int posicao, num;
       int i=0;
       
       //entrada de dados
       printf("escolha um numero para substituir\n");
       scanf("%d",&num);
       printf("escoha uma posicao para substituir\n");
       scanf("%d", &posicao);
       
       //processamento
       for(i=0; i<10; i++)
                a[posicao+1]=a[posicao];
                a[posicao]=num;
       for(i=0; i<10; i++)
                printf("%d", a[i]);
                
                         
       system("pause");
       
       
       
       
       }
