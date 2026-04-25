#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq;
    char c, str[30], frase[80] = "Este e' um arquivo chamado: ";
    int i;
    
    printf("\nEntre com um nome para o arquivo: ");
    gets(str);
    
    if(!(arq=fopen(str,"w"))) {
        printf("\nErro: Impossivel abrir o arquivo %s\n",str);
        exit(1);
    }
    
    /*concatena frase com str*/
    strcat(frase, str); 
    
    for(i=0;frase[i];i++) {
        putc(frase[i],arq);
    }
    
    /*cria o final do arquivo, nao posso usar rewind antes disso*/
    fclose(arq);
    
   /*faz algo pra poder usar rewind*/
    arq=fopen(str,"r");
    while(!feof(arq)){
         getc(arq);
    }
    
    /*volta o apontador do arquivo para o inicio do arquivo*/
    rewind(arq);
    
    while(!feof(arq)) {
        c = getc(arq);
        printf("%c",c);
    }
    fclose(arq);
    getchar();
    
    return(0);
}
