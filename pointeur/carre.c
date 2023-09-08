
#include <stdio.h>
#include <stdlib.h>


int carre_copie(int n)
{
    return (n*n);
}

void carre_adresse(int *adr_n)
{
    *adr_n*=*adr_n;
}


int main(void)
{
    int x = 3;
    printf("Valeur avant fonction: %i \nValeur après fonction: %i\n", x, carre_copie(x));

    x = 3;
    printf("Valeur avant fonction 2: %i", x);
    carre_adresse(&x);
    printf("\nValeur après fonction 2: %i\n", x);

    return EXIT_SUCCESS;
}