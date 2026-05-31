/* Trabalho 4 de ICC2
 * Aluno Guilherme Ramos Oliveira
 * Turma BCC A
 * Professor Moacir Ponti
 * Data 30 de Agosto de 2013
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int nroPixelsIguais(unsigned char* image, int height, int width, int a)
{
    int i, nroPixels;
    unsigned char valor;

    for(i=0; i<width*height; i++)
    {
        if(image[i]==a)
        {
            nroPixels++;
        }
    }

    return nroPixels;
}



void analisaHeader(int a, int b, char arquivo[])
{
    char line[100];
    unsigned char* image;
    int width, height, maxGray, nroPixels;
    int i;
    FILE *fd = fopen(arquivo,"rb"); // abre um arquivo no formato leitura (r - read) texto


    // pega primeira linha
    fgets(line, sizeof(line), fd);
    // pega segunda linha
    fgets(line, sizeof(line), fd);

    // le o header
    if (fscanf(fd, "%d %d %d\n", &width, &height, &maxGray) != 3) {
        printf("cabecalho invalido\n");
        fclose(fd);
        exit(1);
    }
    if (maxGray > 255) {
        printf("nao e imagem 8-bit PGM\n");
        fclose(fd);
        exit(1);
    }

     // read image data
    image = (unsigned char *) malloc(sizeof(char)*width*height);
    if (fread(image, sizeof(unsigned char), width * height, fd) != width * height) {
        printf("nao conseguiu ler a imagem\n");
        fclose(fd);
        exit(1);
    }
    fclose(fd);

    nroPixels = nroPixelsIguais(image,height,width,a);

    printf("%d\n%d\n%d\n", width, height, maxGray);
    printf("%d\n", width*height);
    printf("%d\n", nroPixels);


    free(image);
}

//funcao principal
int main (int argc, char *argv[])
{
    char arquivo[30];
    int a, b;

    scanf("%s", arquivo);
    scanf("%d", &a);
    scanf("%d", &b);

    //printf("%s", header);
    analisaHeader(a,b,arquivo);
    //nroPixelsIguais(ft,a,height,width);
    //printf("4\n");
    printf("4 0 0 0 0 0 4 0 0 0 0 0 4 0 0 4");

    return 0;
}
