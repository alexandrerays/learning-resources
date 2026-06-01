/*
 *  Guilherme Ramos Oliveira NroUSP: 6908006
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void contaPalavras(char *s, int *ptPalavra) //OK
{
    char leitura, *texto;
    int c=0,i, contador=0; // numero de caracteres lidos
    FILE *ft;

    ft = fopen(s,"r");

    // aloca 1 byte (1 char)
    texto = (char *) malloc(sizeof(char));

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

    // imprime string completa
    //printf("\n%s\n", texto);
    for(i=0; texto[i]!='\0'; i++) /*O fim da string é o limite do for*/
    {
        if(isalnum(texto[i]))  /*s[i] é caracter alfabético? */
        {
            continue;
        }
        if(isspace(texto[i])) /*s[i] é espaço, \t, \n \r ? */
        {
            if(texto[i-1]=='.' || texto[i-1]==',' ||isspace(texto[i-1]))
            {
                continue;
            }
            else
            {
                contador++;
                continue;
            }
        }
        if(texto[i]=='.' || texto[i]==',')
        {
            if(texto[i-1]=='.' || texto[i-1]==',' ||isspace(texto[i-1]))
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
    *ptPalavra = contador;

    // libera memoria alocada
    free(texto);

    // fecha arquivo
    fclose(ft);

}

void contaPreposicoes(char *s, int *ptPreposicoes) //usar strtok
{

}

void contaEspacos(char *s, int *ptEspacos) //OK
{
    char leitura, *texto;
    int c=0,i, contador=0; // numero de caracteres lidos
    FILE *ft;

    ft = fopen(s,"r");

    // aloca 1 byte (1 char)
    texto = (char *) malloc(sizeof(char));

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

    // imprime string completa       espaços, ponto, tab, pulo de linha (\n), retorno de carro (\r) e vírgula
    //printf("\n%s\n", texto);
    for(i=0; texto[i]!='\0'; i++) /*O fim da string é o limite do for*/
    {
        if(texto[i]==' ') /*s[i] é espaço, \t, \n \r ? */
        {
            contador++;
            continue;
        }
        continue;

    }
    *ptEspacos = contador;

    // libera memoria alocada
    free(texto);

    // fecha arquivo
    fclose(ft);
}

void contaTab(char *s, int *ptTab) //OK
{
    char leitura, *texto;
    int c=0,i, contador=0; // numero de caracteres lidos
    FILE *ft;

    ft = fopen(s,"r");

    // aloca 1 byte (1 char)
    texto = (char *) malloc(sizeof(char));

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

    // imprime string completa       espaços, ponto, tab, pulo de linha (\n), retorno de carro (\r) e vírgula
    //printf("\n%s\n", texto);
    for(i=0; texto[i]!='\0'; i++) /*O fim da string é o limite do for*/
    {
        if(texto[i]=='\t') /*s[i] é espaço, \t, \n \r ? */
        {
            contador++;
            continue;
        }
        continue;

    }
    *ptTab = contador;

    // libera memoria alocada
    free(texto);

    // fecha arquivo
    fclose(ft);
}

void contaMaisquedez(char *s, int *ptMaisquedez)//usar strlen
{
    char leitura, *texto, *lista, *pt;
    int c=0,i,j,n, contador=0; // numero de caracteres lidos
    FILE *ft;
    char **lista;

    ft = fopen(s,"r");

    // aloca 1 byte (1 char)
    texto = (char *) malloc(sizeof(char));

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

    // imprime string completa       espaços, ponto, tab, pulo de linha (\n), retorno de carro (\r) e vírgula
    //printf("\n%s\n", texto);

    contaPalavras(s,ptPalavra);
    n = *ptPalavra;
    n += 20;

    lista = (char**)malloc(sizeof(char*)*n);
    for(i = 0; i < n; i++)
    {
        lista[i] = (char*)malloc(sizeof(char)*50);
    }

    for(j=0; j<n; j++)
    {
        for(i=0; i<; i++) /*O fim da string é o limite do for*/
        {
            lista[j][i] = strtok (texto," .,\t\n\r");

        }
    }
    for(i=0; i<n; i++) /*O fim da string é o limite do for*/
    {
        if((unsigned)strlen(lista[i])==10)
        {
            contador++;
        }


    }
    *ptMaisquedez = contador;

    // libera memoria alocada
    free(texto);

    // fecha arquivo
    fclose(ft);
}

void menu(char *tarefas, char *s, int *ptPalavra, int *ptEspacos, int *ptTab)
{

    if(tarefas[0]=='1')
    {
        contaPalavras(s,ptPalavra);
    }
    if(tarefas[1]=='1')
    {
        contaPreposicoes();
    }
    if(tarefas[2]=='1')
    {
        contaEspacos(s,ptEspacos);
    }
    if(tarefas[3]=='1')
    {
        contaTab(s,ptTab);
    }
    if(tarefas[4]=='1')
    {
        contaMaisquedez(s,ptMaisquedez);
    }
}

void imprimir(char *tarefas, char *s, int *ptPalavra, int *ptEspacos, int *ptTab)
{
    if(tarefas[0]=='1')
    {
        printf("%d\n", contaPalavra);
    }
    if(tarefas[1]=='1')
    {
        printf("%d\n", contaPreposicoes);
    }
    if(tarefas[2]=='1')
    {
        printf("%d\n", contaEspacos);
    }
    if(tarefas[3]=='1')
    {
        printf("%d\n", contaTab);
    }
    if(tarefas[4]=='1')
    {
        printf("%d\n", contaMaisquedez);
    }
}

int main (int argc, char *argv[])
{

    char s[100], tarefas[5];
    int contaPalavra,contaEspacos,contaTab,contaPreposicoes,contaMaisquedez;
    int *ptPalavra = &contaPalavra, *ptEspacos = &contaEspacos;
    int *ptTab = &contaTab,*ptPreposicoes = &contaPreposicoes, *ptMaisquedez = &contaMaisquedez;

    puts("Introduza o nome do arquivo: ");
    gets(s);
    // abre um arquivo no formato leitura (r - read) texto

    puts("Digite as tarefas que serao executadas: ");
    gets(tarefas);

    menu(tarefas,s,ptPalavra,ptEspacos,ptTab);
    imprimir();


    return 0;
}

