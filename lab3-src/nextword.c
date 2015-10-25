
#include <stdio.h>
#include <stdlib.h>

//
// Separates the file into words
//

#define MAXWORD 200
char word[MAXWORD];
int wordLength;

// It returns the next word from fd.
// If there are no more more words it returns NULL. 
char * nextword(FILE * fd) {
  	char * ans = word;
	int i = 0;
	int c;
	while ((c = fgetc(fd)) != EOF) {
		if( c == '\n' || c == '\t' || c == ' ') {
			if (i == 0) {
				continue;
			}
			word[i] = '\0';
			break;
		}
		word[i] = c;
		i++;
	}
	if (i != 0) {
		return ans;
	}
	return NULL;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*int c;
	int i = 0;
	char * temp = word;
	while ((c = fgetc(fd)) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (i == 0) {
				continue;
			}
			word[i] = '\0';
			return temp;
		}
		word[i] = c;
		i++;
	}
	if ( i != 0) {
		return temp;
	}
	return NULL;*/
	
	// While it is not EOF read char
		// While it is not EOF and it is a non-space char
		// store character in word.
		// if char is not in word return word so far.
		//
	// Return null if there are no more words
}

