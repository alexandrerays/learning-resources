#include<iostream.h>
#include<conio.h>

main()
{
	int a,b,c,menor;

	printf("Digite o primeiro numero: ");
	scanf("%d",&a);
	printf("Digite o segundo numero: ");
	scanf("%d",&b);
	printf("Digite o terceiro numero: ");
	scanf("%d",&c);
	menor=a;

	if(b<menor)
	   menor=b;

	if(c<menor)
	   menor=c;

	printf("O menor numero e: %d \n",menor);
	getch();
}
