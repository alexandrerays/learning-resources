/* Trabalho 4 de ICC2
 * Aluno Guilherme Ramos Oliveira
 * Turma BCC A
 * Professor Moacir Ponti
 * Data 30 de Agosto de 2013

 histograma - calcular qtos pixels de cada cor existem na imagem
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


//funcao que calcula o numero de pixels da imagem que sa iguais ao valor A fornecido como entrada
int nroPixelsIguais(unsigned char* image, int height, int width, int a)
{
    int i, nroPixels;


    for(i=0; i<width*height; i++)
    {
        if(image[i]==a)
        {
            nroPixels++;
        }
    }

    return nroPixels;
}

//funcao que calcula o histograma da imagem e o numero de repeticoes dos valores do histograma em cada bin
//tarefa 6 do trabalho
void analisaImagem(unsigned char* image,int width, int height, int maxGray, int a, int b)
{
    int i=0,j=0,contador=0;
    int* histo;
    unsigned char *p;
    float tamIntervalo=0, tam, tam2, aux;

    // gera o histograma
    histo = (int*)calloc(sizeof(int), b);

    p = image;

	for	(i=0; i<width*height; i++)
    {
        histo[(int)(((float)(*p++)) * b) / (maxGray+1)]++;
    }

	/*for(i=0; i<maxGray; i++)
    {
        printf("%d ", histo[i]) ;
    }*/

    for (i = 0; i < b; i++)
    {
        if (i != b - 1)
            printf("%d ", histo[i]);
        else
            printf("%d\n", histo[i]);
    }

    free(histo);
}

//funcao que le o cabecalho do arquivo de imagem pgm e pega os valores de largura da imagem,
//algura da imagem, valor max de escala de cinza da imagem
//esta funcao tambem calcula o numero de pixels da imagem a partir da multiplicacao da largura com a altura
void analisaHeader(int a, int b, char arquivo[])
{
    char line[100];
    unsigned char* image;
    int width, height, maxGray, nroPixels=0;
    int i;
    FILE *fd = fopen(arquivo,"rb");

    // pega primeira linha
    fgets(line, sizeof(line), fd);
    // pega segunda linha
    fgets(line, sizeof(line), fd);

    // le o header
    fscanf(fd, "%d %d %d\n", &width, &height, &maxGray);

    // le o conteudo da imagem
    image = (unsigned char *) malloc(sizeof(char)*width*height);
    fread(image, sizeof(unsigned char), width * height, fd);

    nroPixels = nroPixelsIguais(image,height,width,a);

    //imprime as 5 primeiras tarefas do trabalho
    printf("%d\n%d\n%d\n", width, height, maxGray);
    printf("%d\n", width*height);
    printf("%d\n", nroPixels);

    analisaImagem(image,width,height,maxGray,a,b);

    fclose(fd);
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

    analisaHeader(a,b,arquivo);

    return 0;
}
