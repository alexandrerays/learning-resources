#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
    char line[100];
    FILE *fd = fopen("saida.pgm","rb");
    int i;

    for(i=0; i<4; i++)
    {
         // pega primeira linha
        fgets(line, sizeof(line), fd);
        printf("%s", line);
    }






    return 0;
}

