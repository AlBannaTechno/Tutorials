// exercise 1: function file
#include <iostream>
using namespace std;

void prints(char let, int num, float dec)
{
	cout << "1: " << let << " | 2: " << num << " | 3: " << dec << endl;
}

char give_ascii(int num)
{
	return static_cast<char>(num);
}

int give_int(char let)
{
	return static_cast<int>(let);
}

float no_rounding(int num, int dev)
{
	return static_cast<float>(num / dev) * 0.237;
}