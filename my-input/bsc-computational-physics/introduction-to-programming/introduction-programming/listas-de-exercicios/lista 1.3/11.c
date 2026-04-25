/*************************************************************************/
/*Lista1 exer3.11                                                        */
/*emanuel.valente@usp.br vulgo Tourinho - Fiscomp T010                   */
/*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

int main()
{
    float a,b;


    printf("\nInsira o primeiro numero: ");
    scanf("%f",&a);

    printf("\nInsira o segundo numero: ");
    scanf("%f",&b);

    if(a<0) b = a;

    if((a>=0)&&(a<=1)) {
        b = 1/(1-(a*a));
    }

    if(a>1) {
        b = (3*log(a)) + a*a;
    }


    printf("\n\n a vale %f e b vale %f\n\n",a,b);


    getchar();
    getchar();

    return(0);
}
