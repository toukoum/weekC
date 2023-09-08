#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void putchars(unsigned int repeat, char ch)
{
    int i = -1;

    while (++i < repeat)
        write(1, &ch, 1);
}

int main(int argc, char **argv)
{
    if (argc != 3)
	    return EXIT_SUCCESS;
    
    int h = atoi(argv[1]);
    int nb_carac = 1;
    int j = 0;

    int len_base = (2 * h) - 1;
    int nb_space = len_base / 2;

    while (j < h)
    {
        putchars(nb_space, ' ');
        putchars(nb_carac, argv[2][0]);
        putchars(nb_space, ' ');
        putchars(1, '\n');
        j++;
        nb_space--;
        nb_carac+=2;
    }

	return EXIT_SUCCESS;
}
