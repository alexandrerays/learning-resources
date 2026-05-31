/*************************************************************************/
/*Lista1 exer4.2.1                                                       */
/*emanuel.valente@usp.br vulgo Tourinho - Fiscomp T010                   */
/*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

int main()
{
    int i;
    float d;
    float soma = 0;


    for(i=1,d=1; i<=100000000; i++,d++) {
        if((i%2)==0) soma = soma - d/(d*d);
        else soma = soma + d/(d*d);
        //printf("\n\nsoma vale %f\n\n",soma);


    }

    printf("\n\nA soma eh: %f\n\n",soma);
    getchar();
    getchar();

    return(0);
}
