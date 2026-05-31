#include<iostream.h>
#include<conio.h>

main()
{
	int a,b,c;

	printf("Digite longitude A: ");
	scanf("%d",&a);
	printf("Digite longitude B: ");
	scanf("%d",&b);
	printf("Digite longitude C: ");
	scanf("%d",&c);

	if(a>=0 && b>=0 && c>=0)
	{
		if(a*a>b*b+c*c)
		{
			printf("E um triangulo obtusangulo");
		}
		else
		{
			if (a*a<b*b+c*c)
			{
				printf("E um triangulo acutangulo");
			}
			else
			{
				printf("E um triangulo retangulo");
			}
		}
	}
	else
	{
		printf("Erro, dados negativos");
	}
	getch();
}

