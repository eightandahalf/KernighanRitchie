/*
	KR_1.21 Write a program entab that replaces string of blanks by the minimum 
	number of tabs and blanks to achieve the same spacing. 
*/
#define MAX_LEN 1000

#include <stdio.h>

void print(char array[]);

int main()
{
	int c, iterator = 0;
	char array[MAX_LEN];
	int space_counter = 0;
	while ((c = getchar()) != EOF && iterator < (MAX_LEN - 1))
	{
		if (c == ' ')
		{
			space_counter++;
			if (space_counter == 4) {
				iterator = iterator - 3;
				array[iterator++] = '\t';
				space_counter = 0;
				continue;
			}
			array[iterator++] = ' ';
			continue;
		}
		space_counter = 0;
		array[iterator++] = c;
	}
	array[iterator] = '\0';

	print(array);
	return 0;
}

void print(char array[])
{
	int i = 0;
	while (array[i++] != '\0')
		printf("%c", array[i - 1]);

	/// 
	/// TESTING THAT PROGRAM REALLY REPLACE TABS WITH 4 BLANKS
	/// 
	//int i = 0;
	//while (array[i++] != '\0')
	//{
	//	if (array[i - 1] == '\t')
	//	{
	//		putchar('$');
	//		continue;
	//	}
	//	else if (array[i - 1] == '\n')
	//	{
	//		putchar('.');
	//		printf("%c", array[i - 1]);
	//		continue;
	//	}
	//	printf("%c", array[i - 1]);
	//}
}