#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void preencher_matriz(int **m, int l, int c){    
     for(int i=0; i<l; i++)
     for(int j=0; j<c; j++)
     m[i][j]=(rand()%10);
     }
     
int imprimir_matriz(int **m, int l, int c){
    for(int i=0; i<l; i++){
    printf("\n");
    for(int j=0; j<c; j++)
    printf("%d ", m[i][j]);    
    }    
    }    
    
int preencher_vetor(int *v, int t){
    for(int i=0; i<t; i++)
    v[i]=(rand()%10);
    }
    
int imprimir_vetor(int *v, int t){
    printf("\n");
    for(int i=0; i<t; i++)
    printf("%d ", v[i]);   
    }
    

/*int verifica(int **m, int *v, int l, int c, int t){
     for(int i=0; i<l; i++)
     for(int j=0; j<c; j++){
             for(int s=0; s<t; s++)
             if(m[i][j]==v[s])
             printf(m[i][j]);
             
             }
     
     
     
     }*/


main(){
       //VETOR 
       int *vet;
       int n=0;
       
       //MATRIZ
       int **mat;
       int linhas=0;
       int colunas=0;
       
       printf("linhas: ");scanf("%d", &linhas);
       printf("colunas: ");scanf("%d", &colunas);
       
       //aloca espaço para as linhas
       mat=(int**)malloc(linhas*sizeof(int*));
       
       //aloca espaço para as colunas
       for(int i=0; i<linhas; i++)
       mat[i]=(int*)malloc(colunas*sizeof(int));      
       
  
       preencher_matriz(mat,linhas,colunas);
       imprimir_matriz(mat,linhas,colunas);
       
       printf("\n\ntamanho do vetor: ");scanf("%d",&n);
       
       //aloca espaço para o vetor
       vet=(int*)malloc(n*sizeof(int));
       
       preencher_vetor(vet,n);
       imprimir_vetor(vet,n);
       
      /* printf("\n");
       verifica(mat,vet,linhas,colunas,n);*/
       
              
       
       getch();
       }
