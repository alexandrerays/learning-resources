#include <iostream.h>
#include <conio.h>

main()
{
	int a,b,c,d,n,s;

	printf("Digite um numero: ");
	scanf("%d",&n);
	a=n%10;
	n=n/10;
	b=n%10;
	n=n/10;
	c=n%10;
	d=n/10;
	s=a+b+c+d;
	printf("A soma e: %d",s);
	getch();
}
