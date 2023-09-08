#define _POSIX_C_SOURCE 200809L  // getline in POSIX.1-2008

/* à compléter: entêtes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LEN 64

/*
 * readline() reads an entire line from stream and stores at most one less than
 * size characters into the buffer pointed to by buffer.
 * A terminating null byte ('\0') is stored after the last character in the
 * buffer.
 *
 * On success, readline() returns the number of characters read, excluding the
 * terminating null byte ('\0').
 *
 * The function returns -1 on failure to read a line (including end-of-file
 * condition).
 */
static ssize_t readline(char *buffer, size_t size, FILE *stream)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	ssize_t ncopied = -1;

	nread = getline(&line, &len, stream);
	if (nread != -1) {
		// copy at most size - 1 bytes
		ncopied = nread < (ssize_t)size - 1 ? nread : (ssize_t)size - 1;
		memcpy(buffer, line, ncopied);
		// terminating null byte
		buffer[size] = '\0';
	}
	free(line);

	return ncopied;
}

int ft_size(char *str)
{
	int i = 0;
	while(str[i])
		i++;

	return (i);
}

int ft_power(int x, int y)
{
    int i = 0;
    int result = 1;

    while (i < y)
    {
        result *= x;
        i++;
    }
    return (result);
}

void bin2dec(char bin[], char dec[])
{
    char *copy;
    int result = 0;
    int i = 0;
    printf("donner un nombre en binaire: ");
	ssize_t nread;
	nread = readline(bin, BUFFER_LEN, stdin);

    copy = bin;

	if (nread == -1)
		return ;
    
    int len = ft_size(bin);


    while (i < len - 1)
    {
        if (bin[i] != '0')
        {
            result += ft_power(2, len - i - 2);
        }
        i++;
    }
    sprintf(dec, "%i", result);
    copy[len-1] = '\0';
    printf("<%s>2 = ", copy);
    printf("<%s>10\n", dec);
}




int main(int argc, char const *argv[])
{

	// int i = 0;
	char bin[BUFFER_LEN];
	char dec[BUFFER_LEN];


    bin2dec(bin, dec);
	
	

	

    // ft_display(compteur);

	return EXIT_SUCCESS;
}