/* K&R 1.8 Write a program to count blanks(' '), tabs and newlines */

#include <stdio.h>

void main()
{
	long numBlanks = 0, numTabs = 0, numNewLines = 0;
	int c;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			++numBlanks;
		else if (c == '\t')
			++numTabs;
		else if (c == '\n')
			++numNewLines;
	}
	
	printf("Number of blanks is equal to %d\nNumber of tabs is equal to %d\nNumber of newlines is equal to %d", numBlanks, numTabs, numNewLines);
}