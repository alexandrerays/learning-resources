/* Trabalho 2 de ICC2
 * Aluno Guilherme Ramos Oliveira
 * Turma BCC A
 * Professor Moacir Ponti
 * Data 10 de Agosto de 2013
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SEPARADORES " \\.\t,\n\r\?\'\":-;\[]*$\%#@!_|\\/"

//funcao que aloca memoria para armazenar um texto e utiliza realloc pois sao introduzidos caracter por caracter na memoria
//esta funcao foi fornecida pelo professor Moacir como base para comecar o primeiro trabalho de icc2 e foi reaproveitada aqui
char* alocaTexto(FILE *ft)
{
    // aloca 1 byte (1 char)
    char *texto = (char *) malloc(sizeof(char));

    char leitura; // variavel temporaria para ler arquivo caracter por caracter

    int c = 0; // numero de caracteres lidos

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

//funcao criada para auxiliar na remocao dos delimitadores enquanto eles sao colocados em uma matriz que
// e utilizada como uma lista de palavras
int isDelimiter(char ch)
{
    char separadores[] = SEPARADORES;
    int i;

    for (i=0; separadores[i] != '\0'; i++)
    {
        if (ch == separadores[i])
            return 1;
    }
    return 0;
}

//funcao que conta o numero de palavras no arquivo de texto
int contaPalavras(char *texto)
{
    int i, contador=0; // numero de caracteres lidos

    for(i=0; texto[i]!='\0'; i++) //O fim da string é o limite do for
    {
        if(isalnum(texto[i]))  //s[i] é caracter alfabético?
        {
            continue;
        }
        if(isDelimiter(texto[i])) //texto[i] é espaço, \t, \n, \r, ponto, virgula, etc... delimitadores pedidos na descricao do trabalho
        {
            if(isDelimiter(texto[i-1]))
            {
                continue;
            }
            else
            {
                contador++;
                continue;
            }
        }
    }
    return contador;
}

//funcao que conta o numero de palavras que se repetem 1 ou mais vezes no texto
int contaPalavrasRepetidas(char **lista,int nroPalavras)
{
    int i,j, palavrasRepetidas=0, flag=0;

    for(i=0; i<nroPalavras; i++)
    {
        for(j=0; j<nroPalavras; j++)
        {
            if(strcasecmp(lista[i], lista[j])==0 && i != j && strcmp(lista[i],"\0") != 0) //testa se as palavras sao iguais
            { // e se nao e a mesma palavra da lista. Cada palavra repetida recebe o delimitador de string na priimeira posicao
                flag=1;
                strcpy(lista[j],"\0");
            }
        }
        strcpy(lista[i],"\0");
        if(flag==1)
        {
            palavrasRepetidas++;
            flag=0;
        }
    }
    return palavrasRepetidas;
}

//funcao que aloca uma matriz para armazenar as palavras do texto
char** alocaLista(char *texto, int nroPalavras)
{
    char **lista, *pt;
    int k=1,i=0; // numero de caracteres lidos

    lista = (char**)malloc(sizeof(char*)*nroPalavras);

    i=1;
    lista[0]=strtok(texto, SEPARADORES); //strtok auxilia na separacao das palavras para armazena-las na lista
    pt = strtok(NULL, SEPARADORES);
    while(i<nroPalavras)
    {
        lista[i] = (char*)malloc(sizeof(char)*(strlen(pt)+1));
        strcpy(lista[i],pt);
        pt = strtok(NULL, SEPARADORES);
        i++;
        k++;
    }
    free(pt);

    return lista;
}

//funcao principal
int main (int argc, char *argv[])
{
    char arquivo[30], *texto, **lista;
    int nroPalavras=0,i, palavrasRepetidas=0;

    scanf("%s", arquivo);
    FILE *ft = fopen(arquivo,"r"); // abre um arquivo no formato leitura (r - read) texto

    texto = alocaTexto(ft); //texto e um ponteiro que vai apontar para a porcao de memoria que alocou o arquivo texto
    nroPalavras = contaPalavras(texto); //nroPalavras e um inteiro que recebe a quantidade de palavras no texto
    lista = alocaLista(texto,nroPalavras);  //lista e um ponteiro de ponteiro que recebe o endereco da porcao de memoria que contem as palavras
    palavrasRepetidas = contaPalavrasRepetidas(lista,nroPalavras); //palavrasRepetidas e um inteiro que recebe a quantidade de palavras que
    printf("%d\n", palavrasRepetidas);                              //se repetem pelo menos uma vez no texto
    fclose(ft);

    i = nroPalavras - 1;
    while(i > 0) {
        if(lista[i] != NULL) free(lista[i]);
        lista = (char **) realloc(lista, sizeof(char *)*(i));
        i--;
    }
    free(lista);
    free(texto);

    return 0;
}
