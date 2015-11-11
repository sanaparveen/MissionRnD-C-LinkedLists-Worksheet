/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
struct node *ptr1;
void deleteNum(struct node *head, int pos)
{
	struct node *prevNode, *currNode;
	int index;

	currNode = head;
	prevNode = NULL;


	for (index = 0; index<pos; index++)
	{
		prevNode = currNode;
		currNode = currNode->next;
	}
	prevNode->next = currNode->next;

}

struct node * removeEveryKthNode(struct node *head, int K) {

	int i = 0, count = 1, l;
	if (K <= 0 || head == NULL)
		return NULL;

	ptr1 = head;
	if (K == 1)
		head = 0;

	while (ptr1->next != NULL)
	{
		count++;
		i++;
		if (count == K&&K>1)
		{
			deleteNum(head, i);
			for (l = 1; l<K && (ptr1->next != NULL); l++)
				ptr1 = ptr1->next;
			count = 1;
		}
		else
			ptr1 = ptr1->next;
	}
	return head;
}

