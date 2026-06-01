/*************************************************************************/
/*Lista1 exer4.1                                                       */
/*emanuel.valente@usp.br vulgo Tourinho - Fiscomp T010                   */
/*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

int main()
{
    int i;
    float n;
    float soma = 0;


    for(i=1,n=2; i<=50; i++,n++) {
        soma = soma + (pow(n,i))/(51-i);
        printf("\nA soma eh %f\n",soma);

    }

    printf("\n\nA soma eh: %f\n\n",soma);
    getchar();
    getchar();

    return(0);
}
