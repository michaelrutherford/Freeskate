#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char **argv)
{
	FILE *example;
	char input;
	char typeinput[5];
	printf ("File type: ");
	scanf ("%s", &typeinput);
	char filetype[29] = "/home/example.";
	strncat (filetype, typeinput, 29);
	example = fopen (filetype, "w");
	if (!example) {
		printf ("Error: Unable to open file\n");
		return EXIT_FAILURE;
	}
	while (input != '~') {
		scanf ("%c", &input);
		fprintf (example, "%c", input);
	}
	fclose (example);
	return EXIT_SUCCESS;
}
