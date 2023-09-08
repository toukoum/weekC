#include <stdlib.h>
#include <stdio.h>

void pascal_free(int actual, int **result)
{
    while (actual >= 0)
    {
        free(result[actual]);
        actual--;
    }
    free(result);    
}

int **pascal_malloc(int n)
{
    int **result;

    int i = 0;
    result = malloc((n + 1) * sizeof(int *));
    if (!result)
        return (0);
    
    while (i < n + 1)
    {
        result[i] = malloc((i + 1) * sizeof(int));
        if (!result[i])
            pascal_free(i, result);
        i++;
    }
    return (result);
}

void  pascal_fill(int n, int **result)
{
    int i = 1;
    int j = 0;
    int tempo = 2;
    result[0][0] = 1;
    while (i < n + 1)
    {
        while (j < tempo)
        {
            if (j == 0 || j == tempo - 1)
                result[i][j] = 1;
            else
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            j++;
        }
        j = 0;
        tempo++;
        i++;        
    }
}

void pascal_display(int n, int **result)
{
    int i = 0;
    int j = 0;
    int tempo = 2;

    while (i < n + 1)
    {
        while (j < tempo - 1)
        {
            printf("%i\t", result[i][j]);
            j++;
        }
        j = 0;
        tempo++;
        printf("\n");
        i++;        
    }
}


int main(int argc, char **argv)
{
    if (argc != 2)
        return (EXIT_FAILURE);
    
    int **result;
    int n = atoi(argv[1]);

    if (n < 0)
        return (EXIT_FAILURE);
    
    result = pascal_malloc(n);
    pascal_fill(n, result);
    pascal_display(n, result);
    pascal_free(n, result);

    return (EXIT_SUCCESS);
}
