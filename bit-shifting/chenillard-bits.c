#include "chenillard-bits.h"

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
    int poids_faible = 0;

    if (is_bulb_on(state, N_AMP  - 1))
        poids_faible = 1;
    state <<= 1;
    if (poids_faible)
        state |= 1;
    return (state);    
}

t_switch  ft_power(int power)
{
    int i = -1;
    t_switch result = 1;

    while (++i < power)
        result = 2 * result;
    return (result);
}

t_switch rotate_right(t_switch state)
{
    int poids_faible = 0;
    t_switch mask = ft_power(N_AMP - 1);
    if (is_bulb_on(state, 0))
        poids_faible = 1;
    state >>= 1;
    if (poids_faible)
        state |= (mask);
    return (state);
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
    while (i < 30)
    {
        affiche_result(result);
        fflush(stdout);
        ms_sleep(SW_TIME);
        tempo = increment(tempo);
        affiche_result(tempo);
        fflush(stdout);
        ms_sleep(SW_TIME);
        i++;
    }
    printf("\n\n\n");

    printf("========= ROTATE[left] =========\n\n");
    i = 0;
    while (i < 40)
    {
        affiche_result(result);
        result = rotate_left(result);
        fflush(stdout);
        ms_sleep(SW_TIME );
        i++;
    }
    printf("\n\n\n");

    printf("========= ROTATE[right] =========\n\n");
    i = 0;
    result = 13;
    while (i < 40)
    {
        affiche_result(result);
        result = rotate_right(result);
        fflush(stdout);
        ms_sleep(SW_TIME );
        i++;
    }
    printf("\n\n\n");

    return (EXIT_SUCCESS);
}
