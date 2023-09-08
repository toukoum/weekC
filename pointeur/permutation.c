#include <stdio.h>
#include <stdlib.h>


void permuter(int *adr_a, int *adr_b)
{
    int tempo;

    tempo = *adr_a;
    *adr_a = *adr_b;
    *adr_b = tempo;

}
int main(void)
{
    int a, b;

    a = 2;
    b = 4;
    
    printf("Valeur avant permutation: %i, %i\n", a, b);
    permuter(&a, &b);
    printf("Valeur après permutation: %i, %i\n", a, b);

    return EXIT_SUCCESS;
}
