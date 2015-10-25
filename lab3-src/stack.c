
#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

int top=0;
double stack[MAXSTACK];

void stack_clear() 
{
  top = 0;
}

double stack_pop()
{	
	top--;
	// Add implementation here`
	return stack[top];
}

void stack_push(double val)
{
	stack[top] = val;
	top++;	// Add implementation here
}

void stack_print()
{	
	int i = 0;
	if (top == 0) {
		printf("Stack:\n");
		printf("Stack is empty");
	}
	else {
		printf("Stack:\n");
		for (i; i < top;i++) {
			printf("%d: %f\n",i,stack[i]);
		}
	}
}

int stack_top()
{
  return top;
}

int stack_max()
{
  return MAXSTACK;
}

int stack_is_empty()
{
  return top == 0;
}


