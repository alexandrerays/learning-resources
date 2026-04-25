#include<stdio.h>
#include<stdlib.h>

//remove todos os elementos nulos de um vetor de n inteiros

int removezeros(int v[], int n){
    int i=0, j=0;
    for(j=0;j<n;j++)
                    if(v[j]!=0){
                                v[i]=v[j];
                                i+=1;
                                }
    return(i);    
    }
    
main(){
       int qtde=0;
       int vetor[100];
       printf("entre com qtde\n");
       scanf("%d", &qtde);
       
       removezeros(vetor, qtde);
       
       system("pause");
       
       }
