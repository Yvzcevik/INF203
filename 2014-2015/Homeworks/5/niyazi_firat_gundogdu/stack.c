#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void stack_free(struct stackNode **top)
{
	struct stackNode *ttop = *top;
	while (ttop != NULL) {
		struct stackNode *orphan = ttop;
		ttop = ttop->next;
		free(orphan);
	}
	*top = NULL;
}

/* TODO */
void stack_push(struct stackNode **top, double data)
{
	struct stackNode *newNode;
	newNode = malloc(sizeof(struct stackNode));
	newNode->data = data;
	newNode->next = *top;
	*top = newNode;
}

void stack_print(struct stackNode *top)
{
	/* Stack bos mu? */
	if (!stack_is_empty(top)) {
		printf("(");
		while (top != NULL) {
			printf("%3.2f -> ", top->data);
			top = top->next;
		}
		printf("NULL)\n");
	} else {
		printf("(EMPTY)\n");
	}
}

/* TODO */
double stack_pop(struct stackNode **top)
{
	/* Stack bos ise -1 dondurelim. */
	struct stackNode *temp = *top;
	double topData;

	if (temp != NULL) {
		//temp = *top;
		*top = (*top)->next;
		topData = temp->data;
		free(temp);
		return topData;
	} else {
		fputs("Error: Stack is empty!\n", stderr);
		return -1;
	}
}
