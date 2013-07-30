// exercise 1: main program
#include "ex1-prints.h"

int main()
{	
	for (int i = 0; i < 5; i++) 
		prints(give_ascii(97 + i), give_int('a' + i), no_rounding(65, 1+i));

	return 0;
}