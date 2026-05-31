/*************************************************************************/
/*Lista1 exer3.12                                                        */
/*emanuel.valente@usp.br vulgo Tourinho - Fiscomp T010                   */
/*************************************************************************/

//HT = HE -(2/3)*faltas
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

int main()
{
    int faltas, hora_e, hora_t;

    printf("\nInsira o numero de horas extras trabalhadas: ");
    scanf("%d",&hora_t);

    printf("\nInsira o numero de faltas: ");
    scanf("%d",&faltas);

    hora_t = hora_e - ((2/3)*faltas);

    if(hora_t>40) {
        printf("\nSeu premio eh 50\n");
    }

    if((hora_t<=40)&&(hora_t>30)) {
        printf("\nSeu premio eh 40\n");
    }

    if((hora_t<=30)&&(hora_t>20)) {
        printf("\nSeu premio eh 30\n");
    }

    if((hora_t<=20)&&(hora_t>10)) {
        printf("\nSeu premio eh 20\n");
    }

    if(hora_t<=10) {
        printf("\nSeu premio eh 10\n");
    }


    getchar();
    getchar();

    return(0);
}
