/* Trabalho 5 de ICC2
 * Aluno Guilherme Ramos Oliveira
 * Turma BCC A
 * Professor Moacir Ponti
 * Data 7 de Setembro de 2013
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int id;
    int nroZeros;
} Subimagem;


//olhar essa funcao. Depois ainda preciso criar outra funcao pra ordenar os indices de acordo com os nros de zero
void nroZerosSubimagem(int width, int height, char saida[])
{
    char line[100];
    FILE *ft = fopen(saida, "rb");
    int i, j;
    int ShouldQuit=0;
    unsigned char *imThres;
    Subimagem sub[16]; //16 subimagens, contagem comeca do zero

    for(i=0; i<4; i++)
    {
        fgets(line, sizeof(line), ft);
    }

    imThres = (unsigned char *) malloc(sizeof(char)*width*height);
    fread(imThres, sizeof(unsigned char), width * height, ft);

    //imThres[width*height]='\0';

    //for(i=0; imThres[i]!='\0'; i++)
    /*for(i=0; i<width*height; i++)
    {
        printf("%d", imThres[i]);
    }*/

    for(i=0; i<16; i++)
    {
        sub[i].id=i+1;
        sub[i].nroZeros=0;
    }

    int grupo=width/4;
    int gLinha=0;
    int gColuna=0;
    int indice=0;
    j=0;

    while(!ShouldQuit)
    {
        for(j; j<height; j++)
        {
            for(j; j<width; j++)
            {

                if(j>=width*height)
                {
                    ShouldQuit=1;
                    break;
                }
                if(imThres[j]==0)
                {
                    sub[indice].nroZeros++;
                }
                gColuna++;
                if(gColuna==grupo)
                {
                    indice++;
                    gColuna=0;
                }

            }

            if(j>=width*height)
            {
                //ShouldQuit=1;
                break;
            }
            gLinha++;
            if(gLinha<grupo)
            {
                indice-=3;
                gLinha=0;
            }
            if(gLinha==grupo)
            {
                indice+=1;
                gLinha=0;
            }
        }
    }

    for(i=0; i<16; i++)
    {
        printf("%d\t%d\n", sub[i].id, sub[i].nroZeros);
    }

    fclose(ft);
    free(imThres);


}

void geraImagem(unsigned char *imThresHold, int width, int height, int maxGray, char saida[])
{
    int i;
    FILE *fsaida = fopen(saida, "wb");

    fprintf(fsaida, "%s", "P5\n# Created by Trabalho 05\n");
    fprintf(fsaida, "%d %d\n", width,height);
    fprintf(fsaida, "%d\n", maxGray);

    fwrite(imThresHold,sizeof(unsigned char), width * height, fsaida);
    /*for(i=0; i<width*height; i++)
    {
        fwrite(imThresHold+i,sizeof(unsigned char), 1, fsaida);
    }*/

    fclose(fsaida);
}

//funcao que calcula o histograma da imagem e o numero de repeticoes dos valores do histograma em cada bin
//tarefa 6 do trabalho
unsigned char* threshold(unsigned char* image,int width, int height, int maxGray, int a)
{
    int i;
    unsigned char* imThres = (unsigned char *) malloc(sizeof(char)*width*height);

    for	(i=0; i<width*height; i++)
    {
        if(image[i]>=a)
        {
            imThres[i]=maxGray;
        }
        else
        {
            imThres[i]=0;
        }
    }

    return imThres;
}

//funcao que le o cabecalho do arquivo de imagem pgm e pega os valores de largura da imagem,
//algura da imagem, valor max de escala de cinza da imagem
//esta funcao tambem calcula o numero de pixels da imagem a partir da multiplicacao da largura com a altura
void analisaImagem(int a, char entrada[], char saida[])
{
    char line[100];
    unsigned char *image, *imThresHold;
    int width, height, maxGray;
    int i;
    FILE *fd = fopen(entrada,"rb");

    // pega primeira linha
    fgets(line, sizeof(line), fd);
    // pega segunda linha
    fgets(line, sizeof(line), fd);

    // le as dimensoes e nivel max de cinza
    fscanf(fd, "%d %d %d\n", &width, &height, &maxGray);

    // le o conteudo da imagem
    image = (unsigned char *) malloc(sizeof(char)*width*height);
    fread(image, sizeof(unsigned char), width * height, fd);

    //nroPixels = nroPixelsIguais(image,height,width,a);
    imThresHold = threshold(image,width,height,maxGray,a);

    geraImagem(imThresHold,width,height,maxGray,saida);
    nroZerosSubimagem(width,height,saida);

    fclose(fd);
    free(image);
    free(imThresHold);
}

//funcao principal
int main (int argc, char *argv[])
{
    char entrada[30], saida[30];
    int a;

    scanf("%s", entrada);
    scanf("%d", &a);
    scanf("%s", saida);

    analisaImagem(a,entrada,saida);

    return 0;
}

