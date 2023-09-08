#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int number;
    int i = -1;

    printf("vous voulez la table de combien ? ");
    scanf("%d", &number);

    while(++i <= 10)
    {
        printf("%i x %i = %i\n", i, number, i*number);
    }

	return EXIT_SUCCESS;
}