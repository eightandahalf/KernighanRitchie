//Exercise 2 - 9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
//in x. Explain why. Use this observation to write a faster version of bitcount.
//Bitcount counts the number of 1-bits in its integer argument.  

#include <stdio.h>

int simple_bitcount(unsigned x);
int complicated_bitcount(unsigned x);

int main()
{
	unsigned x = 200;
	int res = simple_bitcount(x);
	printf("x = %d, simple_bitcount = %d\n", x, res);

	res = complicated_bitcount(x);
	printf("x = %d, complicated_bitcount = %d\n", x, res);

	int y = 100;
	y &= (y-1);

	printf("Press any key to exit..\n");
	getchar();
	return 0;
}

int complicated_bitcount(unsigned x)
{
	// EXAMPLE:
	// x = 01100110
	// x &= (x - 1):
	// x &= (01100110 - 1) = 01100110 
	//						 &
	//						 01100101
	//						 =
	//						 01100100
	// x &= (01100100 - 1) = 01100100 
	//						 &
	//						 01100011
	//						 =
	//						 01100000
	// x &= (01100000 - 1) = 01100000 
	//						 &
	//						 01011111
	//						 =
	//						 01000000
	// x &= (01000000 - 1) = 01000000 
	//						 &
	//						 00111111
	//						 =
	//						 00000000
	int b;
	for (b = 0; x != 0; x &= (x - 1))
		b++;
	return b;
}

int simple_bitcount(unsigned x)
{
	int b;
	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}