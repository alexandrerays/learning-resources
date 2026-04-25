/*************************************************************************/
/*Lista1 exer4.4                                                       */
/*emanuel.valente@usp.br vulgo Tourinho - Fiscomp T010                   */
/*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

int main()
{
    float x;
    int sinal;
    int i,j,k;
    float cosseno = 0;
    float f;


    printf("\nDigite um valor em radianos para ser calculado seu cosseno: ");
    scanf("%f",&x);


    cosseno = 1.0;
    k = 2; //primeiro multiplicador da fatorial
    sinal = -1;
    f = 1.0;

    for(i=0; i<10; i++) { //i = qtide de termos da serie

        j = k;
        for(;j>1;j--) { //fatorial;
            f = f*j;
        }
        if((k%4)==0)sinal=1;

        //printf("\n\nfat vale %f",f);

        //printf("\nsinal: %d Dividindo %f elevado a %d / %f ",sinal,x,k,f);

        cosseno = cosseno + (sinal)*(pow(x,k)/f);
        k=k+2;
        f = 1;
        sinal = -1;

    }

    printf("\n\nA cosseno eh: %f\n\n",cosseno);
    getchar();
    getchar();

    return(0);
}
