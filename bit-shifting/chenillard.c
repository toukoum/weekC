
#include "chenillard.h"

char *ft_init_tab(char *result)
{
    int i = -1;
    while (++i < N_AMP)
        result[i] = '.';
    return (result);
}

int main(void)
{
    char *result;
    int i = 0;
    result = malloc((N_AMP + 1) * sizeof(char));
    if (!result)
        return (EXIT_FAILURE);
    
    result[N_AMP] = '\0';

    result = ft_init_tab(result);
    while (result[i])
    {
        result[i] = '*';
        printf("%s\r", result);
        fflush(stdout);
        ms_sleep(SW_TIME);
        result[i] = '.';
        i++;
    }
    
    return (EXIT_SUCCESS);
}
