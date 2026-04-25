/* Trabalho 4 de ICC2
 * Aluno Guilherme Ramos Oliveira
 * Turma BCC A
 * Professor Moacir Ponti
 * Data 16 de Agosto de 2013
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//funcao que aloca memoria para armazenar um texto e utiliza realloc pois sao introduzidos caracter por caracter na memoria
//esta funcao foi fornecida pelo professor Moacir como base para comecar o primeiro trabalho de icc2 e foi reaproveitada aqui
char* alocaHeader(FILE *ft)
{
    // aloca 1 byte (1 char)
    char *header = (char *) malloc(sizeof(char));

    char leitura, lineBreak=0; // variavel temporaria para ler arquivo caracter por caracter

    int c = 0;

    // fgetc -> le 1 byte do arquivo e armazena na variavel (lvalue)
    // quando o retorno for EOF, significa que o arquivo terminou (End Of File)
    while ((leitura = fgetc(ft)) != EOF)
    {
        if(lineBreak>=2)
        {
            // armazena o caracter lido na string
            if(isalnum(leitura))
            {
                header[c] = leitura;
                c++;
                header = realloc(header, c+1*sizeof(char));
            }
            if(leitura==' ')
            {
                header[c]='\n';
                c++;
                header = realloc(header, c+1*sizeof(char));
            }
            if(leitura=='\n')
            {
                header[c] = leitura;
                c++;
                header = realloc(header, c+1*sizeof(char));
            }

        }
        if(leitura=='\n')
        {
            lineBreak++;
        }
        if(lineBreak==4)
        {
            break;
        }
    }
    header[c] = '\0';

    return header;
}

void analisaHeader(char *header)
{
    int i,j=0,lineBreak=0, height, width, maxGray;
    char itens[3][6];

    for(i=0; header[j]!='\n'; i++)
    {
        itens[0][i]=header[j];
        j++;
    }
    itens[0][i]='\0';
    j++;
    for(i=0; header[j]!='\n'; i++)
    {
        itens[1][i]=header[j];
        j++;
    }
    itens[1][i]='\0';
    j++;
    for(i=0; header[j]!='\n'; i++)
    {
        itens[2][i]=header[j];
        j++;
    }
    itens[2][i]='\0';

    height = atoi(itens[1]);
    width = atoi(itens[0]);
    maxGray = atoi(itens[2]);
    printf("%d\n", width);
    printf("%d\n", height);
    printf("%d\n", maxGray);
    printf("%d\n", height*width);

}

//funcao principal
int main (int argc, char *argv[])
{
    char arquivo[30], *header;
    int i, a, b;

    scanf("%s", arquivo);
    scanf("%d", &a);
    scanf("%d", &b);
    FILE *ft = fopen(arquivo,"rb"); // abre um arquivo no formato leitura (r - read) texto

    header = alocaHeader(ft); //texto e um ponteiro que vai apontar para a porcao de memoria que alocou o arquivo texto
    //printf("%s", header);
    analisaHeader(header);
    //printf("4\n");
    //printf("4 0 0 0 0 0 4 0 0 0 0 0 4 0 0 4");
    fclose(ft);
    free(header);

    return 0;
}


