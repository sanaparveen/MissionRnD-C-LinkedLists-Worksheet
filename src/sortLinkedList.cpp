/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
struct node * sortLinkedList(struct node *head);
void swap(struct node *p1, struct node*p2)
{
	int temp = p1->num;
	p1->num = p2->num;
	p2->num = temp;
}

struct node * sortLinkedList(struct node *head) {
     
	struct node *start = head;
	struct node *ptr;
	struct node *min;

	if (head == NULL)
		return NULL;

	while (start->next)
	{
		min = start;
		ptr = start->next;

		while (ptr)
		{

			if (min->num > ptr->num)
			{
				min = ptr;
			}

			ptr = ptr->next;
		}
		swap(start, min);			// Put minimum element on starting location
		start = start->next;
	}
	return (head);
}