/*************************************************************************/
/*Lista1 exer3.7                                                        */
/*emanuel.valente@usp.br vulgo Tourinho - Fiscomp T010                   */
/*************************************************************************/
//obs: Meses que vão até o dia 31: jan(1),mar(3),mai(5),jul(7),ago(8),out(10),dez(12)


#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

int main()
{
    int d,m,a;
    short int bissexto = false;

    printf("\nDigite entre espacos o dia, mes e ano: ");
    scanf("%d %d %d",&d,&m,&a);

    if((a<0)||(m<0)||(m>12)||(d<0)||(d>31)) {
        printf("\nData invalida!\n");
        exit(0);
    }

    //anos bissextos?
    if((a%100)==0)bissexto = false;
    else if((a%4)==0)bissexto = true;

    if((a%400)==0)bissexto = true;

    //Se ano não é bissexto, não existe 29/2
    if(!bissexto) {
        if((m==2)&&(d>28)) {
            printf("Não existe dia maior que 28/2 em anos não bissextos\n\n");
            exit(0);
        }
    }else if((m==2)&&(d>29)) {
        printf("\n\nNao existe dia maior que 29/2\n\n");
        exit(0);
    }

    //Meses que não possuem 31
    if(d==31) {
        if((m==2)||(m==4)||(m==6)||(m==9)||(m==11)) {
            printf("\nNao existe dia 31 para esse mes\n\n");
            exit(0);
        }
    }

    printf("\n %d/%d/%d eh uma data correta\n\n",d,m,a);

    getchar();
    getchar();

    return(0);
}
