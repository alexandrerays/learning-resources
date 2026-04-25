#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, cont=0;
    char str[50];

    printf("Entre com uma String: ");
    scanf("%s", str);

    for(i=0; str[i]!='\0'; i=i+1) {
        if(str[i]=='a')
            cont=cont+1;
    }
    printf("O numero de caracteres a eh: %d\n", cont);
}