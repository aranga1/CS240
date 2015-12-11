#include "mysort.h"
#include <alloca.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

//

//
// See test_sort to see how to use mysort.
/**
 * @brief Arbitrary sort func
 *
 * Sort an array of element of any type
 * using "compFunc" to sort the elements.
 * 
 * The elements are sorted such as:
 * 
 * if ascending != 0
 *   compFunc( array[ i ], array[ i+1 ] ) <= 0
 * else
 *   compFunc( array[ i ], array[ i+1 ] ) >= 0
 * 
 * @param n Number of elements.
 * @param elementSize Size of each element.
 * @param array Pointer to an array of arbitrary type.
 * @param ascending Boolean controlling the direction of the sort.
 * @param compFunc Comparison funciton.
 **/
void mysort(int n, int elementSize, void * array, int ascending, CompareFunction compFunc)
{
	int i, j, k, l;
	void * temp = malloc(elementSize);
	if (ascending == 1) {
		for (i = 0 ; i < n; i++) {
			for ( j = 0; j < i; j++ ) {
				char * elm = ((char*)array+j*elementSize);
				char * eln = ((char*)array+(i)*elementSize);
				if((*compFunc)(elm,eln)>=0) {
					memcpy(temp, elm, elementSize);
					memcpy(elm, eln, elementSize);
					memcpy(eln, temp, elementSize);
				}
			}
		}
	}
	else if(ascending == 0) {
		for (k = 0 ; k < n; k++) {
			for ( l = 0; l < k; l++ ) {
				char * elm =  ((char*)array+l*elementSize);
				char * eln = ((char*)array+(k)*elementSize);
				if((*compFunc)(elm,eln)<=0) {
					memcpy(temp, elm, elementSize);
					memcpy(elm, eln, elementSize);
					memcpy(eln, temp, elementSize);
				}
			}
		}
	}
	free(temp);
	/** @todo **/
}
