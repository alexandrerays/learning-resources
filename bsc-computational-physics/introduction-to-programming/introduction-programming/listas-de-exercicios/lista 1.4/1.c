/*************************************************************************/
/*Lista1 exer4.1                                                       */
/*emanuel.valente@usp.br vulgo Tourinho - Fiscomp T010                   */
/*************************************************************************/

//HT = HE -(2/3)*faltas
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

int main()
{
    int n, i;
    float soma = 0;

    printf("\nInsira o valor de n: ");
    scanf("%d",&n);

    for(i=1; i<=n; i++) {
        soma = soma + 1.0/i;

    }

    printf("\n\nA soma eh: %f\n\n",soma);
    getchar();
    getchar();

    return(0);
}
