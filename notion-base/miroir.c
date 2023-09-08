/* à compléter: entêtes */
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_LEN 64

int ft_size(char orig[BUFFER_LEN])
{
	int i = 0;
	while(orig[i])
		i++;

	return (i);
}


int main(void)
{
	char orig[BUFFER_LEN] = "bonjour a tous les amis";
	// = {0}; is the universal zero initializer, C99 Standard 6.7.8.21
	char mirror[BUFFER_LEN] = {0};  // fill buffer with 0 (a.k.a. '\0')

	int size_orig = ft_size(orig);
	int i = 0;

	while(size_orig > 0)
	{
		mirror[i] = orig[size_orig-1];
		i++;
		size_orig--;
	}

	printf("%s\n", mirror);

	return EXIT_SUCCESS;
}
