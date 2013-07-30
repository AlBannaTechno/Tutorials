// C04: CppLib.h
// C-Like library converted to C++

struct Stash 
{
	int size;		// size of each space
	int quantity;	// number of storage spaces
	int next;		// next empty space
	// dynamically allocated array of bytes
	unsigned char* storage;
	// functions
	void initialize(int sz);
	void cleanup();
	int add(const void* element);
	void* fetch(int index);
	int count();
	void inflate(int increase);
};
