// C03: rotation.cpp
// Perform left and right rotations

unsigned char rol(unsigned char val)
{
	int highbit;

	if (val & 0x80) // 0x80 is the high bit only
		highbit = 1;
	else
		highbit = 0;
	
	// left shift (bottom bit becomes 0):
	val <<= 1;
	// rotate the high bit onto the bottom
	val |= highbit;

	return val;
}

unsigned char ror(unsigned char val)
{
	int lowbit

	if (val & 1) // check the low bit
		lowbit = 1;
	else
		lowbit = 0;

	val >>= 1; // right shift by one position
	// rotate the low bit onto the top:
	val |= (lowbit << 7);

	return val;
}