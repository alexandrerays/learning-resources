/*Retira char de uma string usando ponteiros
by Tourinho - Fiscomp T010 - emanuelvalente@usp.br
*/

//versao com ponteiros

#include <stdio.h>
#include <stdlib.h>

int verifica(char* st,char ch)
{
    char *p_st;


    for(p_st=st;*p_st!='\0'&&*p_st!=ch;p_st++); //for acaba qdo encontrar string

    if(*p_st!='\0') return 1;
    else return 0;
}

void retira(char* st, char ch)
{
    char *p_st,*p2_st;

    //ps_st apontara para a posicao do final da string ou
    //a posicao quando ch for encontrado
    for(p_st=st;*p_st!='\0'&&*p_st!=ch;p_st++);
    if(*p_st!='\0'){
        for(p2_st=(p_st+1);*p2_st!='\0';p_st++,p2_st++) {
            *p_st = *p2_st;
        }
        *p_st = '\0';

    }

    printf("\nString com caractere retirado: ");
    puts(st);



}
int main()
{
    char s[50];
    char c;

    printf("\nDigite uma string: ");
    gets(s);

    printf("\nDigite o carecter a ser procurado na string: ");
    scanf("%c",&c);
    getchar();

    while(!verifica(s,c)) {
        printf("\nCarecter fornecido nao esta na string!\nPor favor digite outro: ");
        scanf("%c",&c);
        getchar();
    }


    while(verifica(s,c)){
        retira(s,c);
    }

    //system("pause");
     return (0);
}
