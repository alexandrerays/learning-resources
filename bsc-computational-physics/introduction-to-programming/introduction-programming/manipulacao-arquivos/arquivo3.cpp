#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
//ferror, perror e fputs

int main()
{
    FILE *pf;
    char string[100];
    if((pf = fopen("arquivo.txt","w"))==NULL) 
    {
        printf("\nNao consigo abrir o arquivo ! ");
        exit(1);
    }
    do 
    {
        printf("\nDigite uma nova string. Para terminar, digite <enter>: ");
        gets(string);
        fputs(string, pf);
        putc('\n', pf);
        if(ferror(pf))
        {
            perror("Erro na gravacao");
            fclose(pf);
            exit(1);
        }
    } while (strlen(string) > 1);
    fclose(pf);
}
