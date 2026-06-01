//Carlos Fialho
//#7563703
//ICC2 - TURMA B

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define COPY /* if defined, the image is copyed to the memory twice */

typedef char BOOL;
typedef enum //enum of the two possible types of image
{
    P2 = 2,
    P5 = 5
} pgmType;
typedef struct //struct of the image
{
    int width;
    int height;
    int shades;
    unsigned char* bytes;
    pgmType type;
} Image;

BOOL
hasChar(char * string, char aChar) //checks if string contains aChar
{
    int i;
    for (i = 0; string[i] != '\0'; i++)
        if (string[i] == aChar)
            return 1;
    return 0;
}

void
readFile(FILE * stream, char ** fileContent, char readUntil, char * ignoreChars)
{
    char c;
    int count = 0;
    do
    {
        c = fgetc(stream);
        if (hasChar(ignoreChars, c)) continue;
        *fileContent = (char *) realloc(*fileContent, sizeof(char) * (count+1));
        (*fileContent)[count] = c;
        count++;
    } while (c != readUntil);
    (*fileContent)[count-1] = '\0';
}

long
fileReader(char * fileName, unsigned char ** content) // read whole file and returns it's size (withoud \0 at the end)
{
    FILE * file = fopen(fileName, "rb");

    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);

    *content = malloc(fsize);
    fread(*content, fsize, 1, file);
    fclose(file);

    return fsize;
}

char *
getLine(char * text, int start) //gets a line from 'text' starting from 'start'
{
    int i;
    char * line = NULL;
    for (i = start; text[i] != '\n'; i++)
    {
        line = (char*)realloc(line, (i - start) + 2);
        line[(i - start)] = text[i];
    }
    line[(i - start)] = '\0';
    return line;
}

Image *
buildImage(unsigned char * data, long size) //builds a struct for the image
{
    Image * image = (Image*)malloc(sizeof(Image));
    int pos = 0;
    char * line;
    int lineNumber = 0;
    while (1)
    {
        line = getLine((char*)data, pos);
        pos+=strlen(line) + 1;
        if (line[0] == '#'){free(line);continue;}
        if (lineNumber == 0) sscanf(line, "P%d", &image->type);
        else if (lineNumber == 1) sscanf(line, "%d %d", &image->width, &image->height);
        else if (lineNumber == 2){sscanf(line, "%d", &image->shades);free(line); break;};
        lineNumber++;
        free(line);
    }


#ifdef COPY
    image->bytes = (unsigned char *)malloc(sizeof(unsigned char) * image->width * image->height);
    memcpy(image->bytes, &data[pos], image->width * image->height);
#else
    image->bytes = &data[pos];
#endif


    return image;
}

int
countOccurrences(unsigned char * bytes, long size, unsigned char byte)
{
    long i;
    int occurrences = 0;
    for (i = 0; i < size; i++)
        occurrences += (bytes[i] == byte);
    return occurrences;
}

int *
buildHistogram(Image * image, int numberOfBins)
{
    int * histogram = (int*)calloc(sizeof(int), numberOfBins);
    int i;
    for (i = 0; i < image->width * image->height; i++)
    {
        histogram[(int)((((float)(image->bytes[i])) * numberOfBins) / (image->shades+1))]++;
    }
    return histogram;
}

int
main(int argc, const char * argv[])
{
    char * fileName = NULL;
    char * searchByteStr = NULL;
    char * numberOfBinsStr = NULL;
    readFile(stdin, &fileName, '\n', "\r");
    readFile(stdin, &searchByteStr, '\n', "\r");
    readFile(stdin, &numberOfBinsStr, '\n', "\r");
    unsigned char searchByte = atoi(searchByteStr);
    int numberOfBins = atoi(numberOfBinsStr);
    unsigned char * imageBytes;
    long size = fileReader(fileName, &imageBytes);
    Image * image = NULL;
    image = buildImage(imageBytes, size);
    printf("%d\n", image->width);
    printf("%d\n", image->height);
    printf("%d\n", image->shades);
    printf("%d\n", image->width * image->height);
    printf("%d\n", countOccurrences(image->bytes, image->width * image->height, searchByte));
    int i;
    int * histogram = buildHistogram(image, numberOfBins);
    for (i = 0; i < numberOfBins; i++)
    {
        if (i != numberOfBins - 1)
            printf("%d ", histogram[i]);
        else
            printf("%d\n", histogram[i]);
    }
#ifdef COPY
    free(image->bytes);
#endif
    free(histogram);
    free(image);
    free(imageBytes);
    free(fileName);
    free(searchByteStr);
    free(numberOfBinsStr);

    return 0;
}
