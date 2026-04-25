/*************************************************************************/
/*Lista1 exer3.3                                                        */
/*emanuel.valente@usp.br vulgo Tourinho - Fiscomp T010                   */
/*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b;
    int op;

    printf("\nDigite os 2 numeros a serem calculados seguidos de espaco: ");
    scanf("%d %d",&a,&b);

    printf("\nDigite o operador 1(SOMA) 2(SUBTRAI) 3(MULTIPLICA) 4(DIVIDE): ");
    scanf("\n%d",&op);

    if(op==1)printf("\n%d + %d = %d",a,b,(a+b));
    if(op==2)printf("\n%d - %d = %d",a,b,(a-b));
    if(op==3)printf("\n%d X %d = %d",a,b,(a*b));
    if(op==4)printf("\n%d/%d = %d",a,b,(a/b));


    getchar();
    getchar();

    return(0);

}
