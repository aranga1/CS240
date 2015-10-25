
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"

//
// Initialize a linked list
//
void llist_init(LinkedList * list)
{
	list->head = NULL;
}

//
// It prints the elements in the list in the form:
// 4, 6, 2, 3, 8,7
//
void llist_print(LinkedList * list) {

	ListNode * e;

	if (list->head == NULL) {
		printf("{EMPTY}\n");
		return;
	}

	printf("{");

	e = list->head;
	while (e != NULL) {
		printf("%d", e->value);
		e = e->next;
		if (e!=NULL) {
			printf(", ");
		}
	}
	printf("}\n");
}

//
// Appends a new node with this value at the beginning of the list
//
void llist_add(LinkedList * list, int value) {
	// Create new node
	ListNode * n = (ListNode *) malloc(sizeof(ListNode));
	n->value = value;

	// Add at the beginning of the list
	n->next = list->head;
	list->head = n;
}

//
// Returns true if the value exists in the list.
//
int llist_exists(LinkedList * list, int value) {
	ListNode * n = list->head;
	while (n != NULL) {
		if (n->value == value) {
			return 1;
		};
		n = n->next;
	}
	return 0;
}

//
// It removes the entry with that value in the list.
//
int llist_remove(LinkedList * list, int value) {
	ListNode * n = list->head;
	ListNode * n1 = n->next;

	while(n1 != NULL) {
		if (n1->value == value){
			n->next = n1->next;
			return 1;
		}
		n1 = n1->next;
		n = n->next;
	}
	return 0;

}

//
// It stores in *value the value that correspond to the ith entry.
// It returns 1 if success or 0 if there is no ith entry.
//
int llist_get_ith(LinkedList * list, int ith, int * value) {
	int c = 0;
	ListNode * n = list->head;
	while(n != NULL) {
		if(c == ith) {
			*value = n->value;
			return 1;
		}
		c++;
		n = n->next;
	}
	return 0;
}

//
// It removes the ith entry from the list.
// It returns 1 if success or 0 if there is no ith entry.
//
int llist_remove_ith(LinkedList * list, int ith) {
	ListNode * n = list->head;
	ListNode * n1 = n->next;
	int c = 1;
	while(n1 != NULL) {
		if (c == ith) {
			n->next = n1->next;
			return 1;
		}
		n1= n1->next;
		n = n->next;
		c++;
	}
	return 0;
}

//
// It returns the number of elements in the list.
//
int llist_number_elements(LinkedList * list) {
	int ct = 0;
	ListNode * n = list->head;
	while(n != NULL) {
		ct++;
		n = n->next;
	}
	return ct;
}


//
// It saves the list in a file called file_name. The format of the
// file is as follows:
//
// value1\n
// value2\n
// ...
//
int llist_save(LinkedList * list, char * file_name) {
	FILE * fd = fopen(file_name,"w+");
	ListNode * n = list->head;
	if (fd == NULL) {
		return 0;
	}
	while(n != NULL){
		fprintf(fd,"%d\n",n->value);
		n = n->next;
	}
	fclose(fd);
	return 0;
}

//
// It reads the list from the file_name indicated. If the list already has entries, 
// it will clear the entries.
//
int llist_read(LinkedList * list, char * file_name) {
	FILE * fd = fopen(file_name,"r");
	if (fd == NULL) {
		return 0;
	}
	//ListNode * n = NULL;
	list->head = NULL;
	int c;
	while(fscanf(fd, "%d", &c) == 1) {
		//fscanf(fd,"%d",&c);
		ListNode * new = (ListNode*)malloc(sizeof(ListNode));
		new->value = c;
		new->next = list->head;
		list->head = new;

	}
	return 1;
}
int sortArray(int n, int * array) {
	int i, j;
	int * temp = array;
	int tmp;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (*(temp + i) > * (temp + j)) {
				tmp = * (temp + i); 
				* (temp + i) = * (temp + j);
				* (temp +j) = tmp;
			}
		}
	}
	return 0;
}

