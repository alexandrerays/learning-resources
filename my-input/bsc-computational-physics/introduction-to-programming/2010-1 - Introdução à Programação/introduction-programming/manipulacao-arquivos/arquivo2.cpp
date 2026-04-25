/**Preenche um arquivo com a string do usuario          */
/**Emanuel Valente - aka - Tourinho emanuel.valente@usp.br   */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *fp;
    
    char str[100];
    int i;
    
    if(argc==1){
        printf("\nVoce esqueceu de colocar o nome do arquivo!");
        getchar();
        exit(0);
    }
    
    if((fp=fopen(argv[1],"w"))==NULL) {
        printf("\nErro na abertura do arquivo!");
        getchar();
        exit(0);
    }
    
    printf("\nEntre com a string a ser gravada no arquivo: ");
    gets(str);
    
    for(i=0;str[i];i++) {
        putc(str[i], fp);
    }
    
    fclose(fp);
    return(0);
}
