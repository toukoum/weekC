#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a;
	int b;
	printf("programme aui multiplie 2 nombres\n");

	printf("saisir un premier nombre:");
	scanf("%d", &a);

	printf("saisir un deuxième nombre:");
	scanf("%d", &b);

	printf("%i * %i = %i\n", a, b, a*b);


	return EXIT_SUCCESS;
}
