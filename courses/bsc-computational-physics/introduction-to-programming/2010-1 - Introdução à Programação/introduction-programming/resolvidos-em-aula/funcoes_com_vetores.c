#include <stdio.h>
#include <stdlib.h>

void ler_vetor(int v[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nInsira um numero: ");
        scanf("%d",&v[i]);
    }

}

void imprime_vetor(int v[],int tam)
{
    int i;

    for(i=0;i<tam;i++) {
        printf("\nv[%d] = %d",i,v[i]);
    }
}

int verifica(int v[],int n,int x)
{
    int i;
    for(i=0;i<n;i++) {
        if(v[i]==x)return 1; //esta contido
    }

    return 0; // caso nao estiver contido
}

void inserir(int v[],int x,int pos)
{
    v[pos] = x;
}

void remover(int v[],int pos,int n)
{
    int i;
    if(!v[pos]) {
        printf("\nElemento nesta posicao nao existe! Nao pode ser removido");

    }else for(i=pos;i<n-1;i++) {
        v[i] = v[i+1];
        }

    imprime_vetor(v,n-1);
}

void somar(int v[],int n)
{
    int i;
    int soma=0;

    for(i=0;i<n;i++) {
        soma = soma + v[i];
    }

    printf("\n A soma de todos elementos eh: %d",soma);

}

void maior(int v[],int n)
{
    int i;
    int max = v[0];
    for(i=0;i<n;i++) {
        if(v[i]>max)max=v[i];
    }

    printf("\n\nO maior elemento eh %d\n\n",max);
}

int main()
{
    int n,x,pos;
    int vet[20];

    printf("\nEntre com o numero de elementos: ");
    scanf("%d",&n);

    ler_vetor(vet,n);
    imprime_vetor(vet,n);


    //verifica se um numero esta contido no vetor
    printf("\nEntre com um numero para ver se esta contido no vetor: ");
    scanf("%d",&x);
    if(verifica(vet,n,x)) {
        printf("\nO numero %d esta contido no vetor",x);
    }else printf("\nO numero %d nao esta contido no vetor",x);


    //insere um determinado numero na posicao p
    printf("\n\n\nDigite um numero qualquer e a posicao a ser inserido entre espacos: ");
    scanf("%d %d",&x,&pos);
    inserir(vet,x,pos);


    //soma todos elementos do vetor
    somar(vet,n);
    //remove um elemento da posicao dada
    printf("\n\nInsira uma posicao para o elemento ser retirado: ");
    scanf("%d",&pos);
    remover(vet,pos,n);
    maior(vet,n);


    return (0);

}


