#include<stdio.h>
#include<conio.h>


int soma(int *v, int tam){
    int soma=0;
    
    for(int i=0; i<tam; i++)
    soma=soma+v[i];
    
    return(soma);
    
    
    }

main(){
       
       int vet[10]={1,2,3,4,5,6,7,8,9,10};
       printf("A soma dos elementos do vetor e: %d", soma(vet,10));
       
       getch();
       
       
       
       
       }
