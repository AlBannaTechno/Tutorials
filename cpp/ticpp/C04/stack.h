// C04: stack.h
// nested struct in linked list
#ifndef STACK_H
#define STACK_H

struct Stack 
{
	struct Link
	{
		void* data;
		Link* next;
		void initialize(void*, Link*);
	}* head;

	void initialize();
	void push(void*);
	void* peek();
	void* pop();
	void cleanup();
};

#endif