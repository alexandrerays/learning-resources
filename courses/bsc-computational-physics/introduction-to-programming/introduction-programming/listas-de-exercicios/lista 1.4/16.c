/*************************************************************************/
/*Lista1 exer4.16                                                       */
/*emanuel.valente@usp.br vulgo Tourinho - Fiscomp T010                   */
/*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define true 1
#define false 0

int main()
{
    int n;
    int i;
    int count, count_bk;
    int init_space, init_space_bk;
    char space;

    n=2;
    space = ' ';
    count = 0;


    while((n%2)==0) {
        printf("\nDigite um valor impar para construcao do diamante: ");
        scanf("%d",&n);
    }

    init_space = n/2;
    init_space_bk = init_space;

   // printf("\ninit_space vle %d",init_space);

    printf("\n\n");

    count = 1;
    count_bk = 1;

    //imprimindo hemisferio norte
    for(i=0;i<n/2;i++) { //numero de linhas do hemisferio norte
        for(init_space;init_space>0;init_space--) { //espacos por linha
            printf("%c",space);
        }

        for(count;count>0;count--) printf("*"); //asteriscos nos lugares apropriados
        init_space=--init_space_bk; //recuperando valor do espaco (diminui de 1 a cada loop)
        printf("\n");
        count_bk = count_bk+2; //contadores de * (aumentam de 2 a cada loop)
        count = count_bk;      //recupera valor do contador
        //printf("\ncount vale %d",count);
    }

    //imprimindo linha maior
    for(count=n;count>0;count--)printf("*");

    //imprindo hemisferio sul

    printf("\n");

    count = n-2;
    count_bk = n-2;
    init_space =1;
    init_space_bk=1;
    for(i=0;i<n/2;i++) { //numero de linhas
        for(init_space;init_space>0;init_space--) { //espacos em cada linha
            printf("%c",space);
        }

        for(count;count>0;count--) printf("*");
        init_space=++init_space_bk;
        printf("\n");
        count_bk = count_bk-2;
        count = count_bk;
        //printf("\ncount vale %d",count);
    }


    getchar();
    getchar();

    return(0);
}
