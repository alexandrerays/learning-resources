#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


void preenche_matriz(int *m[][],int l, int c){
    
    for(int i=0; i<l; i++)
            for(int j=0; j<c; j++)
                    m[i][j]=(rand()%10);
    
    }


main(){
       
       
       int mat[][];
       
       
       linhas=0;
       colunas=0;       

       
       printf("Entre com a quantidade de linhas");
       scanf("%d", &linhas);
       printf("Entre com a quantidade de colunas");
       scanf("%d", &colunas);
       
       
       preenche_matriz(mat,linhas,colunas);
       
       
       getch();
       }
