#include <stdio.h>
#include "Vector.h"

int IsOdd(short s)
{
	return s % 2;
}

void Print(short s)
{
	printf("%d\n", s);
}

// TDD (Test-Driven Development) 테스트 주도 개발방법론
void TestVector()
{
	Vector* v1 = new Vector();

	//Vector* v = VT_Create(2);
	Vector* v = new Vector(2);


	//Set(v, 0, 3); // ar[0] = 1;
	v->Set(0, 3); // ar[0] = 1;
	v->Set(1, 5); // ar[0] = 1;

	//Resize(v, 4);
	v->Resize(4);

	v->Set(2, 1);
	v->Set(3, 2);

	v->Iterate(Print);

	short value = v->Get(1); // short value = ar[1];
	printf("value of 2st element : %d\n", value);

	printf("contains 3 : %d\n", v->Contains(3));
	printf("contains 4 : %d\n", v->Contains(4));

	printf("count of all : %d\n", v->Count());
	printf("count if : %d\n", v->Count(IsOdd)); // 조건을 만족하는 원소의 갯수

	delete v;
}

void TestLinkedList()
{


}

int main()
{
	TestVector();
	//TestLinkedList();

	return 0;
}