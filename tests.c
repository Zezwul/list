#include "tests.h"

#include <stdio.h>
#include <stdlib.h>

listS* listInit()
{
	listS* list1 = malloc(sizeof(listS));
	list1->head_p = NULL;

	return list1;
}

listS* createTestList(unsigned int numberOfNodes)
{
	listS* testList = listInit();
	for(size_t i = 0; i < numberOfNodes; i++)
	{
		push_back(testList, i);
	}

	return testList;
}





