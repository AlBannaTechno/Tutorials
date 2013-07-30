// C04: CppLib.cpp
// C library converted to C++
#include <iostream>
#include <cassert>
#include "CppLib.h"

using namespace std;

// quantity of elements to add when increasing storage:
const int increment = 100;

void Stash::initialize(int sz) 
{
	size = sz;
	quantity = 0;
	storage = 0;
	next = 0;
}

int Stash::add(const void* element)
{
	if (next >= quantity) 	// enough space left?
		inflate(increment);

	// copy element into storage, start at next empty space:
	int startBytes = next * size;
	unsigned char* e = (unsigned char*)element;

	for (int i = 0; i < size; i++)
		storage[startBytes + i] = e[i];
	
	next++;
	return (next - 1);	// index number
}

void* Stash::fetch(int index) 
{
	//check index boundaries:
	assert(0 <= index);
	if (index >= next)
		return 0;	// to indicate the end

	return &(storage[index * size]);
}

int Stash::count()
{
	return next;	// number of elements in Stash
}

void Stash::inflate(int increase)
{
	assert(increase > 0);
	int newQuantity = quantity + increase;
	int newBytes = newQuantity * size;
	int oldBytes = quantity * size;
	unsigned char* b = new unsigned char[newBytes];

	for (int i = 0; i < oldBytes; i++)
		b[i] = storage[i];	// copy old to new
	delete []storage;		// delete old storage
	storage = b;			// point to new memory
	quantity = newQuantity;
}

void Stash::cleanup()
{
	if (storage != 0) {
		cout << "freeing storage" << endl;
		delete []storage;
	}
}