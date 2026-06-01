/*************************************************************************/
/*Lista1 exer3.8                                                        */
/*emanuel.valente@usp.br vulgo Tourinho - Fiscomp T010                   */
/*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

int main()
{
    int a,b;
    int a1,a2,a3,a4,b1,b2,b3,b4;
    int fail = false;

    printf("\nInsira o primeiro numero de quatro digitos: ");
    scanf("%d",&a);

    printf("\nInsira o segundo numero de quatro digitos: ");
    scanf("%d",&b);

    //obtendo os 4 digitos de a
    a1 = a/1000;
    a2 = (a-(a1*1000))/100;
    a3 = (a-((a1*1000)+a2*100))/10;
    a4 = (a-(((a1*1000)+(a2*100)+(a3*10))));

    //obtendo os 4 digitos de b
    b1 = b/1000;
    b2 = (b-(b1*1000))/100;
    b3 = (b-((b1*1000)+b2*100))/10;
    b4 = (b-(((b1*1000)+(b2*100)+(b3*10))));


    //comparando
    if(a1!=b4)fail = true;
    if(a2!=b3)fail = true;
    if(a3!=b2)fail = true;
    if(a4!=b1)fail = true;

    if(fail) printf("\n\n %d e %d nao sao palindromos\n\n",a,b);
    else printf("\n\n %d e %d sao palindromos\n\n",a,b);


    getchar();
    getchar();

    return(0);
}
