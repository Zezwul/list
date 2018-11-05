#ifndef LIST_H_
#define LIST_H_

typedef struct nodeS
{
	struct nodeS* next_p;
	int value;
} nodeS;

typedef struct listS
{
	nodeS* head_p;
} listS;

int push_back(listS* list, int value);
int pop_first(listS* list);
int pop_last(listS* list);
int list_print(const listS* list1);
int list_clear(listS* list);

#endif
