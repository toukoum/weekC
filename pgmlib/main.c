#include "allocation.h"
#include "traitement.h"
#include <stdio.h>
#include <time.h> 


void pgm_show(char *filename)
{
    char command[512];

    snprintf(command, sizeof(command), "eog %s &", filename);
    system(command);
}

int main(void)
{
    int i = 0;

    clock_t debut = clock();

    
    while (i++ < 10)
    {
        pgm_t_image *image_data;
        size_t height, width;

        width = 1920;
        height = 1080;

        image_data = pgm_malloc(width, height);
        if(!image_data)
            return (EXIT_FAILURE);

        // pgm_solid(image_data, 99);
        // pgm_negative(image_data);
        // pgm_threshold(image_data, 99);
        pgm_gradient(image_data);
        pgm_write("test.pgm", image_data);
        pgm_free(image_data);
    }
    pgm_show("test.pgm");

    clock_t fin = clock();
    float temps_ecoule = (float)(fin - debut) / CLOCKS_PER_SEC;
    printf("Temps écoulé : %.3f secondes\n", temps_ecoule);

    return (EXIT_SUCCESS);
}
