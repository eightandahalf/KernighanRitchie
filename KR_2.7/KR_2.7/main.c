//Exercise 2 - 7. Write a function invert(x, p, n) that returns x with the n bits that begin at
//position p inverted(i.e., 1 changed into 0 and vice versa), leaving the others unchanged.

#include <stdio.h>

int invert(int x, int p, int n);

int main()
{
	int x = 100, p = 5, n = 3;

	printf("x before settbits is equal to %d\n"
		"p is equal to %d\n"
		"n is equal to %d\n", x, p, n);
	int res = invert(x, p, n);
	printf("x after settbits is equal to %d\n", res);



	printf("Press any key to exit..\n");
	getchar();
	return 0;
}

int invert(int x, int p, int n)
{
	int maska = ~(~0 << n);
	int res = x;
	res = x & maska; // have isolated the necessary bits from the X.
	res = ~res & maska;

	x = x & ~maska;

	res = x | res;

	return res;
}