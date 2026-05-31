#include <iostream.h>
#include <conio.h>

main()
{
	int a,b,c,s;
	float p;

	printf("Digite o primeiro numero: ");
	scanf("%d",&a);
	printf("Digite o segundo numero: ");
	scanf("%d",&b);
	printf("Digite o terceiro numero: ");
	scanf("%d",&c);
	s=a+b+c;
	printf("Soma: %d \n",s);
	p=s/3.0;
	printf("Media: %f \n",p);
	getch();
}
