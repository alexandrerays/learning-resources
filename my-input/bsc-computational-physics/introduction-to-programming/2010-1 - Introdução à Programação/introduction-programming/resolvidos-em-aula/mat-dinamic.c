#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

void preenche_matriz(int **m,int linhas,int colunas)
{
    int i,j;

    for(i=0;i<linhas;i++) {
        for(j=0;j<colunas;j++) {
            m[i][j] = (rand()%10);
        }
    }
}

void imprime_matriz(int **m,int linhas,int colunas)
{
    int i,j;

    for(i=0;i<linhas;i++) {
        printf("\n");
        for(j=0;j<colunas;j++) {
            //printf("\nmat[%d][%d] = %d",i,j,m[i][j]);
            printf(" %d ",m[i][j]);
        }
    }
}

void soma_diagonal_principal(int **v,int linhas,int colunas)
{
    int i,j,soma=0;

    for(i=0;i<linhas;i++) {
        for(j=0;j<colunas;j++) {
            if(i==j) soma += v[i][j];
        }
    }

    printf("\nA soma da diagonal principal eh: %d\n\n",soma);


}


int main()
{
    int **mat;
    int linhas,colunas;
    int i;

    printf("\nDigite o numero de linhas da matriz: ");
    scanf("%d",&linhas);

    printf("\nDigite o numero de colunas da matriz: ");
    scanf("%d",&colunas);

    //aloca o vetor de linhas
    mat = (int**)malloc(linhas*sizeof(int*));

    //aloca os vetores colunas
    for(i=0;i<linhas;i++)
    mat[i] = (int*)malloc(colunas*sizeof(int));


    preenche_matriz(mat,linhas,colunas);
    imprime_matriz(mat,linhas,colunas);
    soma_diagonal_principal(mat,linhas,colunas);
    //soma(vet,n);

getch();
    return (0);
}


