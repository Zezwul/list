#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int push_back(listS* list_p, int value)
{
	if (list_p->head_p == NULL)
	{
		list_p->head_p = (nodeS*)malloc(sizeof(nodeS));
		list_p->head_p->value = value;
		list_p->head_p->next_p = NULL;
		return 0;
	}

	nodeS* currentPointer = list_p->head_p;
	while (currentPointer->next_p != NULL)
	{
		currentPointer = currentPointer->next_p;
	}
	currentPointer->next_p = (nodeS*)malloc(sizeof(nodeS));
	currentPointer = currentPointer->next_p;
	currentPointer->next_p = NULL;
	currentPointer->value = value;

	return 0;
}

int list_print(const listS* list1)
{
	if (list1->head_p == NULL)
	{
		printf("no list to print\n");
		return -1;
	}

	nodeS* list = list1->head_p;
	while (list != NULL)
	{
		printf("->value: %d\n", list->value);
		printf("->pointer: %p\n\n", list->next_p);
		list = list->next_p;
	}
	return 0;
}

int pop_first(listS* list, int *valueBuff)
{
	if (list->head_p == NULL)
	{
		return -1;
	}
	nodeS* currentPointer = list->head_p;
	list->head_p = list->head_p->next_p;
	if (valueBuff)
	{
		*valueBuff = currentPointer->value;
	}

	free(currentPointer);
	currentPointer = NULL;
	return 0;
}

int pop_last(listS* list, int *valueBuff)
{
	if (list->head_p == NULL)
	{
		return -1;
	}

	if (list->head_p->next_p == NULL)
	{
		free(list->head_p);
		list->head_p = NULL;
		return -2;
	}

	nodeS* tempPointer = list->head_p;
	nodeS* currentPointer = tempPointer ->next_p;
	while (currentPointer->next_p != NULL)
	{
		currentPointer = currentPointer->next_p;
		tempPointer = tempPointer->next_p;
	}

	if (valueBuff)
	{
		*valueBuff = currentPointer->value;
	}
	free(currentPointer);
	tempPointer->next_p = NULL;

	return 0;
}

int list_clear(listS* list)
{
	if (list->head_p == NULL)
	{
		free(list);
		return -3;
	}
	while (list->head_p != NULL)
	{
		pop_first(list, NULL);
	}
	free(list);
	list->head_p = NULL;
	//printf("list->head_p: %p\n", )

	return 0;
}
