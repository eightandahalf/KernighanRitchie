//Exercise 2 - 6. Write a function setbits(x, p, n, y) that returns x with the n bits that begin at
//position p set to the rightmost n bits of y, leaving the other bits unchanged.

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

char* DecToBin(int dec); // SOME EXPERIMENTS WITH BITWISE OPERATORS
void ArrReverse(char* array); // SOME EXPERIMENTS WITH BITWISE OPERATORS
void print(char* array);
int setbits(int x, int p, int n, int y); // KR_2.6

int main()
{
	////////////KR_2.6
	int x = 100, p = 5, n = 3, y = 501;
	printf("x before settbits is equal to %d\n"
			"p is equal to %d\n"
			"n is equal to %d\n"
			"y is equal to %d\n", x, p, n, y);
	int res = setbits(x, p, n, y);
	printf("x after settbits is equal to %d\n", res);
	////////////KR_2.6

	////////////SOME EXPERIMENTS WITH BITWISE OPERATORS
	char a = 14; // dec 15 = bin 1111
	char b = 10; // dec 10 = bin 1010

				 //char h = ~0 << 3;
				 //char j = 254;
				 //char k = 127;
				 //char l = 128;
				 //char u = 129;
				 //char q = 255;
				 //char z = 256;
				 //char x = 257;

	char* binb = DecToBin(b);
	int i = 0;
	printf("int %d is equal to bin ", b);
	while (binb[i] != '\0' && binb[i] != EOF)
		printf("%c", binb[i++]);

	ArrReverse(binb);

	free(binb);
	////////////SOME EXPERIMENTS WITH BITWISE OPERATORS

	printf("Press any key to exit..\n");
	getchar();
	return 0;
}

int setbits(int x, int p, int n, int y)
{
	// what we want to get:
	// for example: 
	// x = 100 = 01(100)100
	// indexes   76 543 210
	//
	// p = 5 - means, that starting from this index to the right we should insert the rightmost n = 3 bits from y
	// bits that we should copy from y to x are enclosed in parentheses (), this means, that the result should look
	// like this:
	// x = 01(101)100
	// n = 3 = 00000011 - number of bits, that we should copy from one place to another
	// y = 501 = 000111110(101)

	int res; 
	int maska = ~(~0 << n);
	//First, we must create a mask that will allow us to select 
	//the necessary n rightmost n bits from the number y, we 
	//do it with this line: int maska = ~(~0 << n) - we shift 
	//the number consisting entirely of bits with the value 1 to 
	//the value n to the left to add to the right of zeros 
	//number n, this is how the operation << works, it adds zeros 
	//to the right, then we invert everything, and we get that in 
	//the rightmost n bits we have ones, and in the remaining bits zeros.

	y = y & maska; // with this line we just leave only the necessary n rightmost bits in y

	maska = ~(maska << (p - n + 1));
	//Next, we modify our mask so that later we can zero out the 
	//cells in number x into which we want to insert the new values.
	//To do this, we first shift the mask to the left by the amount 
	//so that the mask stands exactly where the new bits in the variable 
	//x will stand, it is equal to p - n + 1. Next, we must invert this 
	//mask so that exactly where the new bits will be in x, there will 
	//be zeros, so that we can prepare x for inserting new data.

	x = x & maska; /*Here we apply the prepared mask to the variable 
	x to clear those cells in which the new data will be inserted*/

	x = x | (y << (p - n + 1));
	//shift the y variable to the left by the number p - n + 1 to 
	//shift the rightmost bits to the position where the new bits 
	//are to be inserted into the x variable.After that, we apply 
	//the logical OR operation and get the new value of x

	res = x;

	return res;
}

void print(char* array)
{
	int i = 0;
	while (array[i] != '\0' && array[i] != EOF)
		printf("%c", array[i++]);
	printf("\n");
}

void ArrReverse(char* array)
{
	int i = 0, j = 0, key = 0;
	while (array[i] != '\0' && array[i] != EOF)
		i++;

	printf("\nArray before reverse: ");
	print(array);

	while (i > j)
	{
		key = array[j];
		array[j++] = array[--i];
		array[i] = key;
	}

	printf("\nArray after reverse: ");
	print(array);
}

char* DecToBin(int dec)
{
	char* bin = (char*)malloc(sizeof(char) * MAXLINE);
	int i = 0;
	int rem = 0;
	while (dec > 0 && i < MAXLINE)
	{
		rem = dec % 2;
		bin[i++] = rem + '0'; // as char '1' has 49 decimal value. and char '0' has 48 decimal value
		dec = dec / 2;
	}
	bin = (char*)realloc(bin, (sizeof(char) * (i + 1)));

	bin[i] = '\0';

	return bin;
}

//1 mod 2 is a situation where the divisor, 2, is larger than the dividend, 1, 
//so the remainder you get is equal to the dividend, 1.
//char a = 1; 
//char b = 2; 
//a = a % b;
//printf("%d\n", a);


