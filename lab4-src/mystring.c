
#include <stdlib.h>
#include "mystring.h"

int mystrlen(char * s) {
	char * temp = s;
	int i = 0;
	while (*temp != '\0') {
		i++;
		temp++;
	}
	return i;
}

char * mystrcpy(char * dest, char * src) {
	char * temp = src;
	char * temp1 = dest;
	while (*temp != '\0') {
		*temp1 = *temp;
		temp1++;
		temp++;
	}
	*temp1 = '\0';
	return dest;
}

char * mystrcat(char * dest, char * src) {
	char * temp = dest;
	while (*temp != '\0') {
		temp++;
	}
	while (*src != '\0') {
		*temp = *src;
		temp++;
		src++;
	}
	*temp = '\0';
	return dest;
}

int mystrcmp(char * s1, char * s2) {
	int c1 = 0;
	int c2 = 0;
	while (*s1 != '\0') {
		c1++;
		s1++;
	}
	while (*s2 != '\0') {
		c2++;
		s2++;
	}
	if (c2 > c1) {
		return -1;
	}
	else if (c2 < c1) {
		return 1;
	}
	else {
		return 0;
	}
}

char * mystrstr(char * hay, char * needle) {
	char *p1 = hay;
	while (*p1 != '\0') {
		char *ans = p1;
		char *p2 = needle;
		while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
			p1++;
			p2++;
		}
		if (*p2 == '\0')
			return ans;
		p1++;
	}
	return NULL;
}

char * mystrdup(char * s) {
	char * temp = s;
	int i = 0;
	while (*temp != '\0') {
		i++;
		temp++;
	}
	char * dup = (char*)malloc(i+1 * sizeof(char*));
	char * temp1 = dup;
	while (*s != '\0') {
		*temp1 = *s;
		s++;
		temp1++;
	}
	*temp1 = '\0';
	return dup;
}

char * mymemcpy(char * dest, char * src, int n) {
	char * temp = src;
	char * temp1 = dest;
	int i;
	for (i = 0; i < n; i++) {
		*temp1 = *temp;
		temp1++;
		temp++;
	}
	return dest;
}

