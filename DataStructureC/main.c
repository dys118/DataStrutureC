#include <stdio.h>
#include "Vector.h"
#include "LinkedList.h"
#include "ArrayStack.h"
#include "ListStack.h"

int IsOdd(short s)
{
	return s % 2;
}

void Print(short s)
{
	printf("%d\n", s);
}

void TestListStack()
{
	ListStack* stack = LS_Create();

	LS_Push(stack, 3);
	LS_Push(stack, 5);
	LS_Push(stack, 1);
	LS_Push(stack, 2);

	printf("count : %d\n", LS_Count(stack));

	printf("pop : %d\n", LS_Pop(stack));
	printf("pop : %d\n", LS_Pop(stack));
	printf("pop : %d\n", LS_Pop(stack));
	printf("pop : %d\n", LS_Pop(stack));

	LS_Destroy(stack);
}

void TestArrayStack()
{
	ArrayStack* stack = AS_Create();

	AS_Push(stack, 3);
	AS_Push(stack, 5);
	AS_Push(stack, 1);
	AS_Push(stack, 2);

	printf("count : %d\n", AS_Count(stack));

	printf("pop : %d\n", AS_Pop(stack));
	printf("pop : %d\n", AS_Pop(stack));
	printf("pop : %d\n", AS_Pop(stack));
	printf("pop : %d\n", AS_Pop(stack));

	AS_Destroy(stack);
}

// TDD (Test-Driven Development) 테스트 주도 개발방법론
void TestVector()
{
	Vector* v = VT_Create(2);

	VT_Set(v, 0, 3); // ar[0] = 1;
	VT_Set(v, 1, 5);
	
	VT_Resize(v, 4);

	VT_Set(v, 2, 1);
	VT_Set(v, 3, 2);

	Iterate(v, Print);

	short value = VT_Get(v, 1); // short value = ar[1];
	printf("value of 2st element : %d\n", value);

	printf("contains 3 : %d\n", VT_Contains(v, 3));
	printf("contains 4 : %d\n", VT_Contains(v, 4));

	printf("count of all : %d\n", VT_Count(v));
	printf("count if : %d\n", VT_CountIf(v, IsOdd)); // 조건을 만족하는 원소의 갯수

	VT_Destroy(v);
}

void TestLinkedList()
{
	LinkedList* list = LL_Create();

	LL_AddFront(list, 3);
	LL_AddFront(list, 5);
	LL_AddFront(list, 1);
	LL_AddFront(list, 2);

	printf("%d\n", LL_RemoveBack(list));
	printf("%d\n", LL_RemoveBack(list));
	printf("%d\n", LL_RemoveBack(list));
	printf("%d\n", LL_RemoveBack(list));

	LL_Iterate(list, Print);

	LL_Remove(list, 5);

	LL_Iterate(list, Print);

	printf("contains 3 : %d\n", LL_Contains(list, 3));
	printf("contains 4 : %d\n", LL_Contains(list, 4));

	printf("count of all : %d\n", LL_Count(list));
	printf("count if : %d\n", LL_CountIf(list, IsOdd)); // 조건을 만족하는 원소의 갯수

	LL_Destroy(list);
}

int main()
{
	//TestVector();
	//TestLinkedList();
	//TestArrayStack();
	TestListStack();

	return 0;
}