#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//#define n 2
          
             
void preencher_matriz(int **matriz, int lc){
     for(int i=0; i<lc; i++)
     for(int j=0; j<lc; j++)
     matriz[i][j]=(rand()%10);  
     
     
     }
     
     
void imprimir_matriz(int **matriz, int lc){
      for(int i=0; i<lc; i++)
     for(int j=0; j<lc; j++)
     printf("%d ", matriz[i][j]);  
     
     
     } 





main(){
       int **mat;
       int n;
       
       mat=(int**)malloc(n*sizeof(int*));
       
       preencher_matriz(mat,n);       

       
       getch();
       }
