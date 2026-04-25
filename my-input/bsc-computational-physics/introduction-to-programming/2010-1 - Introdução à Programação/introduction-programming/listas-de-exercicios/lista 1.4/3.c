/*************************************************************************/
/*Lista1 exer4.3                                                       */
/*emanuel.valente@usp.br vulgo Tourinho - Fiscomp T010                   */
/*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

int main()
{
    int i,j,k;
    float d;
    float f;
    float soma = 0;


    k = 0;
    f = 1.0;

    for(i=1; i<=20; i++) {

        j = k;
        for(;j>=1;j--) { //fatorial;
            f = f*j;
        }
        k++;
        //printf("\n\nfat vale %f",f);

        //printf("\nDividindo %f/%f",101.0-i,f);

        soma = soma + (101.0 -i)/f;
        f = 1;

    }

    printf("\n\nA soma eh: %f\n\n",soma);
    getchar();
    getchar();

    return(0);
}
