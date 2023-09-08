#define _POSIX_C_SOURCE 200809L  // POSIX.1-2008 (correctness of function pointer cast)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define COMMAND_BUFFER_LEN 64
// #define TEST 13

/* TODO: déclarer les variables globales ici */
int globvar_decl;
int globvar_init = 13;

static void dump_memory_map(void)
{
	char command[COMMAND_BUFFER_LEN] = {0};

	puts("address                   perms offset  dev   inode                      pathname\n"
	     "-------                   ----- ------  ---   -----                      --------");
	snprintf(command, COMMAND_BUFFER_LEN, "cat /proc/%d/maps", getpid());
	system(command);
}

int main(void)
{
	/* variables locales */
	const char *str = "Hello world!";
	puts(str);
	printf("\nadresse `str`: %p\ncontenu `str`: %p\n\n",
	       (void *)&str,
	       (void *)str);

	/* allocation dynamique */
	char *alloc = malloc(42 * sizeof(char));
	printf("adresse `alloc`: %p\ncontenu `alloc`: %p\n\n",
	       (void *)&alloc,
	       (void *)alloc);
	free(alloc);

	/* variables globales */
	/* TODO: afficher les adresses et contenus des variables globales */

	/* fonctions */
	printf("adresse `main()`: %p\n", (void *)main);
	printf("adresse `dump_memory_map()`: %p\n\n", (void *)dump_memory_map);

	/*
	 * Note on function pointer cast:
	 *
	 * Casting a function pointer into a regular pointer is undefined
	 * behavior in the C standard.
	 * It is however mentioned as an extension in section J.5.7 'Function
	 * pointer casts'.
	 *
	 * POSIX (since POSIX.1-2008 Technical Corrigendum 1) however requires
	 * for conformance, see section 2.12.3 'Pointer Types', that function
	 * pointer univocally maps to a void *.
	 *
	 * As a result, the cast `(void *)function` is valid on Linux.
	 */

	dump_memory_map();

	return EXIT_SUCCESS;
}

/*
======== Réponse aux questions =========

0-	Le segment contenant le code doit avoir les permissions suivantes: read et execute
	C'est cette ligne qui correspond au segment de code: 55fa620a2000-55fa620a3000 r-xp 00001000 fe:04 917552                     /tmp/semaine-C/instrumented-program

1-	Non les plages d'@ ne sont pas conservé pour une question de securité

2-	La variable locale str se trouve dans la stack, le contenu de str se trouve dans la section .text
	Il faut 13 octets pour stocker str dans le segment .text

3-	La variable local alloc se trouve dans la stack, mais le contenu de alloc se trouve dans la heap
	Les permissions sont: rw-
	Il faut 8 octets pour stocker alloc dans la stack

4- dans la section .bss (perm: rw-) 0 octects occupés; 
	=> stocké dans .bss qui est simplement alloué et initialisé à 0 au démarage du programme.

5- dans la section .data (perm: rw-) 4 octects occupés;
	=> stocké dans .data qui est stocké dans le fichier binaire.


6- 0 octets sont nécessaire
	=> préprocesseur, occupe pas de place dans le fichier binaire.
*/