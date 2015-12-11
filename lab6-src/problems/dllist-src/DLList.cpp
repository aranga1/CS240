#include "DLList.h"
#include <stdio.h>
DLList::DLList()
{
	DLNode *e = new DLNode();
	head =e;
	head->next = e;
	head->prev = e;
}

DLList::~DLList()
{
	delete head->next;
}

void DLList::print()
{
	DLNode *n;
	n = head->next;
	while(n != head){
		printf("%d\n", n->data);
		n = n->next;
	}
}

void DLList::printSorted()
{
	DLNode *e ;
	e = head->next;
	int count =0;
	while(e != head){
		count++;
		e=e->next;
	}
	int array[count];
	e=head->next;
	int i=0;
	while(e != head ){
		array[i]=e->data;
		e=e->next;
		i++;
	}
	for(int j =0; j<count;j++){
		for(int k = j+1; k < count; k++){
			if(array[k]<array[j] ){
				int temp = array[j];
				array[j]=array[k];
				array[k]=temp;
				i++;
			}
		}
	}
	for(int a=0; a<count; a++){
		printf("%d\n", array[a]);
	}
}
void DLList::insertFront(int data)
{
	DLNode *n1 = new DLNode();
	DLNode *n;
	n = head->next;
	head->next = n1;
	n1->next = n;
	n->prev = n1;
	n1->prev = head;
	n1->data = data;
}

bool DLList::removeLast(int & data)
{
	DLNode * n;

	if(head->next == head){
		return false;
	}
	n = head->prev;
	n->prev->next = head;
	n->next->prev = n->prev;
	data = n->data;
	free(n);
	return true;
}

DLList * DLList::difference(DLList & list)
{
	DLList * diff = new DLList();
	DLNode *n1 = this->head->prev;
	DLNode *n2 = list.head->prev;
	while( n1 != this->head ){
		int flag =0;
		while( n2 != list.head){
			if(n1->data == n2->data){
				flag =1;
			}
			n2=n2->prev;
		}
		if(flag ==0){
			diff->insertFront(n1->data);
		}

		n2=list.head->prev;
		n1=n1->prev;
	}
	return diff;
}

DLList * DLList::getRange(int start, int end)
{
	return this;
}

DLList * DLList::intersection(DLList & list)
{
	DLList * inter = new DLList();
	DLNode *n1 = this->head->prev;
	DLNode *n2 = list.head->prev;
	while(n1 !=this->head) {
		while(n2 != list.head) {

			if(n2->data == n1->data) {
				inter->insertFront(n1->data);
				break;
			}
			n2 = n2->prev;
		}
		n2 = list.head->prev;
		n1 = n1->prev;
	}
	return  inter;
}

void DLList::removeRange(int start, int end)
{

}
