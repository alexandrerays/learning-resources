/*Calcula a media aritmetica de n numeros
*Emanuel Valente - Física Computacional - Turma 010 - USP
*/

#include <stdio.h>

int main()
{
    int n, i, x;
    float soma = 0;
    float media = 0;
    
    printf("\nDigite o numero de entradas: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++) {
                     printf("\nDigite um numero: ");
                     scanf("%d",&x);
                     soma = soma + x;
                     }
    media = (soma/n);
    printf("\nA media eh: %f\n",media);
                     
    getchar();
    getchar();
    
    return(0);
    
}   
    
