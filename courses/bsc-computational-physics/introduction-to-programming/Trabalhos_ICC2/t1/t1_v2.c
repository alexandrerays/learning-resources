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

void contaMaisquedez(char *s, int *ptMaisquedez, int *ptPalavra)//usar strlen
{
    char leitura, *texto, *pt;
    int c=0,k=1,i=0,n, contador=0; // numero de caracteres lidos
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

    n = *ptPalavra;
    //printf("n %d\n",n);

    lista = (char**)malloc(sizeof(char*)*n);
    for(i = 0; i < n; i++)
    {
        lista[i] = (char*)malloc(sizeof(char)*50);
    }
    //printf("alocou\n");

    i=1;
    lista[0]=strtok(texto, " ,\\.\t\n\r");
    pt = strtok(NULL, " ,\\.\t\n\r");
    while(i<n)
    {
        lista[i]=pt;
        pt = strtok(NULL, " ,\\.\t\n\r");
        i++;
        k++;
        //printf("parei %d\n",i);
    }


    for(i=0; i<n; i++) //O fim da string é o limite do for
    {
        if((unsigned)strlen(lista[i])==10)
        {
            contador++;
        }
    }
    *ptMaisquedez = contador;
    //printf("%d",contador);
    //for(i = 0; i < k; i++)
    //{
    //    printf("%s\n",lista[i]);
    //}

    // libera memoria alocada
    free(texto);
    //free(lista);

    // fecha arquivo
    fclose(ft);
}

void menu(char *tarefas, char *s, int *ptPalavra, int *ptEspacos, int *ptTab, int *ptPreposicoes, int *ptMaisquedez)
{
    if(tarefas[0]=='1')
    {
        contaPalavras(s,ptPalavra);
    }
    if(tarefas[1]=='1')
    {
        contaPreposicoes(s,ptPreposicoes);
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
        contaPalavras(s,ptPalavra);
        contaMaisquedez(s,ptMaisquedez,ptPalavra);
    }
}

void imprimir(char *tarefas, char *s, int *ptPalavra, int *ptEspacos, int *ptTab, int *ptPreposicoes, int *ptMaisquedez)
{
    if(tarefas[0]=='1')
    {
        printf("%d\n", *ptPalavra);
    }
    if(tarefas[1]=='1')
    {
        printf("%d\n", *ptPreposicoes);
    }
    if(tarefas[2]=='1')
    {
        printf("%d\n", *ptEspacos);
    }
    if(tarefas[3]=='1')
    {
        printf("%d\n", *ptTab);
    }
    if(tarefas[4]=='1')
    {
        printf("%d\n", *ptMaisquedez);
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

    menu(tarefas,s,ptPalavra,ptEspacos,ptTab,ptPreposicoes,ptMaisquedez);
    imprimir(tarefas,s,ptPalavra,ptEspacos,ptTab,ptPreposicoes,ptMaisquedez);
    //printf("%d",contaPalavra);

    return 0;
}
