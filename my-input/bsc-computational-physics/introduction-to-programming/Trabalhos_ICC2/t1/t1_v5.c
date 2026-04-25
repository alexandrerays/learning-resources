/*
 *  Guilherme Ramos Oliveira NroUSP: 6908006
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
}

void contaPreposicoes(char *s, int *ptPreposicoes,FILE *ft,char *texto, char **lista) //usar strtok
{

}

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
    *ptEspacos = contador;
}

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
    *ptTab = contador;
}

void contaMaisquedez(char *s, int *ptMaisquedez, int *ptPalavra,FILE *ft,char *texto, char **lista)
{
    int k=1,i=0,n, contador=0; // numero de caracteres lidos
    char *pt;

    n = *ptPalavra;
    //printf("n %d\n",n);

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


    // fecha arquivo
}

char* alocaTexto(char *texto,FILE *ft)
{
    char leitura;
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

char** alocaLista(int *ptPalavra)
{
    char **lista;
    int i,n;

    n=*ptPalavra;

    lista = (char**)malloc(sizeof(char*)*n);
    for(i = 0; i < n; i++)
    {
        lista[i] = (char*)malloc(sizeof(char)*50);
    }

    return lista;
}

void menu(char *tarefas, char *s, int *ptPalavra, int *ptEspacos, int *ptTab, int *ptPreposicoes, int *ptMaisquedez,FILE *ft, char *texto)
{
    char **lista;
    //if(tarefas[0]=='1')
    //{
        contaPalavras(s,ptPalavra,ft,texto);
    //}
    if(tarefas[1]=='1')
    {
        lista = alocaLista(ptPalavra);
        contaPreposicoes(s,ptPreposicoes,ft,texto,lista);
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
        //contaPalavras(s,ptPalavra,ft,texto);
        lista = alocaLista(ptPalavra);
        contaMaisquedez(s,ptMaisquedez,ptPalavra,ft,texto,lista);
        free(lista);
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

    texto = alocaTexto(texto,ft);
    //lista = alocaLista(lista,ptPalavra);
    //printf("\n%s\n", texto);
    menu(tarefas,s,ptPalavra,ptEspacos,ptTab,ptPreposicoes,ptMaisquedez,ft,texto);
    imprimir(tarefas,s,ptPalavra,ptEspacos,ptTab,ptPreposicoes,ptMaisquedez);
    //printf("%d",contaPalavra);

    free(texto);
    //free(lista);
    fclose(ft);

    return 0;
}
