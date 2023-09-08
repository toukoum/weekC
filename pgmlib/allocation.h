#ifndef ALLOCATION_H_
#define ALLOCATION_H_

#include <pgmio.h>
#include <stdlib.h>

pgm_t_image *pgm_malloc(size_t width, size_t height);
void pgm_free(pgm_t_image *pgm);


#endif 