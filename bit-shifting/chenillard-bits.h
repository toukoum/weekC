
#ifndef CHENILLARD_H_
#define CHENILLARD_H_

#define _POSIX_C_SOURCE 199309L  // nanosleep in POSIX.1b (real-time extensions)

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

static void ms_sleep(const unsigned long long int ms)
{
	struct timespec delay = {
		.tv_sec = ms / 1000,
		.tv_nsec = ms % 1000 * 1000000,
	};
	nanosleep(&delay, NULL);
}

#define ON 1
#define OFF 0
#define N_AMP 32
#define SW_TIME 100

typedef uint32_t t_switch;

#endif