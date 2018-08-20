#include "LinkedList.h"
#include <stdlib.h>

LinkedList* LinkedList::LL_Create()
{

	Head = new Node;
	Tail = new Node;

	Head->Next = Tail;
	Tail->Previous = Head;

	return 0;
}

void LinkedList::LL_Add(short value)
{
	LL_AddBack(value);
}

void LinkedList::LL_AddFront(short value)
{
	Node *node = new Node;
	node->Value = value;

	node->Previous = Head;
	node->Next = Head->Next;

	Head->Next->Previous = node;
	Head->Next = node;
}

void LinkedList::LL_AddBack(short value)
{
	Node* node = new Node;
	node->Value = value;

	node->Next = Tail;
	node->Previous = Tail->Previous;

	Tail->Previous->Next = node;
	Tail->Previous = node;
}



void LinkedList::LL_Remove(short value)
{
	Node* node = LL_Find_Node(value);

	if (node == Tail)
		return;


}

short LinkedList::LL_RemoveFront()
{
	Node* node = Head->Next;

	if (node == Tail)
		return 0;


}

short LinkedList::LL_RemoveBack()
{
	Node* node = Tail->Previous;

	if (node == Head)
		return 0;


}

void LinkedList::LL_Iterate(void(*pf)(short))
{
	Node* node = Head->Next;

	while (node != Tail)
	{
		pf(node->Value);

		node = node->Next;
	}
}

int LinkedList::LL_Contains(short value)
{
	Node* node = LL_Find_Node(value);

	return node == Tail ? FALSE : TRUE;
}

int LinkedList::LL_Count()
{
	int count = 0;

	Node* node = Head->Next;

	while (node != Tail)
	{
		count++;

		node = node->Next;
	}

	return count;
}

int LinkedList::LL_CountIf(int (*fp)(short))
{
	int count = 0;

	Node* node = Head->Next;

	while (node != Tail)
	{
		if (fp(node->Value) == TRUE)
			count++;

		node = node->Next;
	}

	return count;
}

void LinkedList::LL_Destroy()
{
	free(Head);
	free(Tail);
	
}

Node* LinkedList::LL_Find_Node(short value)
{
	Node* current = Head->Next;

	while (current != Tail)
	{
		if (current->Value == value)
			return current;

		current = current->Next;
	}

	return Tail;
}