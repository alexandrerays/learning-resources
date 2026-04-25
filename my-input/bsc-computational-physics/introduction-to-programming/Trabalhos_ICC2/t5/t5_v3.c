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

int compara(const void *a, const void *b)
{
    if((int*)a>(int*b))return 1;
    if((int*)a<(int*b))return -1;
    return 0;
}

/*int separa( int *v, int p, int r)
{
   int c = v[p], i = p+1, j = r, t;
   while ( i <= j) {
      if (v[i] <= c) ++i;
      else if (c < v[j]) --j;
      else {
         t = v[i], v[i] = v[j], v[j] = t;
         ++i; --j;
      }
   }
   // agora i == j+1
   v[p] = v[j], v[j] = c;
   return j;
}

void quickSort( int *v, int p, int r)
{
   int j;
   while (p < r) {
      j = separa( v, p, r);
      if (j - p < r - j) {
         quickSort( v, p, j-1);
         p = j + 1;
      } else {
         quickSort( v, j+1, r);
         r = j - 1;
      }
   }
}*/

//olhar essa funcao. Depois ainda preciso criar outra funcao pra ordenar os indices de acordo com os nros de zero
void nroZerosSubimagem(int width, int height, char saida[])
{
    char line[100];
    FILE *ft = fopen(saida, "rb");
    int i, j,k,indice=0; //ind_inicio;
    //int ShouldQuit=0;
    unsigned char *imThres;
    //Subimagem sub[16]; //16 subimagens, contagem comeca do zero

    for(i=0; i<4; i++)
    {
        fgets(line, sizeof(line), ft);
    }

    imThres = (unsigned char *) malloc(sizeof(char)*width*height);
    fread(imThres, sizeof(unsigned char), width * height, ft);

    int *listaID;
    //int elemBlocos=(width*height)/4;

    //listaID = (int **)malloc(sizeof(int*)*16);
    listaID = (Subimagem *)calloc(16,sizeof(Subimagem));

    /*for(i=0; i<16; i++){
        listaID[i] = 0; //tacar calloc
    }*/

    j=0;
    while(j<width*height)
    {
        for(i=0; i<height/4; i++)
        {
            for(j,k=0; k<width/4; j++,k++)
            {
                if(imThres[j]==0)
                {
                    listaID[indice]++;
                }
            }
            for(j,k=0; k<width/4; j++,k++)
            {
                if(imThres[j]==0)
                {
                    listaID[indice+1]++;
                }
            }
            for(j,k=0; k<width/4; j++,k++)
            {
                if(imThres[j]==0)
                {
                    listaID[indice+2]++;
                }
            }
            for(j,k=0; k<width/4; j++,k++)
            {
                if(imThres[j]==0)
                {
                    listaID[indice+3]++;
                }
            }
        }
        indice+=width;
    }

    qsort(listaID, 16,sizeof(int), compara);
    for(i=0; i<16; i++)
    {
        printf("%d\t%d\n", i+1, listaID[i]);
        //fprintf(stderr, "%d\t%d\n", i+1, listaID[i]);
    }

    fclose(ft);
    free(listaID);
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

