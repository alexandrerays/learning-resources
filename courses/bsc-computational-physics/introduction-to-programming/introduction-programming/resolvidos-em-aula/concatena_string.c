#include <stdio.h>


void concatena(char* s1,char* s2)
{
	char *p_s1;
	char *p_s2;
	
	for(p_s1=s1;*p_s1!='\0';p_s1++);
	for(p_s2=s2;*p_s2!='\0';p_s1++,p_s2++) {
		*p_s1 = *p_s2;
         }

	*p_s1 = '\0';

	
}
	  


int main()
{
	char str[25] = "cadeira";
	char str2[25] = "porta";
	
	concatena(str,str2);

	printf("\nstring concatenada: %s\n", str);

	return (0);

}
