// C03: fileStatic.cpp
// File scope demonstration. Compiling and linking this file with fileStatic2.cpp will cause a 
// linker error

// file scope means only available in this file:
static int fs;

int main()
{
	fs = 1;
}