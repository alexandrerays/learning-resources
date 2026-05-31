#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>



int main (int argc, char *argv[])
{
    char arquivo[30];
    float tamIntervalo, i;
    int tam;

    for(i=1; i<=10; i++)
    {
        tamIntervalo = 256/i;
        tam = (int) tamIntervalo;
        printf("%d\n", tam);
    }

    return 0;
}
