/*Fazer uma funcao que recebe um string e um caractere
e verifica se o catactere esta presentena string
by Tourinho - Fiscomp T010 - emanuelvalente@usp.br
*/

//versao com ponteiros

#include <stdio.h>
#include <stdlib.h>

int verifica(char* st,char* ch)
{
    int i;
    for(i=0;(*st+i)!='\0';i++) if(*(st+i)==*ch) return 1;

    return 0;
}


int main()
{
    char s[50];
    char c;

    printf("\nDigite uma string: ");
    gets(s);
    printf("\nDigite o carecter a ser procurado na string: ");
    scanf("%c",&c);
    if(verifica(s,&c))puts("\nCaractere encontrado!\n");
    else puts("\nCaractere nao encontrado!\n");

    system("pause");
     return (0);
}
