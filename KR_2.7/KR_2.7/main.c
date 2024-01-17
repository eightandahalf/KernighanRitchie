//Exercise 2 - 7. Write a function invert(x, p, n) that returns x with the n bits that begin at
//position p inverted(i.e., 1 changed into 0 and vice versa), leaving the others unchanged.

// what should we get as the result?
// let x = 100, p = 4, n = 4
// x in bin look like this x = 100 = 0110(0100)
// since indexing starts at 0, and the number of bits n is 4, 
// and the initial index is p = 4, we must invert the bits, that are 
// in parentheses in x
#include <stdio.h>

int invert(int x, int p, int n);

int main()
{
	int x = 100, p = 4, n = 4;

	printf("x before invert is equal to %d\n"
		"p is equal to %d\n"
		"n is equal to %d\n", x, p, n);
	int res = invert(x, p, n);
	printf("x after invert is equal to %d\n", res);

	printf("Press any key to exit..\n");
	getchar();
	return 0;
}

int invert(int x, int p, int n)
{
	int maska1 = ~((~(~0 << n)) << (p - n + 1));
	// The first mask is created in order to zeroize in the variable x 
	// those bits that we will invert, so that it will be easier to insert 
	// the inverted bits back into this variable later. This mask means the 
	// following: we fill the whole variable with units "~0", then we move 
	// these units to the left by the amount passed in the parameter n "~0 << n". 
	// Next we have a variable that consists of zeros and ones, approximately 
	// 11110000, then we need to invert it, "~(~0 << n)", we get something like 
	// 00001111, then we move it to the left by the amount that will allow us 
	// to zero the bits that will be further inverted "~(~0 << n)) << (p - n + 1)", 
	// we get something in the form of 00111100; the bits with one is a mask that 
	// says that these bits will be inverted, so these bits need to be zeroed, and 
	// to do this we invert the mask that we got "~((~(~(~0 << n))) << (p - n + 1))", 
	// and we get this mask 11000011, which zeroes the bits that will be inverted, 
	// and we leave the other bits as they were. 

	int maska2 = (~(~0 << n)) << (p - n + 1);
	// The second mask is used to extract the bits to be inverted from 
	// parameter x and invert them, while all other bits must be set to zero.
	// "~0 << n" - get 11110000.
	// "~(~0 << n))" - get 00001111
	// "(~(~0 << n)) << (p - n + 1)" - get 00111100 

	int res = x;
	int inverted_bits = x;

	res = res & maska1; // clear n bits that we will invert, and leave another bits as they were
	inverted_bits = ~(inverted_bits & maska2) & maska2; // extract n bits to invert, then
														// invert them, and apply maska2 to save only inverted n bits and set the other bits to zero

	res = res | inverted_bits;

	return res;
}