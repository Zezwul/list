#include "tests.h"
#include "list.h"
#include <criterion/criterion.h>

//int main()
//{
//	list* testList = listInit();
//	push_back(testList, 0);
////	pop_first(testList);
//	pop_last(testList);
////	list_print(testList);
////	list_clear(testList);
//	free(testList);
//	return 0;
//}

Test(test, popFirstTest)
{
	list* testList = createTestList(2);
	node* controlNextAdress = testList->head_p->next_p;
	pop_first(testList);
	cr_expect(testList->head_p == controlNextAdress);
	list_clear(testList);
}

Test(test, popLastTest)
{
	list* testList = createTestList(3);
	node* controlPreviousAdress = testList->head_p;
	node* controlNextAdress = testList->head_p->next_p;
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
	for(size_t i = 0; i < optimalNumberOfIterations; i++)
	{
		if (i == 1)
		{
			list* testList = createTestList(i);
			list_clear(testList);
			cr_expect(testList->head_p == NULL);
			break;
		}
		list* testList = createTestList(i);
		list_clear(testList);
		cr_expect(testList->head_p == NULL);

	}

}