//
// It sorts the list. The parameter ascending determines if the
// order si ascending (1) or descending(0).
//
void llist_sort(LinkedList * list, int ascending) {
	ListNode * e = list->head;
	int number = llist_number_elements(list);
	int * p = (int *) malloc (number * sizeof(int));
	int * a = p;
	int * b = p;
	int i = 0;
	while (e != NULL) {
		*(a + i) = e->value;
		e = e->next;
		i++;
	}
	sortArray(number, b);
	int j = 0;
	ListNode * f = list->head;
	if (ascending == 1) {
		while (f != NULL) {
			f->value = * (p + j);
			f = f->next;
			j++;
		}
	} else if (ascending == 0) {
		j = number - 1;
		while (f != NULL) {
			f->value = * (p + j);
			f = f->next;
			j--;
		}
	}







	/*ListNode * ptr1;
	  ListNode * ptr2 = NULL;
	  int tmp = 1;
	  if (ascending == 1) {
	  while(tmp) {
	  tmp = 0;
	  ptr1 = list->head;
	  while(ptr1->next != ptr2) {
	  if (ptr1->value > ptr1->next->value) {
	  int a = ptr1->value;
	  ptr1->value = ptr1->next->value;
	  ptr1->next->value = a;
	  tmp = 1;
	  }
	  ptr1 = ptr1->next;
	  }
	  ptr2 = ptr1;
	  }
	  }*/
	/*while (ptr1 != NULL) {
	  ptr2 = ptr1->next;
	  while(ptr2 != NULL) {
	  if (ptr1->value > ptr2->value) {
	  ptr1->value = tmp;
	  ptr1->value = ptr2->value;
	  ptr2->value = tmp;
	  }
	  ptr2 = ptr2->next;
	  }
	  ptr1 = ptr1->next;
	  }

	  if (ascending == 1) {
	  do {
	  swapped = 0;
	  while (ptr1->next != ptr2) {
	  if (ptr1->value > ptr1->next->value) {
	  tmp = ptr1->value;
	  ptr1->value = ptr1->next->value;
	  ptr1->next->value = tmp;
	  swapped = 1;
	  }
	  ptr1 = ptr1->next;
	  }
	  ptr2 = ptr1;
	  } while(swapped);
	  }
	  else {
	  do {
	  swapped = 0;
	  while (ptr1->next != ptr2) {
	  if (ptr1->value < ptr1->next->value) {
	  tmp = ptr1->value;
	  ptr1->value = ptr1->next->value;
	  ptr1->next->value = tmp;
	  swapped = 1;
	  }	
	  ptr1 = ptr1->next;
	  }
	  ptr2 = ptr1;
	  } while (swapped);
	  }*/
}

//
// It removes the first entry in the list and puts value in *value.
// It also frees memory allocated for the node
//
int llist_remove_first(LinkedList * list, int * value) {
	ListNode * n = list->head;
	if (n == NULL) {
		return 0;
	}
	*value = n->value;
	list->head = list->head->next;
	free(n);
	return 1;
}

//
// It removes the last entry in the list and puts value in *value/
// It also frees memory allocated for node.
//
int llist_remove_last(LinkedList * list, int *value) {
	ListNode * n = list->head;
	if (list->head ==NULL) {
		return 0;
	}
	while(n->next->next != NULL) {
		n = n->next;
	}
	*value = n->next->value;
	free(n->next);
	n->next = NULL;
	return 1;
}

//
// Insert a value at the beginning of the list.
// There is no check if the value exists. The entry is added
// at the beginning of the list.
//
void llist_insert_first(LinkedList * list, int value) {
	llist_add(list, value);
}

//
// Insert a value at the end of the list.
// There is no check if the name already exists. The entry is added
// at the end of the list.
//
void llist_insert_last(LinkedList * list, int value) {

	ListNode * n = (ListNode *) malloc (sizeof(ListNode));
	ListNode * e = list->head;
	if (list->head == NULL) {
		llist_add(list, value);

	} else {
		while (e->next != NULL) {
			e = e->next;
		}
		e->next = n;
		n->next = NULL;
		n->value = value;
	}





	/*ListNode * n1 = (ListNode*)malloc(sizeof(ListNode));
	  n1->value = value;
	  ListNode * a = list->head;
	  while (a->next != NULL) {
	  a = a->next;
	  }
	  a->next = n1;
	  n1->next = NULL;
	  }*/
}
//
// Clear all elements in the list and free the nodes
//
void llist_clear(LinkedList *list) {
	
	list->head = NULL;
	
	/*ListNode * n1 = list->head;
	while (n1->next != NULL) {
		list->head = list->head->next;
		free(n1);
		n1 = list->head;
	}*/
}
