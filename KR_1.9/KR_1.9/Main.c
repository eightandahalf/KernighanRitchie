/* 
	K&R 1.9 Write a program to copy its input to its output, 
	replacing each string of one or more blanks by a single blank

	1         2      3         4\n
	1 2 3 4
*/

#include <stdio.h>

void main()
{
	int c;
	int flag = 1; // flag that tells for us that we can or not printing blanks 
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' && flag == 1)
		{
			putchar(c);
			flag = 0;
		}
		else if (c == ' ' && flag != 1)
			;
		else
		{
			putchar(c);
			flag = 1; // it means that we print some char that not equal to blank and now we again can print blank
		}
	}


}