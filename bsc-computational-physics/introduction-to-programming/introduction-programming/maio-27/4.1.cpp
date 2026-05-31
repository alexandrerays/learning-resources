#include<stdio.h>
#include<conio.h>
//PREENCHE VETOR DINAMICAMENTE E CALCULA A SOMA ENTRE OS ELEMENTOS DO VETOR

int preenche_vetor(int *v, int qtde){    
    for(int i=0; i<qtde; i++)
    v[i]=(rand()%10);            
    }

int imprime_vetor(int *v, int qtde){
    for(int i=0; i<qtde; i++)
    printf("%d ", v[i]);    
    }
    
int soma(int *v, int n){
    int soma=0;
    for(int i=0; i<n; i++){
    soma=soma+v[i];                  
            }  
    printf("\nA soma total e: %d ", soma);
    }

main(){       
       int *vet;
       int n=0;
       
       printf("Entre com a qtde de elementos do vetor: ");
       scanf("%d",&n);
       
       vet=(int*)malloc(n*sizeof(int));  
       
       preenche_vetor(vet, n);
       imprime_vetor(vet,n); 
       soma(vet,n);  

       getch();
       }
