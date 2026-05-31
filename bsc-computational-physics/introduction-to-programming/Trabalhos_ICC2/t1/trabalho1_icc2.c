/*  Trabalho 1 de SCC0201 Introducao a Ciencia da Computacao II
 *  Turma BCC-A
 *  Prof. Moacir
 *  Guilherme Ramos Oliveira NroUSP: 6908006
 *  Data: 05-08-2013
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//conta o numero de palavras no arquivo - Item 1 do trabalho
void contaPalavras(char *s, int *ptPalavra,FILE *ft,char *texto) //OK
{
    int i, contador=0; // numero de caracteres lidos

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
        if(texto[i]=='.' || texto[i]==',') //delimitadores ponto e virgula sao verificados
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
    *ptPalavra = contador; //numero de palavras no texto
}

//conta o numero de preposicoes no arquivo, de acordo com uma lista pre definida - Item 2 do trabalho
//essa funcao gera segmentation fault e nao consegui solucionar o problema
void contaPreposicoes(char *s, int *ptPreposicoes,FILE *ft,char *texto, char **lista,int *ptPalavra)
{
    char dicionario[18][30+1] = {{"a"},{"ante"},{"até"},{"após"},{"com"},{"contra"},{"de"},{"desde"},{"em"},{"entre"},{"para"},{"per"},
        {"perante"},{"por"},{"sem"},{"sob"},{"sobre"},{"trás"}
    };
    int i, j,ocorrencia=0, tamLista; //flag=0,

    tamLista = *ptPalavra;

    for(j=0; j<18; j++)
    {
        for(i=0; i<tamLista; i++) // i< tamanho da lista
        {
            if(strcmp(lista[i], dicionario[j])==0) /*a palavra esta no dicionario de preposicoes? */
            {
                ocorrencia++;
            }
        }
    }
    *ptPreposicoes = ocorrencia; //numero de preposicoes no texto, de acordo com dicionario pre definido
}

//conta o numero de espacos no arquivo - Item 3 do trabalho
void contaEspacos(char *s, int *ptEspacos,FILE *ft,char *texto) //OK
{
    int i, contador=0; // numero de caracteres lidos

    for(i=0; texto[i]!='\0'; i++) /*O fim da string é o limite do for*/
    {
        if(texto[i]==' ') /*s[i] é espaço, \t, \n \r ? */
        {
            contador++;
            continue;
        }
        continue;

    }
    *ptEspacos = contador; //numero de ocorrencias de espaco no texto
}

//conta o numero de tabulacoes no arquivo - Item 4 do trabalho
void contaTab(char *s, int *ptTab,FILE *ft,char *texto) //OK
{
    int i, contador=0; // numero de caracteres lidos

    for(i=0; texto[i]!='\0'; i++) /*O fim da string é o limite do for*/
    {
        if(texto[i]=='\t') /*s[i] é espaço, \t, \n \r ? */
        {
            contador++;
            continue;
        }
        continue;
    }
    *ptTab = contador; //numero de ocorrencias de tabulacoes no texto
}

//conta o numero de palavras com mais de 10 caracteres no arquivo - Item 5 do trabalho
void contaMaisquedez(char *s, int *ptMaisquedez, int *ptPalavra,FILE *ft,char *texto, char **lista) //OK
{
    int i=0,n, contador=0; // numero de caracteres lidos

    n = *ptPalavra;

    for(i=0; i<n; i++) //O fim da string é o limite do for
    {
        if((unsigned)strlen(lista[i])>10)
        {
            contador++;
        }
    }
    *ptMaisquedez = contador; //numero de palavras com mais de 10 caracteres
}

//aloca uma string pra armazenar o texto do arquivo
char* alocaTexto(FILE *ft) //OK
{
    char leitura, *texto;
    int c=0;

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
    return texto;
}

//aloca uma matriz para armazenar as palavras do texto
char** alocaLista(int *ptPalavra, char *texto)  //OK
{
    char **lista;
    int k=1,i=0,n, contador=0; // numero de caracteres lidos
    char *pt;

    n = *ptPalavra;

    lista = (char**)malloc(sizeof(char*)*n);
    for(i = 0; i < n; i++)
    {
        lista[i] = (char*)malloc(sizeof(char)*50);
    }

    i=1;
    lista[0]=strtok(texto, " ,\\.\t\n\r"); //strtok auxilia na separacao das palavras para armazena-las na lista
    pt = strtok(NULL, " ,\\.\t\n\r");
    while(i<n)
    {
        lista[i]=pt;
        pt = strtok(NULL, " ,\\.\t\n\r");
        i++;
        k++;
    }
    return lista;
}

//menu que escolhe as tarefas de acordo com a entrada de dados via stream
void menu(char *tarefas, char *s, int *ptPalavra, int *ptEspacos, int *ptTab, int *ptPreposicoes, int *ptMaisquedez,FILE *ft)  //OK
{
    char **lista, *texto;

    texto = alocaTexto(ft);
    if(tarefas[0]=='1')
    {
        contaPalavras(s,ptPalavra,ft,texto);
    }
    if(tarefas[1]=='1')
    {
        if(tarefas[0]=='0')
        {
            contaPalavras(s,ptPalavra,ft,texto);
        }
        lista = alocaLista(ptPalavra,texto);
        contaPreposicoes(s,ptPreposicoes,ft,texto,lista,ptPalavra);
        free(lista);
    }
    if(tarefas[2]=='1')
    {
        contaEspacos(s,ptEspacos,ft,texto);
    }
    if(tarefas[3]=='1')
    {
        contaTab(s,ptTab,ft,texto);
    }
    if(tarefas[4]=='1')
    {
        if(tarefas[0]=='0')
        {
            contaPalavras(s,ptPalavra,ft,texto);
        }
        lista = alocaLista(ptPalavra,texto);
        contaMaisquedez(s,ptMaisquedez,ptPalavra,ft,texto,lista);
        free(lista);
    }
    free(texto);
}

//imprime o resultado das tarefas escolhidas
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

//funcao principal
int main (int argc, char *argv[])
{
    char s[100], tarefas[5], *texto;
    int contaPalavra,contaEspacos,contaTab,contaPreposicoes,contaMaisquedez;
    int *ptPalavra = &contaPalavra, *ptEspacos = &contaEspacos;
    int *ptTab = &contaTab,*ptPreposicoes = &contaPreposicoes, *ptMaisquedez = &contaMaisquedez;
    FILE *ft;

    //puts("Introduza o nome do arquivo: ");
    gets(s);
    // abre um arquivo no formato leitura (r - read) texto
    ft = fopen(s,"r");
    //puts("Digite as tarefas que serao executadas: ");
    gets(tarefas);

    //lista = alocaLista(lista,ptPalavra);
    //printf("\n%s\n", texto);
    menu(tarefas,s,ptPalavra,ptEspacos,ptTab,ptPreposicoes,ptMaisquedez,ft);
    imprimir(tarefas,s,ptPalavra,ptEspacos,ptTab,ptPreposicoes,ptMaisquedez);

    fclose(ft);

    return 0;
}
