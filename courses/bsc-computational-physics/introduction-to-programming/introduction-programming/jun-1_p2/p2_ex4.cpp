#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define n 3 //linhas
#define m 3 //colunas

void le_matriz(int **matriz, int lin, int col){
     
     for(int i=0; i<lin; i++)
         for(int j=0; j<col; j++)
             scanf("%d",&matriz[i][j]);  
     
     }
     
void imprimir_matriz(int **matriz, int lin, int col){
     
     for(int i=0; i<lin; i++){
                   printf("\n");
                                 for(int j=0; j<col; j++)
                                          printf("%d ",matriz[i][j]);
                }
     }

main(){
       
       int **mat;
       int i,j;
       
       //aloca linhas
       mat=(int**)malloc(n*sizeof(int*));
       
       //aloca colunas
       for(i=0; i<m; i++)
       mat[i]=(int*)malloc(m*sizeof(int));
       
       le_matriz(mat,n,m);
       imprimir_matriz(mat,n,m);
       
       
       getch();
       }
