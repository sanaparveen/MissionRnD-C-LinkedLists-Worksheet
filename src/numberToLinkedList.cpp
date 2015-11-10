/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
struct node *head, *temp;

void insert(int value)
{
	temp = (struct node *) malloc(sizeof(struct node));

	temp->num = value;
	temp->next = head->next;
	head->next = temp;
}

struct node * numberToLinkedList(int N) {
	
	head = (struct node *) malloc(sizeof(struct node));

	if (N<0)
		N = -1 * N;
	head->num = NULL;
	head->next = NULL;
	if (N == 0)
		insert(0);
	while (N != 0)
	{
		insert(N % 10);
		N = N / 10;
	}
	
	head = head->next;
	return head;
}