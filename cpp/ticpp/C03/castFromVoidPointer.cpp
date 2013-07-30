// C03: castFromVoidPointer.cpp
int main()
{
	int i = 99;
	void* vp = &i;

	// Can't dereference a void pointer: *vp = 3; compile time error. 
	// Must be cast back to int before dereferencing:
	*((int*)vp) = 3;

	return 0;
}