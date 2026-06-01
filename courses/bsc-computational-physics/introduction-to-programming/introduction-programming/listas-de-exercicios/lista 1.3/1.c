/*************************************************************************/
/*Lista1 exer3.1                                                        */
/*emanuel.valente@usp.br vulgo Tourinho - Fiscomp T010                   */
/*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b,c;

    printf("\nDigite os tres numeros seguidos de espaco: ");
    scanf("%d %d %d",&a,&b,&c);

    if(a>b) {
        if(b>c) printf("\n%d eh menor",c); //c é menor
        else printf("\n%d eh menor",b); //b é menor
    }else {
        if(c>a)printf("\n%d eh menor",a); //a é menor
        else printf("\n%d eh menor",c); //c é menor
    }

    getchar();

    return(0);

}
