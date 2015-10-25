
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char ** argv) {
	int c;
	int lines=0;
	char * temp = argv[1];
	FILE * fd = fopen(temp, "r");
	printf("Program that counts lines.\n");
	
	while ((c = fgetc(fd)) != EOF)
	{
		if (c == '\n') {
			lines++;
		}
	}
	fclose(fd);
	printf("Total lines: %d\n", lines);
 	// Add your implementation here

	exit(0);
}
