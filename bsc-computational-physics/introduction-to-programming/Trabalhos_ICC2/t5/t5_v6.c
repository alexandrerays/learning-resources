/* Trabalho 5 de ICC2
 * Aluno Guilherme Ramos Oliveira
 * Turma BCC A
 * Professor Moacir Ponti
 * Data 7 de Setembro de 2013

  calcular qtos pixels da cor preta tem naquele espaço
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


/*struct que armazena a ID da subimagem e contem uma variavel pra contar o nro de zeros presentes nessa subimagem
 * novo tipo Subimagem*/
typedef struct
{
    int id;
    int nroZeros;
} Subimagem;

/*funcao que compara dois elementos da subimagem, no caso, as variaveis que armazenam a quantidade de zeros de cada subimagem*/
int compara(const void *a, const void *b)
{
    if(((Subimagem*)a)->nroZeros>((Subimagem*)b)->nroZeros)return 1;
    if(((Subimagem*)a)->nroZeros<((Subimagem*)b)->nroZeros)return -1;
    if(((Subimagem*)a)->nroZeros==((Subimagem*)b)->nroZeros)return 0;
}

/*funcao que abre a imagem com o filtro threshold, aloca um vetor do tipo Subimagem com 16 posicoes,
* calcula o nro de zeros de cada subimagem e chama a funcao qsort para
* ordenar os IDs por ordem crescente de nro de zeros
*/
Subimagem *nroZerosSubimagem(int width, int height, char saida[])
{
    char line[100];
    FILE *ft = fopen(saida, "rb");
    int i, j,x,y,indice=0, flag=0;
    unsigned char *imThres;

    for(i=0; i<4; i++)
    {
        fgets(line, sizeof(line), ft);
    }

    imThres = (unsigned char *) malloc(sizeof(char)*width*height);
    fread(imThres, sizeof(unsigned char), width * height, ft);

    Subimagem *listaID;

    listaID = (Subimagem *)calloc(16,sizeof(Subimagem)); //calloc zera todo o espaco reservado para os elementos da struct alocada

    for(i=0; i<16; i++)
    {
        listaID[i].id=i+1;
    }

    for(j=0; j<4; j++)
    {
        for(i=0; i<4; i++)
        {
            for(y=i*height/4; y <(i+1)*height/4; y++)
            {
                for(x=j*width/4; x < (j+1)*width/4; x++)
                {
                    if(imThres[y*width+x]==0)
                    {

                        listaID[i*4+j].nroZeros++;
                    }
                }
            }
        }
    }

    qsort(listaID, 16,sizeof(Subimagem), compara);
    /*for(i=0; i<16; i++)
    {
        printf("%d\t%d\n", listaID[i].id, listaID[i].nroZeros);
    }*/

    fclose(ft);
    //free(listaID);
    free(imThres);

    return listaID;
}

/*funcao que gera a imagem de saida com o filtro threshold*/
void geraImagem(unsigned char *imThresHold, int width, int height, int maxGray, char saida[])
{
    int i;
    FILE *fsaida = fopen(saida, "wb");

    fprintf(fsaida, "%s", "P5\n# Created by Trabalho 05\n");
    fprintf(fsaida, "%d %d\n", width,height);
    fprintf(fsaida, "%d\n", maxGray);

    fwrite(imThresHold,sizeof(unsigned char), width * height, fsaida);

    fclose(fsaida);
}

/*funcao que aplica o filtro threshold em uma imagem, de acordo com um limiar recebido na entrada*/
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

/*funcao que le o cabecalho do arquivo de imagem pgm e pega os valores de largura da imagem,
* algura da imagem, valor max de escala de cinza da imagem e
* passa esses valores para a funcao threshold. Apos a aplicacao do filtro, a funcao que gera a nova imagem eh chamada.
* Por fim, a funcao nroZerosSubimagem eh chamada e calcula o nro de zeros que cada subimagem possui
*/
Subimagem *analisaImagem(int a, char entrada[], char saida[])
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

    imThresHold = threshold(image,width,height,maxGray,a);

    geraImagem(imThresHold,width,height,maxGray,saida);


    fclose(fd);
    free(image);
    free(imThresHold);

    return nroZerosSubimagem(width,height,saida);
}

//funcao principal
int main (int argc, char *argv[])
{
    char entrada[30], saida[30];
    int a,i;
    Subimagem *lista;

    scanf("%s", entrada);
    scanf("%d", &a);
    scanf("%s", saida);

    lista = analisaImagem(a,entrada,saida);
    for(i=0; i<16; i++)
    {
        printf("%d\t%d\n", lista[i].id, lista[i].nroZeros);
    }

    free(lista);
    return 0;
}

