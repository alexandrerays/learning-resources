#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//o programa faz uma matriz
//o usuario escolha: qtd de linhas e colunas e os valores da matriz

main(){
       int matriz[][];
       int qtd_linhas=0;
       int qtd_colunas=0;
       
       printf("entre com a quantidade de linhas");
       scanf("%d", &qtd_linhas);
       printf("entre com a quantidade de colunas");
       scanf("%d", &qtd_colunas);
       
       
       for(int i=0;i<qtd_linhas;i++)
               for(int j=0; j<qtd_colunas; j++)
               {
                       printf("entre com os valores da matriz: ");
                       scanf("%d", &matriz[i][j]);
                       }
       
       
       for(int i=0;i<qtd_linhas;i++)
       {
               for(int j=0; j<qtd_colunas; j++)
               {
                       printf("%d ", matriz[i][j]);
                       }   
                       
       printf("\n")                
       }           
             
       
       
       
       
       system("pause");
       }
