#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// push()
int push_back(list* list, int value)
{

	if(list->head_p == NULL)
	{
		list->head_p = malloc(sizeof(node));
		list->head_p->value = value;
		list->head_p->next_p = NULL;
		return 0;
	}

	node* currentPointer = list->head_p;
	while (currentPointer->next_p != NULL)
	{
		currentPointer = currentPointer->next_p;
	}
	currentPointer->next_p = malloc(sizeof(node));
	currentPointer = currentPointer->next_p;
	currentPointer->next_p = NULL;
	currentPointer->value = value;
	return 0;
}

//print()
int list_print(const list* list1)
{
	if (list1->head_p == NULL)
	{
		printf("no list to print\n");
		return -1;
	}

	node* list = list1->head_p;
	while (list != NULL)
	{
		printf("->value: %d\n", list->value);
		printf("->pointer: %p\n\n", list->next_p);
		list = list->next_p;
	}
	return 0;
}

//clear()

int pop_first(list* list) //delete first element of list
{

	if(list->head_p == NULL)
	{
		printf("no node to delete\n");
		return -1;
	}
	node* currentPointer = list->head_p;
	list->head_p = list->head_p->next_p;

	free(currentPointer);
	currentPointer = NULL;

	return 0;
}

int pop_last(list* list) //delete last element of list
{
	if(list->head_p == NULL)
	{
		printf("no node to delete\n");
		return -1;
	}

	if(list->head_p->next_p == NULL)
	{
		free(list->head_p);
		list->head_p = NULL;
		return -1;
	}


	node* currentPointer = list->head_p->next_p;
	node* tempPointer = list->head_p;
	while(currentPointer->next_p != NULL)
	{
		currentPointer = currentPointer->next_p;
		tempPointer = tempPointer->next_p;
	}

	free(currentPointer);
	tempPointer->next_p = NULL;

	return 0;
}

int list_clear(list* list)
{
	if(list->head_p == NULL)
	{
		printf("no list to clear\n");
		return 0;
	}
	while (list->head_p != NULL)
	{
		pop_first(list);
	}
	free(list);
	list->head_p = NULL;
	return 0;
}






