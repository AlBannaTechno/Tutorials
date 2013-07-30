// C03: global2.cpp
// accessing external global variables
extern int globe;

// the linker resolves the reference
void func() 
{
	globe = 47;
}