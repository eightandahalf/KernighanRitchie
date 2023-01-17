/*
	K&R 1.12 Write a program that prints its input one word per line 
*/
#define IN 1
#define OUT 0

#include <stdio.h>

void main()
{
	int c;
	int condition = OUT;
	while ((c = getchar()) != EOF)
	{
		if ((condition == OUT) && ((c == '\t') || (c == ' ') || (c == '\f')))
			continue;
		else if ((condition == IN) && ((c == '\t') || (c == ' ') || (c == '\f')))
		{
			putchar('\n');
			condition = OUT;
			continue;
		}

		putchar(c);
		condition = IN;
	}
}