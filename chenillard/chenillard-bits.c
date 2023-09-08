
#include "chenillard-bits.h"

// char *ft_init_tab(char *result)
// {
//     int i = -1;
//     while (++i < N_AMP)
//         result[i] = '.';
//     return (result);
// }

void affiche_result(t_switch result)
{
    int i = N_AMP - 1;

    printf("\r");
    while (i >= 0)
    {
        if((result >> i) & 1)
            printf("*");
        else
            printf(".");
        i--;
    }
}

unsigned char is_bulb_on(t_switch state, unsigned char bulb)
{
    return ((state >> bulb) & 1);
}

t_switch invert(t_switch state)
{
    return (~state);
}

t_switch increment(t_switch state)
{
    return (state + 1);
}

t_switch rotate_left(t_switch state)
{
    
}


int main(void)
{
    t_switch result = 13;
    
    printf("========= INVERT =========\n\n");
    int i = 0;
    while (i < 20)
    {
        affiche_result(result);
        fflush(stdout);
        ms_sleep(SW_TIME);
        affiche_result(invert(result));
        fflush(stdout);
        ms_sleep(SW_TIME);
        i++;
    }
    printf("\n\n\n");

    printf("========= INCREMENT =========\n\n");
    i = 0;
    int tempo = result;
    while (i < 100)
    {
        affiche_result(result);
        fflush(stdout);
        ms_sleep(SW_TIME - 80);
        tempo = increment(tempo);
        affiche_result(tempo);
        fflush(stdout);
        ms_sleep(SW_TIME - 90);
        i++;
    }
    printf("\n\n\n");

    printf("========= ROTATE[left] =========\n\n");


    return (EXIT_SUCCESS);
}
