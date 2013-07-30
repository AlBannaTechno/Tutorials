// C03: voidPointer.cpp
int main()
{
	void* vp;
	char c;
	int i;
	float f;
	double d;

	// the address of ANY type can be assigned to a void pointer:
	vp = &c;
	vp = &i;
	vp = &f;
	vp = &d;

	return 0;
}