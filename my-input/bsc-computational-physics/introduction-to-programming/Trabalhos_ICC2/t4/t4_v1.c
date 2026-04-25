/* Trabalho 3 de ICC2
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
char* alocaTexto(FILE *ft)
{
    // aloca 1 byte (1 char)
    char *texto = (char *) malloc(sizeof(char));

    char leitura; // variavel temporaria para ler arquivo caracter por caracter

    int c = 0;

    // fgetc -> le 1 byte do arquivo e armazena na variavel (lvalue)
    // quando o retorno for EOF, significa que o arquivo terminou (End Of File)
    while ((leitura = fgetc(ft)) != EOF)
    {

        // armazena o caracter lido na string
        texto[c] = leitura;

        // incrementa variavel de numero de caracteres
        c++;
        // realoca espaco na memoria, para mais um caracter
        texto = realloc(texto, c+1*sizeof(char));
    }

    // insere o caracter terminador de string
    texto[c] = '\0';

    return texto;
}

//funcao que atribui valores iniciais aos vetores de caracteres envolvidos na soma
void iniciaBloco(unsigned char *bits, unsigned char aChar)
{
    int i;

    for(i=0; i<32; i++)
    {
        (bits)[i]=aChar;
    }
    (bits)[32]='\0';
}

//funcao que converte os caracteres em bits e imprime na tela
void printChar(char c)
{
    int i;
    for (i=7;i>=0;--i)
    {
        putchar((c & (1 << i)) ? '1' : '0');
    }
}

//funcao que soma grupos de 32 caracteres do texto com um vetor de nome bits. Faz tratamento de overflow do grupo de bits
char* somaGrupos(char *texto)
{
    int overflow;
    unsigned char bits[33], aux[33];
    int i=0,j,contador=0;

    iniciaBloco(bits, 0);//inicia o bloco de bits com zeros
    iniciaBloco(aux, 0x20); //inicia o bloco auxiliar com espacos

    char shouldQuit = 0;
    while(!shouldQuit)
    {
        while(contador<32) //pega blocos de 32 caracteres do texto e armazena na variavel auxiliar
        {
            if (texto[i] == '\0'){shouldQuit = 1; break;}
            aux[contador]=texto[i];
            i++;
            contador++;
        }
        overflow=0;
        for(j=31; j>=0; j--)
        {                                      //variavel soma recebe bits(setada com zeros) mais os caracteres da variavel auxiliar
            int soma=bits[j]+aux[j]+overflow;  //mais o overflow da soma anterior
            overflow=(soma>=256);       //se o overflow for maior que 256 seta 1, senao seta 0
            bits[j]=(unsigned char)soma;
        }
        contador=0;
        iniciaBloco(aux, 0x20); //inicia o bloco auxiliar com espacos
    }
    for(i=0; i<32; i++)
    {
        printChar(bits[i]);
    }
}

//funcao principal
int main (int argc, char *argv[])
{
    char arquivo[30], *texto, *bits;
    int i;

    scanf("%s", arquivo);
    FILE *ft = fopen(arquivo,"r"); // abre um arquivo no formato leitura (r - read) texto

    texto = alocaTexto(ft); //texto e um ponteiro que vai apontar para a porcao de memoria que alocou o arquivo texto
    bits = somaGrupos(texto);
    fclose(ft);
    free(texto);

    return 0;
}
