/*************************************************************************/
/*Lista1 exer3.2                                                        */
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
        if(b>c){  //c é menor, poderá entao estar e ordem decrescente
            if(a>b) printf("\nEsta em ordem descrescente");
        }
    } else { // a < b
        if(b<c) printf("\nEsta em ordem crescente");
    }


    getchar();

    return(0);

}
