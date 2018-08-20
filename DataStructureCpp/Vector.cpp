#include "Vector.h"
#include <stdlib.h>

Vector::Vector(int size) // 기본 매개변수
{
	Size = size;
	Array = new short[size];
}

Vector::~Vector()
{
	delete[] Array;
}

void Vector::Set(int index, short value)
{
	// VT_Set(v, 1, 5);
	Array[index] = value;
}

void Vector::Resize(int size)
{
	short* ar = new short[size];

	for (int i = 0; i < Size; i++)
		ar[i] = Array[i];

	delete[] Array;

	Array = ar;
	Size = size;
}

void Vector::Iterate(void(*func)(short))
{
	for (int i = 0; i < Size; i++)
		func(Array[i]);
}

short Vector::Get(int index)
{
	return Array[index];
}

int Vector::Contains(short value)
{
	for (int i = 0; i < Size; i++)
		if (Array[i] == value)
			return 1;

	return 0;
}

int Vector::Count()
{
	return Size;
}

int Vector::Count(int(*func)(short))
{
	int count = 0;

	for (int i = 0; i < Size; i++)
		if (func(Array[i]) == 1)
			count++;

	return count;
}
