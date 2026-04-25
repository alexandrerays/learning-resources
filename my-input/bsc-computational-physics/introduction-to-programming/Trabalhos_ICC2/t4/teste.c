#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char line[100];
    int width, height, maxval;
    unsigned char* image;
    unsigned int* histo;
    int i;
    FILE *fd;

    fd = fopen(argv[1], "rb");
    if (fd == NULL) {
        printf("could not open image file\n");
        exit(1);
    }

    // magic number
    fgets(line, sizeof(line), fd);
    if (strcmp(line, "P5\n") != 0) {
        printf("image is not in PGM format!\n");
        fclose(fd);
        exit(1);
    }

    // skip comment
    fgets(line, sizeof(line), fd);

    // read header
    if (fscanf(fd, "%d %d %d\n", &width, &height, &maxval) != 3) {
        printf("invalid header\n");
        fclose(fd);
        exit(1);
    }
    if (maxval > 255) {
        printf("sorry, only 8-bit PGMs are supported at this time!\n");
        fclose(fd);
        exit(1);
    }

    printf("width: %d\nheight: %d\nmaxval: %d\n", width, height, maxval);

    // read image data
    image = malloc(width * height);
    if (fread(image, sizeof(unsigned char), width * height, fd) != width * height) {
        printf("could not read image\n");
        fclose(fd);
        exit(1);
    }
    fclose(fd);

    // compute histogram
    histo = (int*)calloc(maxval+1, sizeof(int));
    for (i = 0; i < width * height; i++)
        histo[image[i]]++;

    // print histogram
    for (i = 0; i <= maxval; i++)
        printf("Color number %d count %d\n", i, histo[i]);

    // release memory
    free(image);
    free(histo);
}
