/* K&R 1.7 Write a program to print the value of EOF */

#include <stdio.h>

void main()
{
	int c;
	while ((c = getchar()) != EOF)
		;
	printf("The value of EOF is equal to %d", c);
}