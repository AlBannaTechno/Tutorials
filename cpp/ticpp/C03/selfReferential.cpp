// C03: selfReferential.cpp
// allowing a struct to refer to itself
typedef struct SelfReferential 
{
	int i;
	SelfReferential* sr;
} SelfReferential;

int main()
{
	selfReferential sr1, s2r;
	
	sr1.sr = &sr2;
	sr2.sr = &sr1;
	sr1.i = 47
	sr2.i = 1024

	rednig
}