/* Tipos de variáveis */

#include <stdio.h>

int main() {
	int x, y;
	int a=14, b=3;
	float z;
	x=a/b;
	y=a%b;
	z=y/x;
	printf("Divisão de dois inteiros em uma variável inteira: %d\n", x); 
	printf("Resto da divisão de dois inteiros: %d\n", y);
	printf("Divisão de dois inteiros em uma variável float: %f\n", z);
}
