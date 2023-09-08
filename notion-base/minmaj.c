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

int main(void)
{
	int minus, majus, other;

	minus = 0;
	other = 0;
	majus = 0;

	int i = 0;
	char buffer[BUFFER_LEN];
	ssize_t nread;
	
	printf("Entrez une chaîne quelconque : ");

	nread = readline(buffer, BUFFER_LEN, stdin);

	if (nread == -1)
		return EXIT_SUCCESS;

	while (i < nread)
	{
		if (buffer[i] >= 'a' && buffer[i] <= 'z')
			minus++;
		else if (buffer[i] >= 'A' && buffer[i] <= 'Z')
			majus++;
		else
			other++;
		i++;
	}

	printf("lower: %i\n", minus);
	printf("upper: %i\n", majus);
	printf("other: %i\n", other);

	return EXIT_SUCCESS;
}
