// C03: complicatedDefinitions.cpp

/* 1. */	void * (*(*fp1)(int))[10];
// fp1 is a pointer to a function that takes an integer argument and returns a pointer to an array
// of 10 void pointers

/* 2. */	float (*(*fp2)(int,int,float))(int);
// fp2 is a pointer to a function that takes three arguments and returns a pointer to a function 
// that takes an integer argument and returns a float

/* 3. */	typedef double (*(*(*fp3)())[10])();
			fp3 a;
// fp3 is a pointer to a function that takes no arguments and returns a pointer to an array of 10
// pointers to functions that take no arguments and return  doubles
// a is one of these fp3 types

/* 4. */	int (*(*f4())[10])();
// f4 is a function that returns a pointer to an array of 10 pointers to functions that return 
// integers

int main() {};