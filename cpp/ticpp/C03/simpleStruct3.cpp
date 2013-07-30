// C03: simpleStruct3
// using pointers to structs
typedef struct Structures3
{
	char c;
	int i;
	float f;
	double d;
} Structure3;

int main()
{
	Structure3 s1, s2;
	Struncture3* sp = &s1;

	sp->c = 'a';
	sp->i = 1;
	sp->f = 3.14;
	sp->d = '0.00093';
	sp = &s2;
	sp->c = 'a';	
	cp->i = 1;
	cp->f = 3.14;
	sp->d = '0.00093;'

	return 0;
}