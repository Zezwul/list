#include "tests.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//#include "criterion/criterion.h"

// listInit
list* listInit()
{
	list* list1 = NULL;
	list1 = malloc(sizeof(list));
	list1->head_p = NULL;

	return list1;
}

list* createTestList(unsigned int numberOfNodes)
{
	list* testList = listInit();
	for(size_t i = 0; i < numberOfNodes; i++)
	{
		push_back(testList, i);
	}
	return testList;
}

void testPushBack(void)
{
	list* testList = listInit();

	static unsigned int pushBackCounter = 0;
	unsigned int numberOfElements = 3;
	for(size_t i = 0; i < numberOfElements; i++)
	{
		push_back(testList, i);
		pushBackCounter++;
	}

	printf("expected number of nodes: %d\n", numberOfElements);
	printf("actual number of nodes: %d\n", pushBackCounter);

	//assert((numberOfElements != pushBackCounter), "push_back test failed\n");
	if(numberOfElements == pushBackCounter)
	{
		printf("push_back function test was successul\n");
	} else
	{
		printf("push_back test failed\n");
	}

	list_clear(testList);
	free(testList);
}

void testPopFront(void)
{
	list* testList = listInit();
	unsigned int numberOfElements = 3;

	for(size_t i = 0; i < numberOfElements; i++)
	{
		push_back(testList, i);
	}

	node* controlNextAdress = testList->head_p->next_p;
	pop_first(testList);
	if (testList->head_p == controlNextAdress)
	{
		 printf("pop function test was successful\n");
	} else
	{
		 printf("pop function test failed\n");
	}
	list_clear(testList);
}

//void testPopLast(void)
//{
//	list* testList = listInit();
//	unsigned int numberOfElements = 3;
//	//node* controlPreviousAdress =
//
//	for(size_t i = 0; i < numberOfElements; i++)
//	{
//		push_back(testList, i);
//	}
//	pop_last(testList);
//
//}

void testListClear(void)
{
	list* testList = listInit();
	unsigned int numberOfElements = 3;
	for(size_t i = 0; i < numberOfElements; i++)
	{
		push_back(testList, i);
	}

	node* controlHeadAdress = testList->head_p;
	list_clear(testList);
	if (controlHeadAdress == testList->head_p)
	{
		printf("mission failed\n");
	} else
	{
		printf("list_clear was tested successful\n");
	}
}







