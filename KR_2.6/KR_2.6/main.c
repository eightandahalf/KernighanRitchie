//Exercise 2 - 6. Write a function setbits(x, p, n, y) that returns x with the n bits that begin at
//position p set to the rightmost n bits of y, leaving the other bits unchanged.

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

char* DecToBin(int dec);
void ArrReverse(char* array);
void print(char* array);

int main()
{
	char a = 14; // dec 15 = bin 1111
	char b = 10; // dec 10 = bin 1010

	// bitwise &
	a = a % b;
	//printf("%d\n", a);

	char* binb = DecToBin(b);
	int i = 0;
	printf("int %d is equal to bin ", b);
	while (binb[i] != '\0' && binb[i] != EOF)
		printf("%c", binb[i++]);

	ArrReverse(binb);

	free(binb);
	printf("Press any key to exit..\n");
	getchar();
	return 0;
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


