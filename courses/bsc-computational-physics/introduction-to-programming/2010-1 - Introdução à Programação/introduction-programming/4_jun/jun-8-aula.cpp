#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
//EX. 01 - IMPLEMENTAR UMA FUNÇÃO P/ EFETUAR BUSCA COM SENTINELA EM UM VETOR DE INTEIROS

void criar(int v[100]){
        int i=0;
        for (;i<100;i++)
            v[i]= rand()% 10;
}

void imprimir(int v[100]){
    int i=0;
    for(;i<100; i++)
        printf("%d\n  ", v[i]);
}

int busca(int v[100],int n){
    int achou, i=0, indice;
    for(;i<100; i++){
        if(v[i]==n){
        printf("%d\n ", i);
        indice = i;
        i=101;
    }
    }
    return(indice);
}

int main(){
    int vetor[100], numero;
    criar(vetor);
    imprimir(vetor);
    scanf("%d", &numero);
    printf("\n%d", busca(vetor, numero));
    system ("pause");
}
