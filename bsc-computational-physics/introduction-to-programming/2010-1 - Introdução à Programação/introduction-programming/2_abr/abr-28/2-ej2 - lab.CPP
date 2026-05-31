#include<iostream.h>
#include<conio.h>

main()
{
	int n1,n2,op;
	float r;

	printf("Digite o primeiro numero: ");
	scanf("%d",&n1);
	printf("Digite o segundo numero: ");
	scanf("%d",&n2);
	printf("Digite operador: ");
	scanf("%d",&op);

	switch(op)
	{
		case 1:
		{
			r=n1+n2;
			break;
		}

		case 2:
		{
			r=n1-n2;
			break;
		}

		case 3:
		{
			r=n1*n2;
			break;
		}

		case 4:
		{
			r=n1/float(n2);
			break;
		}

		default:
		{
			printf("Operador nao definido\n");
			r=0;
			break;
		}
	}
	printf("O resultado e: %f",r);
	getch();
}
