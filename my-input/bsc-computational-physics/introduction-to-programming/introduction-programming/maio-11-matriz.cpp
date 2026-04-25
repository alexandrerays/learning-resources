#include<stdio.h>
#include<stdlib.h>


void imprime_matriz (int mat[][10],int x,int y)
{
   int i,j;
   for (i=0;i<x;i++){
       for(j=0;j<y;j++)
         printf("%d    ",mat[i][j]);
        printf("\n");
       
         }
}        
   
/*
void le_matriz(int mat[][m],int n,int m){
     int i,j;
     for(i=0;i<n;i++)
      for(j=0;j<y;j++){
        printf("Digite um numero (%d %d):" ,i,j);
        scanf("%d" &mat [i][j]);
        }
*/
main(){
    int m[10][10];
    int *pi;
    int i,j,a,n,soma=0;
    for (i=0;i<10;i++)
       for (j=0;j<10;j++){
           m[i][j]=i+j;
           }    
    imprime_matriz(m,10,10);
    
    
    pi=(int*)malloc(100*sizeof(int));
    for (i=0;i<10;i++){
        //*pi=m[i][j];    
        //soma=soma+(*pi);
        soma=soma+m[i][i];
        }
        printf("%d\n\n" ,soma);
        system("pause"); 
            
}
