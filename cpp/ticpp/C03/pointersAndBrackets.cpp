// C03: pointersAndBrackets.cpp
int main()
{
	int a[10];
	int* ip = a;

	for (int i = 0; i < 10; i++)
		ip[i] = i * 10;

	return 0;
}