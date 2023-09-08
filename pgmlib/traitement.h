#ifndef TRAITEMENT_H_
#define TRAITEMENT_H_

#include <pgmio.h>
#include <stdio.h>

void pgm_negative(pgm_t_image *pgm);
void pgm_threshold(pgm_t_image *pgm, pgm_t_pixel threshold);
void pgm_gradient(pgm_t_image *pgm);
void pgm_solid(pgm_t_image *pgm, pgm_t_pixel color);

#define DEBUG 0

#if DEBUG
    #define AFFICHER_FONCTION() printf("Fonction : %s\n", __func__)
#else
    #define AFFICHER_FONCTION()

#endif

#endif /*TRAITEMENT_H_*/