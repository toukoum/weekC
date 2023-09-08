#include "traitement.h"
#define SEUIL2_PIXEL(valeur, seuil) (valeur = ((valeur < seuil) ? 0 : 255))
    
void pgm_negative(pgm_t_image *pgm)
{
    AFFICHER_FONCTION();
    int i = 0;
    int size = pgm->width * pgm->height;

    while (i < size)
    {
        pgm->pixels[i] = 255 - pgm->pixels[i];
        i++;
    }
}

void pgm_threshold(pgm_t_image *pgm, pgm_t_pixel threshold)
{
    AFFICHER_FONCTION();
    int i = 0;
    int size = pgm->width * pgm->height;

    while (i++ < size)
        SEUIL2_PIXEL(pgm->pixels[i], threshold);       
    
}

void pgm_gradient(pgm_t_image *pgm)
{
    AFFICHER_FONCTION();
    int i = 0;
    int size = pgm->width * pgm->height;

    while (i < size)
    {        
        pgm->pixels[i] = (255 * (i % pgm->width)) / (pgm->width - 1);       
        i++;                                                                                                                                                              
    }
}

void pgm_solid(pgm_t_image *pgm, pgm_t_pixel color)
{
    AFFICHER_FONCTION();
    int size = pgm->width * pgm->height;
    int i = 0;

    while (i < size)
    {
        pgm->pixels[i] = color;
        i++;
    }
}