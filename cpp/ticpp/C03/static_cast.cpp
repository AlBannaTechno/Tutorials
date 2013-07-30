// C03: static_cast.cpp
void func(int) {}

int main()
{
	int i = 0x7fff // max pos value = 32767
	long l;
	float f;

	// (1) typical castless conversions:
	l = i;
	f = i;
	// also works:
	l = static_cast<long>(i);
	f = static_cast<float>(i);

	// (2) narrowing conversions:
	i = l; // may lose digits
	i = f; // may lose info
	// says "I know," eliminates warnings:
	i = static_cast<int>(l);
	i = static_cast<int>(f);
	char c = static_cast<char>(i);
	
	// (3) forcing a conversion from void*:
	void* vp = &i;
	// old way profuces a dangerous conversion:
	float* fp = (float*)(vp);
	// the new way is equally dangerous:
	fp = static_cast<float*>(vp);
	
	// (4) implicit type conversions, normally performed by the compiler:
	double d = 0.0;
	int x = d; // automatic type conversion
	x = static_cast<int>(d); // more explicit
	func(d); // automatic conversion
	func(static_cast<int>(d)); // more explicit
	
	return 0; 
}