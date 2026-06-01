#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
FILE*p;
char c, str[30],frase[80]="este e um arquivo chamado :";
int i;
//le um arquivo para o arquivo a ser aberto

printf("\n\n entre com um nome para arquivo :\n");
gets(str);

if(!(p=fopen(str,"w")))
                       { //programa aborta automaticamente
                       printf("ERRO!IMPOSSIVEL ABRIR O ARQUIVO!\n");
                       exit(1);
                       //se nao houve erro , imprime no arquivo e o fecha...
                       strcat(frase,str);
                              for(i=0;frase[i];i++)
                                                   putc(frase[i],p);
                       fclose(p);
                       //abre novamente para leitura
                       p=fopen(str,"r");
                                        while(!feof(p)){
                                        //enquanto nao chegar no final do arquivo
                                        c=getc(p);
                                        //le um caracter no arquivo
                                        printf("%c",c);
                                        //o imprime na tela
                                        }

fclose(p);//fecha o arquivo
                  }
                  
}
