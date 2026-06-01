//Carlos Fialho
//#7563703
//ICC2 - TURMA B

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>


//#define TESTE

#ifdef TESTE
    #define myLog(...) printf(__VA_ARGS__);
#else
    #define myLog(...)
#endif



#define isContinuationChar(char) (char >= 128 && char <= 191)
#define DELIMITERS " .\t\n\r,"
#define PREPOSITIONS {"a", "ante", "até", "após", "com",\
"contra", "de", "desde", "em", "entre", "para", "per",\
"perante", "por", "sem", "sob", "sorte", "trás"}
#define NUMBER_OF_PREPOSITIONS 18
#define NUMBER_OF_INSTRUCTIONS 5
typedef enum
{
    WordCount        = 1 << 4,
    PrepositionCount = 1 << 3,
    SpaceCount       = 1 << 2,
    TabCount         = 1 << 1,
    LongWordCount    = 1 << 0
} Instructions;
typedef char BOOL;


char * readFromStdin();
char * fileReader(char *);
BOOL isWordDelimiter(char);
unsigned long adiacriticStrlen(char *);

int wordCounter(char *, int);
int prepositionCounter(char *);
int charCounter(char *, char);

char *
readFromStdin()
{
    char * string = malloc(sizeof(char));
    string[0] = '\0';
    while(1)
    {
        char thisChar;
        scanf("%c", &thisChar);
        if (thisChar == '\r') continue;
        if (thisChar == '\n') break;
        string = (char *)realloc(string, sizeof(char) * (strlen(string) + 2));
        string[strlen(string) + 1] = '\0';
        string[strlen(string)] = thisChar;
    }
    return string;
}

char *
fileReader(char * fileName)
{
    errno = 0;
    FILE * file = fopen(fileName, "r");
    if (!file)
    {
        myLog("\nError opening file \"%s\": %s \n", fileName, strerror(errno));
        exit(1);
    }
    
    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char *string = malloc(fsize + 1);
    fread(string, fsize, 1, file);
    fclose(file);
    
    string[fsize] = '\0';
    return string;
}

BOOL
isWordDelimiter(char aChar)
{
    static const char delimiters[] = DELIMITERS;
    int i;
    for (i = 0; delimiters[i] != '\0'; i++)
        if (aChar == delimiters[i]) return 1;
    return 0;
}

unsigned long
adiacriticStrlen(char * input)
{
    int i;
    unsigned long length = 0;
    for (i = 0; input[i] != '\0'; i++)
    {
        unsigned char thisChar = input[i];
        if (isContinuationChar(thisChar)) continue;
        length++;
    }
    return length;
}

int
wordCounter(char * input, int length)
{
    int words = 0;
    BOOL isBuildingWord = 0;
    int lenOfWord = 0;
    int i;
    for (i = 0; input[i] != '\0'; i++)
    {
        unsigned char thisChar = input[i];
        if (isContinuationChar(thisChar)) continue;
        if (!isWordDelimiter(thisChar))
        {
            isBuildingWord = 1;
            lenOfWord++;
            myLog("%c", thisChar);
        }
        else if (isBuildingWord)
        {
            isBuildingWord = 0;
            words += (lenOfWord > length);
            lenOfWord = 0;
            myLog("|0x%x|\n", thisChar);
        }
    }
    if (isBuildingWord)
    {
        words += (lenOfWord > length);
        myLog("|0x%x|", '\0');
    }
    myLog("\n");
    return words;
}


int
prepositionCounter(char * input)
{
    static const char * prepositions[] = PREPOSITIONS;
    int prepositionsCount = 0;
    int i;
    for (i = 0; i < NUMBER_OF_PREPOSITIONS; i++)
    {
        char * substring = strstr(input, prepositions[i]); // find next occurrence of preposition
        if (substring == NULL) continue; // preposition not found: continue
        do
        {       // first char       or predecessor char is delimiter
            myLog("substring == input:%d\n", (substring == input));
            if ((substring == input || isWordDelimiter(substring[-1])) &&
                // char after preposition ||
                (isWordDelimiter(substring[strlen(prepositions[i])]) ||
                 //last char
                 substring[strlen(prepositions[i])] == '\0'))
            {
                prepositionsCount++;
            }
        }while ((substring = strstr(substring+strlen(prepositions[i]), prepositions[i])));
    }
    return prepositionsCount;
}

int
charCounter(char * input, char aChar)
{
    int occurrences = 0;
    int i;
    for (i = 0; input[i] != '\0'; i++)
        occurrences += input[i] == aChar;
    return occurrences;
}

int
main(int argc, const char * argv[])
{
#ifdef TESTE

    char * fileContent = fileReader("/Users/carlos/Desktop/ex3.txt");
    printf("%d\n", wordCounter(fileContent, 0));
    printf("%d\n", prepositionCounter(fileContent));
    printf("%d\n", charCounter(fileContent, ' '));
    printf("%d\n", charCounter(fileContent, '\t'));
    printf("%d\n", wordCounter(fileContent, 10));
    free(fileContent);

#else
    
    char * fileName = readFromStdin();
    char * fileContent = fileReader(fileName);
    char * instructions = readFromStdin();
    free(fileName);
    int inputInstructions = (int)strtol(instructions, NULL, 2);

    int i;
    for (i = NUMBER_OF_INSTRUCTIONS; i >= 0; i--)
    {
        switch (inputInstructions & 1<<i)
        {
            case WordCount:
                printf("%d\n", wordCounter(fileContent, 0));
                break;
            case PrepositionCount:
                printf("%d\n", prepositionCounter(fileContent));
                break;
            case SpaceCount:
                printf("%d\n", charCounter(fileContent, ' '));
                break;
            case TabCount:
                printf("%d\n", charCounter(fileContent, '\t'));
                break;
            case LongWordCount:
                printf("%d\n", wordCounter(fileContent, 10));
                break;
        }
    }
    free(fileContent);
    free(instructions);

#endif
    return 0;
}