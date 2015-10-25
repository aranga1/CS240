#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Problem ( 1/3 ) 
/******************************************************************************
 * TODO: Count the number of lines in the file named 'fileName'. Return the 
 * number of lines as an integer.
 * 
 * Parameters: fileName -- name of the file
 *
 * Return: number of lines in the file
 *
 * Return Type: integer
 *****************************************************************************/
int countLines(char * fileName) {
    int i = 0; int c;
    FILE * fd = fopen(fileName,"r");
    if (fd == NULL) {
	printf("Could not open file %s\n", fileName);
	exit(1);
    }
    while ((c = fgetc(fd)) != EOF) {
	if (c == '\n') {
	    i++;
	}
    }
    return i;
}

// Problem ( 2/3 ) 
/******************************************************************************
 * TODO: Read the text file, parse each word, and store the word in to the
 * 'word_list'. Change all the characters in the word to capital letters. 
 * Return 'word_list'.
 *
 * E.g. a text file contains "Hello, world"
 *      The string array 'word_list' should contain {"HELLO", "WORLD"}
 * 
 * Parameters: fileName -- name of the file
 *             word_list -- seperate the words from the text file and store
 *             each word in to this string array. Make sure to change all the
 *             characters in the word to upper case.
 *
 * Return: return the string array 'word_list'
 *
 * Return Type: char double pointer (String array)
 *****************************************************************************/
char ** create_word_list( char * fileName, char ** word_list ) {
	int i = 0;
	int j = 0;
	int c;
	FILE *fd = fopen(fileName,"r");
		while ((c = fgetc(fd)) != EOF) {
			if (c > 90) {
				c -= ' ';
			}
			if (c == '\n' || c == '\0' || c == ' ' || c == '.' || c == ',' || c == '-') {
				if (c == ',') {
					continue;
				}
				word_list[j][i] = '\0';
				j++;
				i = 0;
				continue;
			}
			word_list[j][i] = c;
			i++;
		}
	return word_list;
}

// Problem ( 3/3 ) 
/******************************************************************************
 * TODO: Iterate through the list of words in each file. If a word is found in
 * both files, add the word to 'match_list'. Do not repeat words in the list. 
 * Capitilization of words does not matter. So "Bob" and "bob" should be
 * considered a match. When inserting the word in to the list, make all the
 * characters in the word upper case. 
 *
 *  HINT: Use the function create_word_list to save time.
 *
 * E.g. File1 contains the text "We like fruit. It is good."
 *      File2 contains the text "Fruit is very delicious."
 *
 *      The string array 'match_list' should contain {"FRUIT", "IS"}
 *
 * Parameters: fileName1 -- name of the first text file
 *	       fileName2 -- name of the second text file
 *	       match_list -- store the intersecting words from both files in
 *	                     this string array. 
 *
 * Return: Return the string array 'match_list'.
 *
 * Return Type: char double pointer (String array)
 *****************************************************************************/
char ** sharedWords( char * fileName1, char * fileName2, char ** match_list ) {
    
    char **wordsA = (char **) malloc (200 * sizeof(char *));
        for (int i = 0; i < 200; i++) {
	        wordsA[i] = strdup("");
		}
    create_word_list(fileName1, wordsA);
    char **wordsB = (char **) malloc (200 * sizeof(char *));
        for (int i = 0; i < 200; i++) {
	        wordsB[i] = strdup("");
		}
    create_word_list(fileName2, wordsB);
    int m = 0;
    int f = 0;
    for (int i = 0; wordsB[i] != NULL; i++) {
    	f = 0;
    	for (int j = 0; match_list[j] != NULL; j++) {
		if (strcmp(wordsB[i],match_list[j]) == 0){
			f++;
			break;
		}
	}
	if (f == 1) {
		continue;
	}
	for (int k = 0; wordsA[k] != NULL; k++) {
		if (strcmp(wordsB[i],wordsA[k]) != 0) {
			continue;
		}
		match_list[m] = wordsB[i];
		m++;
		break;
		}
	}
    // Write Your Code Here
    return match_list;
}
