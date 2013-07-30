// C04: scoperes.cpp
// global scope resolution

int a;
void f() 
{}

struct S
{
	int a;
	void f();
};

void S::f() 
{
	::f();	// would be recursive otherwise!
	::a++;	// select the global a
	a --;	// the a at struct scope
}

int main()
{	
	S s; 
	f();
	return 0;
}