#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


main(int argc, char **argv) 
{
	if (argc != 4) {
		printf("Usage:  convert <basefrom> <baseto> <number>\n");
		exit(1);
	}

	int bFrom = 0;
	int bTo = 0;
	long signed int n;
	long signed int h;
	long signed int nn = 0;
	char word[15];
	int i = 0;

	char base_numbers[25] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'};
	int converted[64];
	sscanf(argv[1], "%d", &bFrom);
	sscanf(argv[2], "%d", &bTo);
	sscanf(argv[3], "%s", &word);
	sscanf(argv[3], "%ld", &n);
	sscanf(argv[3], "%ld", &nn);

	printf("Number read in base %d: %s\n", bFrom, word);
	if(bFrom < 10) {
		int j;

		for(j = 0; j < strlen(word); j++) {
			int t = word[j] - 48;
			if (t >= bFrom) {
				printf("Wrong digit in number.\n");
				exit(1);
			}

		}

	}
	h = strtol(word, NULL, bFrom);
	printf("Converted to base 10: %ld\n", h);
	while (h != 0)
	{
		converted[i] = h % bTo;
		h = h/bTo;
		++i;
	}
	--i;
	printf("Converted to base %d: ", bTo);
	for(; i>=0; i--) /* go backward through array */
	{
		printf("%c", base_numbers[converted[i]]);
	}
	printf("\n");

	

}
