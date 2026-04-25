char* getLine(){
    char *string;
    char temp[1000], aux;
    int i;

    for(i=0 ; (fscanf(stdin, "%s", &aux)!=EOF) && aux!='\n'; i++){
        temp[i] = aux;
    }
    temp[i] = '\0';

    //não pode esqueçer de declara a <string.h>
    string = (char*) malloc(strlen(temp)*sizeof(char));

    return string;
}
