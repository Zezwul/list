#include "tests.h"
#include "list.h"
#include <criterion/criterion.h>

Test(test, popFirstTest)
{
	listS* testList = createTestList(2);
	nodeS* controlNextAdress = testList->head_p->next_p;
	pop_first(testList);
	cr_expect(testList->head_p == controlNextAdress);
	list_clear(testList);
}

Test(test, popLastTest)
{
	listS* testList = createTestList(3);
	nodeS* controlPreviousAdress = testList->head_p;
	nodeS* controlNextAdress = testList->head_p->next_p;
	while (controlNextAdress->next_p != NULL)
	{
		controlNextAdress = controlNextAdress->next_p;
	}
	pop_last(testList);
	cr_expect(controlPreviousAdress == testList->head_p);
	list_clear(testList);
}

Test(test, listClearTest)
{
	unsigned int optimalNumberOfIterations = 3;
	for (size_t i = 0; i < optimalNumberOfIterations; i++)
	{
		if (i == 1)
		{
			listS* testList = createTestList(i);
			list_clear(testList);
			cr_expect(testList->head_p == NULL);
			break;
		}
		listS* testList = createTestList(i);
		list_clear(testList);
		cr_expect(testList->head_p == NULL);
	}
}
