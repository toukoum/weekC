#include "allocation.h"

pgm_t_image *pgm_malloc(size_t width, size_t height)
{
    pgm_t_image *result;

    result = malloc(sizeof(pgm_t_image));
    if (!result)
        return (NULL);

    result->pixels = malloc((height * width) * sizeof(pgm_t_pixel));
    if (!result->pixels)
    {
        free(result);
        return (NULL);
    }

    result->height = height;
    result->width = width;
    return (result);
}

void pgm_free(pgm_t_image *pgm)
{
    free(pgm->pixels);
    free(pgm);
}

