#ifndef TESTS_H_
#define TESTS_H_

#include "list.h"

void testPushBack(void);
void testPopFront(void);
void testPopLast(void);
void testListClear(void);

list* listInit();
list* createTestList(unsigned int numberOfNodes);

#endif /*TESTS_H_*/
