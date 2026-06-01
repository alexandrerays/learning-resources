#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

main()
{
       int pontos, n=0;
       puts("Entre com uma nota\n");
       scanf("%d",&pontos);
       while(pontos>=0){
       n=n++;
       scanf("%d", &pontos);
       }
       puts("total de notas\n");
       printf("%d", &n);
       system("pause");
}

