/*************************************************************************/
/*Lista1 exer3.4                                                        */
/*emanuel.valente@usp.br vulgo Tourinho - Fiscomp T010                   */
/*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b,c;
    float delta;
    float r1,r2;

    printf("\n (a)x^2 +(b)x + (c) =0 \nDigite os 3 coeficientes (a, b e c) seguidos de espacos para as raízes serem calculadas: ");
    scanf("%d %d %d",&a,&b,&c);

    delta = (b*b)-(4*a*c);
    //printf("\n\ndelta vale %f",delta);

    if(delta>0) {
        r1 = (-b+sqrt(delta))/(2*a);
        r2 = (-b-sqrt(delta))/(2*a);
        printf("\n\nAs raizes sao %f e %f",r1,r2);
    }else if(delta ==0) {
        r1 = (-b+sqrt(delta))/(2*a);
        printf("\n\nA unica raiz eh %f",r1);
    }

    if(delta<0) {
        printf("\nAs raizes complexas sao:\n (%d + raiz(%f)i)/%d",((-1)*b),((-1)*delta),2*a);
        printf(" e  (%d - raiz(%f)i)/%d",((-1)*b),((-1)*delta),2*a);
    }

    getchar();
    getchar();

    return(0);

}
