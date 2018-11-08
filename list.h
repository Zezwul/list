#ifndef LIST_H_
#define LIST_H_

enum
{
	ERR_NO_NODE_TO_POP = -1,
	ERR_NO_VALUE_TO_POP = -3
};

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
int pop_first(listS* list, int *valueBuff);
int pop_last(listS* list, int *valueBuff);
int list_print(const listS* list1);
int list_clear(listS* list, int *valueBuff);

#endif
