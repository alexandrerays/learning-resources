/* Codigo fonte que pode ser usado como ponto de partida para
 * o desenvolvimento do trabalho 1
 *
 * Guilherme Ramos Oliveira NroUSP: 6908006
 */

#include <iostream>
#include <fstream>
#include <string>
#include <new>

int contaPalavras(char *s, int *ptPalavra)
{
    char *texto, leitura;
    int c=0, i, contador=0; // numero de caracteres lidos
    FILE *ft;

    ft = fopen(s,"r");

    // aloca 1 byte (1 char)
    texto = (char *) malloc(sizeof(char));

    // fgetc -> le 1 byte do arquivo e armazena na variavel (lvalue)
    // quando o retorno for EOF, significa que o arquivo terminou (End Of File)
    while ((leitura = fgetc(ft)) != EOF) {

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
    printf("\n%s\n", texto);
    for(i=0; texto[i]!='\0'; i++) /*O fim da string é o limite do for*/
    {
        if(isalnum(texto[i]))  /*s[i] é caracter alfabético? */
        {
            continue;
        }
        if(isspace(texto[i])) /*s[i] é espaço, \t, \n \r ? */
        {
            if(ispunct(texto[i-1]) || isspace(texto[i-1]) || texto[i-1]=='\u2014')
            {
                continue;
            }
            else
            {
                contador++;
                continue;
            }
        }
        if(ispunct(texto[i]))
        {
            if(ispunct(texto[i-1]) || isspace(texto[i-1]) || texto[i-1]=='\u2014')
            {
                continue;
            }
            else
            {
                contador++;
                continue;
            }
        }
        if(texto[i-1]=='\u2014')
        {
            if(ispunct(texto[i-1]) || isspace(texto[i-1]) || texto[i-1]=='\u2014')
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

int contaPreposicoes() //usar strtok
{
    return 0;
}

int contaEspacos()
{
    return 0;
}

int contaTab()
{
    return 0;
}

int contaMaisquedez()//usar strlen
{
    return 0;
}

void menu(char *tarefas, char *s, int *ptPalavra)
{
    char opcoes[5];

    strcpy(opcoes,tarefas);
    if(strcmp("00000",opcoes)==0){
        printf("Digite pelo menos alguma tarefa para ser realizada.\n");
        puts("Digite as tarefas que serao executadas: \n");
        gets(opcoes);
        menu(opcoes,s,ptPalavra);
    }
    if(tarefas[0]=='1'){
        contaPalavras(s,ptPalavra);
    }
    if(tarefas[1]=='1'){
        contaPreposicoes();
    }
    if(tarefas[2]=='1'){
        contaEspacos();
    }
    if(tarefas[3]=='1'){
        contaTab();
    }
    if(tarefas[4]=='1'){
        contaMaisquedez();
    }
}

int main (int argc, char *argv[]) {

    char s[100], tarefas[5];
    int contaPalavra;
    int *ptPalavra = &contaPalavra;

    puts("Introduza o nome do arquivo: ");
    gets(s);
    // abre um arquivo no formato leitura (r - read) texto

    puts("Digite as tarefas que serao executadas: ");
    gets(tarefas);

    menu(tarefas,s,ptPalavra);
    printf("%d\n", contaPalavra);

    return 0;
}

