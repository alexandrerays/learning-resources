/**********************************************************/
/*Lista1 exer12                                       */
/*emanuel.valente@usp.br vulgo Tourinho - Fiscomp T010    */
/**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N;//meses
    float C; //capital inicial
    float I; //taxa mensal
    float M; //valor final (a ser acumalado)

    printf("\nDigite o capital inicial: ");
    scanf("%f",&C);
    printf("\nDigite o valor desejado a ser acumulado: ");
    scanf("%f",&M);
    printf("\nDigite a taxa mensal da poupanca em %: ");
    scanf("%f",&I);
    I = I/100; //tranforma em porcentagem

    N = (log(M)-log(C))/log(1+I);  //a funcao log() possui base "e"

    N = ceil(N);

    printf("\nO numero de meses para atingir R$ %f sera: %d\n\n",M,N);
    system("pause");


    return(0);

}
