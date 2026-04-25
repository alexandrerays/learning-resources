#include <stdio.h>
#include <stdlib.h>
#include<string.h>
// função que reverte uma string e imprime o conteúdo invertido num arquivo de 
//bloco de notas
void str_reverse(char* str)
{
  char ch;
  int i, j;

  for(i = 0, j = strlen(str) - 1;  i < j;  ++i, --j)
  {
    ch = str[i];
    str[i] = str[j];
    str[j] = ch;
  }
}

main()
{
      FILE *pf;
      
      pf = fopen("arquivo.txt","w");
      
      
  char nome[] = "?url=rar.1trap.vu.ak/919793361/selif/moc.erahsdipar//:ptth";

  // original
  printf("Original: %s\n", nome);

  // inverte
  str_reverse(nome);
  printf("Invertido: %s\n", nome);
  
  fputs(nome, pf);

  printf("\n\n");
  system("PAUSE");
  return 0;
}
