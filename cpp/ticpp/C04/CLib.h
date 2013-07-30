// C04: CLib.h
// header file for C-like library, an array-like entity created at runtime

typedef struct CStashTag 
{
	int size;		// size of each space
	int quantity;	// number of stroage spaces 
	int next;		// next empty space
	// dynamically allocated array of bytes:
	unsigned char* storage;
}	CStash;

void initialize(CStash*, int);
void cleanup(CStash* s);
int add(CStash*, const void*);
void* fetch(CStash*, int);
int count(CStash*);
void inflate(CStash*, int);