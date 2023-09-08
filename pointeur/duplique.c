#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copier_chaine(char *str)
{
    char *result;
    int len = strlen(str);

    result = malloc((len + 1) * sizeof(char));
    if (!result)
        return (NULL);

    result[len] = '\0';

    strcpy(result, str);

    return (result);
}

int main(void)
{
    char original[] = "Ma super chaine a copier";
    char *copie;

    copie = copier_chaine(original);
    if (!copie)
        return EXIT_FAILURE;
    
    printf("Chaine original: %s\n", original);
    printf("Copie de la chaine: %s\n", copie);

    free(copie);

    return EXIT_SUCCESS;
}
