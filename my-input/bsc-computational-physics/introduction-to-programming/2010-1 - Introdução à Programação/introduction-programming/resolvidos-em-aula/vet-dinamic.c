#include <stdio.h>
#include <stdlib.h>

void soma(int *v,int n)
{
    int i,soma=0;

    for(i=0;i<n;i++) {
        soma += v[i];
    }

    printf("\nA soma e: %d\n\n",soma);
}

void preenche_vetor(int *v,int n)
{
    int i;

    for(i=0;i<n;i++) {
        v[i] = (rand()%10);
    }
}

void imprime_vetor(int *v,int n)
{
    int i;

    for(i=0;i<n;i++) {
        printf("\nvet[%d] = %d",i,v[i]);
    }
}

int main()
{
    int *vet;
    int n,i;

    printf("\nDigite o numero de elementos do vetor: ");
    scanf("%d",&n);

    vet = (int*)malloc(n*sizeof(int));

    preenche_vetor(vet,n);
    imprime_vetor(vet,n);
    soma(vet,n);

    return (0);
    system("pause");
}


