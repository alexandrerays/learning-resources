#include <iostream.h>
#include <conio.h>

main()
{
	int a,b,c,d,n;

	printf("Digite um numero: ");
	scanf("%d",&n);
	a=n%10;
	n=n/10;
	b=n%10;
	n=n/10;
	c=n%10;
	d=n/10;
	if(a==d && b==c)
        printf("Numero palindromo");
    else
        printf("Numero nao palindromo");
	getch();
}
