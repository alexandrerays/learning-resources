#include <iostream.h>
#include <conio.h>

main()
{
	float b,h,a,p;

	printf("Digite a base: ");
	scanf("%f",&b);
	printf("Digite a altura: ");
	scanf("%f",&h);
	a=b*h;
	printf("Area: %f \n",a);
	p=2*(b+h);
	printf("Perimetro: %f \n",p);
	getch();
}
