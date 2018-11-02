#ifndef LIST_H_
#define LIST_H_

typedef struct node
{
	struct node* next_p;
	int value;
} node;

typedef struct
{
	node* head_p;
} list;


int push_back(list* list, int value);
int pop_first(list* list);
int pop_last(list* list);
int list_print(const list* list1);
int list_clear(list* list);


#endif /* LIST_H_ */
