/* Trabalho 4 de ICC2
 * Aluno Guilherme Ramos Oliveira
 * Turma BCC A
 * Professor Moacir Ponti
 * Data 30 de Agosto de 2013
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//funcao que aloca memoria para armazenar um arquivo e utiliza realloc pois sao introduzidos caracter por caracter na memoria
//esta funcao foi fornecida pelo professor Moacir como base para comecar o primeiro trabalho de icc2 e foi reaproveitada aqui
char* alocaArquivo(FILE *ft)
{
    // aloca 1 byte (1 char)
    char *arquivo = (char *) malloc(sizeof(char));

    char leitura; // variavel temporaria para ler arquivo caracter por caracter

    int c=0;

    // fgetc -> le 1 byte do arquivo e armazena na variavel (lvalue)
    // quando o retorno for EOF, significa que o arquivo terminou (End Of File)
    while ((leitura = fgetc(ft)) != EOF)
    {

        // armazena o caracter lido na string
        arquivo[c] = leitura;

        // incrementa variavel de numero de caracteres
        c++;
        // realoca espaco na memoria, para mais um caracter
        arquivo = realloc(arquivo, c+1*sizeof(char));
    }

    // insere o caracter terminador de string
    arquivo[c] = '\0';

    return arquivo;
}

void analisaHeader(char *arq)
{
    int i, lineBreak=0, c=0, height, width;
    char *largura = (char *) malloc(sizeof(char));
    char *altura = (char *) malloc(sizeof(char));
    char *maxCinza = (char *) malloc(sizeof(char));

    for(i=0; lineBreak<=4; i++)
    {
        if(lineBreak>=2)
        {
            if(lineBreak==2)
            {
                while(arq[i]!=' ')
                {
                    largura[c] = arq[i];
                    c++;
                    largura = realloc(largura, c+1*sizeof(char));
                }
                largura[c] = '\0';
                c=0;
                while(arq[i]!='\n')
                {
                    altura[c] = arq[i];
                    c++;
                    altura = realloc(altura, c+1*sizeof(char));
                }
                altura[c] = '\0';
                c=0;
            }
            if(lineBreak==3)
            {
                while(arq[i]!='\n')
                {
                    maxCinza[c] = arq[i];
                    c++;
                    maxCinza = realloc(maxCinza, c+1*sizeof(char));
                }
                maxCinza[c] = '\0';
                c=0;
            }
        }
        if(arq[i]=='\n'){lineBreak++;}
    }

    height = atoi(altura);
    width = atoi(largura);
    printf("%s\n", largura);
    printf("%s\n", altura);
    printf("%s\n", maxCinza);
    printf("%d\n", height*width);

    free(maxCinza);
    free(altura);
    free(largura);
}

//funcao principal
int main (int argc, char *argv[])
{
    char nome[30], *arquivo;
    int i;

    scanf("%s", nome);
    FILE *ft = fopen(arquivo,"rb"); // abre um arquivo no formato leitura (r - read)

    arquivo = alocaArquivo(ft); //arquivo e um ponteiro que vai apontar para a porcao de memoria que alocou o arquivo
    printf("%s", arquivo);
    analisaHeader(arquivo);
    fclose(ft);
    free(arquivo);

    return 0;
}
