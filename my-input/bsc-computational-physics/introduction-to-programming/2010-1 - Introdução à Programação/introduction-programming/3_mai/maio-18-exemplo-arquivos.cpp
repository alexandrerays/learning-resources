#include<stdio.h>
#include<stdlib.h>

main(){
       FILE *fp;
       char string[100];
       int i;
       if((fp=fopen("arquivo.txt","w"))==NULL){
                                               //arquivo ASCII, para escrita
                                               printf("Erro na abertura do arquivo\n");
                                               exit(0);
                                               }
                                               
       printf("Entre com a string a ser gravada no arquivo\n");
       gets(string);
       for(i=0;string[i];i++)putc(string[i], fp);
       //grava a string, caractere a caractere
       fclose(fp);
       
       }
