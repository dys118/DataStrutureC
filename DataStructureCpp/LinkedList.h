#pragma once
#pragma once

#define TRUE 1
#define FALSE 0

class Node
{
public:
	short Value;
	Node* Previous;
	Node* Next;
};

class LinkedList
{
private:
	Node* Head;
	Node* Tail;

public:
	LinkedList* LL_Create();
	void LL_Add(short value);
	void LL_AddFront(short value);
	void LL_AddBack(short value);
	void LL_Remove(short value);
	short LL_RemoveFront();
	short LL_RemoveBack();
	void LL_Iterate(void(*pf)(short));
	int LL_Contains(short value);
	int LL_Count();
	int LL_CountIf(int(*fp)(short));
	void LL_Destroy();
	Node* LL_Find_Node(short value);
};