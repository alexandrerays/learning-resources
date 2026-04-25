/* Codigo fonte que pode ser usado como ponto de partida para
 * o desenvolvimento do trabalho 1 
 *
 * Moacir Ponti -- ICMC/USP 2013
 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

    // abre um arquivo no formato leitura (r - read) texto
    FILE *ft = fopen("arquivo.txt","r");
    
    // aloca 1 byte (1 char)
    char *texto = (char *) malloc(sizeof(char));
    
    char leitura; // variavel temporaria para ler arquivo caracter por caracter
    
    int c = 0; // numero de caracteres lidos
    
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
    
    // imprime string completa
    printf("\n%s\n", texto);
    
    // libera memoria alocada
    free(texto);
    
    // fecha arquivo
    fclose(ft);
    
    return 0;
}

