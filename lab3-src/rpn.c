#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

#include "rpn.h"
#include "nextword.h"
#include "stack.h"

double rpn_eval(char * fileName, double x) {

	double a,b,temp,ans;
	FILE *fd;

	fd = fopen(fileName,"r");
	if (fd == NULL) {
		printf("Could not open file %s\n", fileName);
		exit(1);
	}
	char * word;
	while ((word = nextword(fd)) != NULL) {
		if (strcmp(word,"+") == 0) {
			a = stack_pop();
			b = stack_pop();
			ans = b + a;
			stack_push(ans);
			continue;
		}
		else if (strcmp(word,"-") == 0) {
			a = stack_pop();
			b = stack_pop();
			ans = b - a;
			stack_push(ans);
			continue;
		}
		else if (strcmp(word,"*") == 0) {
			a = stack_pop();
			b = stack_pop();
			ans = b * a;
			stack_push(ans);
			continue;
		}
		else if (strcmp(word,"/") == 0) {
			a = stack_pop();
			b = stack_pop();
			ans = b / a;
			stack_push(ans);
			continue;
		}
		else if (strcmp(word,"sin") == 0) {
			a = stack_pop();
			ans = sin(a);
			stack_push(ans);
			continue;
		}
		else if (strcmp(word,"cos") == 0) {
			a = stack_pop();
			ans = cos(a);
			stack_push(ans);
			continue;
		}
		else if (strcmp(word,"log") == 0) {
			a = stack_pop();
			ans = log(a);
			stack_push(ans);
			continue;
		}
		else if (strcmp(word,"exp") == 0) {
			a = stack_pop();
			ans = exp(a);
			stack_push(ans);
			continue;
		}
		else if (strcmp(word,"pow") == 0) {
			a = stack_pop();
			b = stack_pop();
			ans = pow(b, a);
			stack_push(ans);
			continue;
		}
		else if (strcmp(word,"x") == 0) {
			stack_push(x);
			continue;
		}
		double val = atof(word);
		stack_push(val);
	}
	if (stack_top() > 1) {
		printf("Elements remain in the stack\n");
		exit(1);
	}
	else if (stack_top() == 0) {
		printf("Stack underflow\n");
		exit(1);
	}
	double retval; 
	retval = stack_pop();
	return retval;
}
