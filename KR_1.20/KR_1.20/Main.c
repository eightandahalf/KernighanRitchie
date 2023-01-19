/*
	KR_1.20 Write a program detab that replaces tabs in the input with 
	the proper number of blanks to space to the next tab stop.
*/
#define MAX_LEN 1000

#include <stdio.h>

void print(char array[], int size);

int main(void)
{
	int c, i = 0, from_tab_to_blank = 4;
	char array[MAX_LEN];
	while ((c = getchar()) != EOF && i < MAX_LEN)
	{
		if (c == '\t') {
			array[i++] = '<';
			while (from_tab_to_blank > 0)
			{
				array[i++] = ' ';
				from_tab_to_blank--;
			}
			from_tab_to_blank = 4;
			array[i++] = '>';
			continue;
		}
		array[i++] = c;
	}
	array[i] = '\0';

	print(array, i);

	return 0;
}

void print(char array[], int size)
{
	int i = 0;
	while (i < size)
		printf("%c", array[i++]);

}