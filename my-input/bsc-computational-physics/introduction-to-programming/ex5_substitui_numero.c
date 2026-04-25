/* Substitui um número escolhido em uma posição escolhida */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[10] = {10,9,72,8,18,2,98,56,82};
    int posicao, num;
    int i=0;

    printf("Vetor original:\n");
    for(i=0; i<10; i++) {
        printf("[%d]=%d ", i, a[i]);
    }   

    printf("\n\nEscolha o numero usada na substituicao: ");
    scanf("%d",&num);
    printf("Escoha uma posicao para substituir: ");
    scanf("%d", &posicao);

    for(i=0; i<10; i++) {
        a[posicao+1]=a[posicao];
        a[posicao]=num;
    }        
    printf("\nNovo vetor:\n");
    for(i=0; i<10; i++) {
        printf("[%d]=%d ", i, a[i]);
    }        
    printf("\n");
}
