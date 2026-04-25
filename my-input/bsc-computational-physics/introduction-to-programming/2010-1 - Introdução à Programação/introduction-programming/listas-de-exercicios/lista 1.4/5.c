/*************************************************************************/
/*Lista1 exer4.5                                                       */
/*emanuel.valente@usp.br vulgo Tourinho - Fiscomp T010                   */
/*************************************************************************/
//obs: A serie na lista esta errada. A correta seria:
//exp(n) = 1 + n + n^2/2! + n^3/3!  Fonte: http://www.cs.mtu.edu/~shene/COURSES/cs201/NOTES/chap04/exp.html

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define true 1
#define false 0

int main()
{
    int x;
    float v1,v2;
    int i,j;
    int k;
    float f;


    printf("\nDigite o valor da potencia de base \"e\": ");
    scanf("%d",&x);

    v1 = exp(x);

    //printf("\nO valor de v2 eh: %f\n",v1);



    k = 1; //primeiro multiplicador da fatorial
    f = 1.0;
    v2 = 1.0;

    for(i=1;(v1-v2)>0.0001;i++) { //i = qtide de termos da serie

        j = k;
        for(;j>1;j--) { //fatorial;
            f = f*j;
        }

        v2 = v2 + (pow(x,i)/f);


        //printf("\n\nv2 vale %f",v2);

        //printf("\n Dividindo %d elevado a %d / %f ",x,i,f);

        k++;
        f = 1;

    }

    printf("\n\nExp pela funcao exp(): %f\nExp pela serie: %f\nNumero de iteracaoes %d",v1,v2,i-1);

    getchar();
    getchar();

    return(0);
}
