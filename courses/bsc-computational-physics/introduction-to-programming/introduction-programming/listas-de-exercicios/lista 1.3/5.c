/*************************************************************************/
/*Lista1 exer3.5                                                        */
/*emanuel.valente@usp.br vulgo Tourinho - Fiscomp T010                   */
/*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b,c;

    printf("\n Digite os lados de um triangulo seguidos de espacos: ");
    scanf("%d %d %d",&a,&b,&c);



    //os lados nao podem ser negativos
    if((a<0)||(b<0)||(c<0)) {
        printf("Os lados nao podem ser negativos\n");
        exit(0);
    }


    //condicao de existencia de um triangulo: a soma
    //de dois lados deve ser maior que outro lado


    if(((a+b)<c)||((a+c)<b)||((c+b)<a)) {
        printf("Triangulo nao existe\n");
        exit(0);
    }


    //verificando se nao eh retangulo
    if((a*a)==((b*b)+(c*c))||(b*b)==((a*a)+(c*c))||(c*c)==((b*b)+(a*a))) {
        printf("\nO triangulo eh retangulo");
    }else {
        //verificando se o triangulo é obtusangulo a^2 > b^2 + c^2
        if((a*a)>((b*b)+(c*c))||(b*b)>((a*a)+(c*c))||(c*c)>((b*b)+(a*a))) {
        printf("\nO triangulo eh obtusangulo");
        }else {
            //verificando se o triangulo é acuatngulo a^2 < b^2 + c^2
        if((a*a)<((b*b)+(c*c))||(b*b)<((a*a)+(c*c))||(c*c)<((b*b)+(a*a))) {
        printf("\nO triangulo eh acutangulo");
        }
     }
    }



    getchar();
    getchar();

    return(0);

}
