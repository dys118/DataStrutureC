#pragma once

class Vector
{
private:
	int Size;
	short* Array;

public:
	Vector(int size = 4); // new
	~Vector(); // delete

	void Set(int index, short value);
	void Resize(int size);
	void Iterate(void(*func)(short));
	short Get(int index);
	int Contains(short value);
	int Count();
	int Count(int(*func)(short));
};