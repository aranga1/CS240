
#include <stdio.h>

#include "array.h"

// Return sum of the array
double sumArray(int n, double * array) {
	double sum = 0;

	double * p = array;
	double * pend = p+n;

	while (p < pend) {
		sum += *p;
		p++;
	}

	return sum;
}

// Return maximum element of array
double maxArray(int n, double * array) {
	double max = 0;

	double * p = array;
	double * pend = p + n;

	while (p < pend) {
		if (*p > max) {
			max = *p;
		}
		p++;
	}
	return max;
}

// Return minimum element of array
double minArray(int n, double * array) {
	double min = 200;

	double * p = array;
	double * pend = p + n;

	while (p < pend) {
		if (*p < min) {
			min = *p;
		}
		p++;
	}
	return min;
}

// Find the position in the array of the first element x 
// such that min<=x<=max or -1 if no element was found
int findArray(int n, double * array, double min, double max) {
	double * p = array;
	double * pend = p + n;
	double pos = 0;
	while (p < pend) {
		if ((*p >= min) && (*p <= max)) {
			return pos;
		}
		pos++;
		p++;
	}
	return -1;
}

// Sort array without using [] operator. Use pointers 
// Hint: Use a pointer to the current and another to the next element
int sortArray(int n, double * array) {
	double * p = array;
	double * pend = p + n;
	double temp;
	for ( p ; p < pend; p ++)  {
		double * p1 = (p+1);
		for ( p1; p1 < pend; p1++) {
			if (*p > *p1) {
				temp = *p;
				*p = *p1;
				*p1 = temp;
			}
			//p1++;
		}
		//p++;
	}
	return 1;
}

// Print array
void printArray(int n, double * array) {
	double * p = array;
	double * pend = p + n;
	int ct = 0;
	while (p < pend) {
		printf("%d:%f\n",ct, *p);
		ct++;
		p++;
	}
}

