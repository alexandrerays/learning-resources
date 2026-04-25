/*Calcula a soma da seguinte série: 1/1 + 3/2 + 5/3 + 7/4 + ... + 99/50
*Emanuel Valente - Física Computacional - Turma 010 - USP
*/

#include <stdio.h>

int main() 
{
    float n =1;
    float d =1;
    float soma = 0;
    
    do {
        soma = (soma + (n/d));
        n = n + 2;
        d = d + 1;
        } while(d <=50);
        
        printf("\nA soma eh: %f\n", soma);
        
        getchar();
        
        return(0);
}


        
        
        
