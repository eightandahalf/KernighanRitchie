/*
	KR_1.22 Write a program to "fold" long input lines into two or
	more shorter lines after the last non-blank character that occurs 
	before the n-th column of input. Make sure your program does something
	intelligent with very long lines, and if there are no blanks or tabs 
	before the specified column
*/
#define MAX_LEN 1000
#define LINE_LIMIT 25

#include <stdio.h>

void print(char array[]);

int main(void)
{
	int c, line_size_counter = 0, iterator = 0;
	char array[MAX_LEN];
	printf("Input: \n");
	while ((c = getchar()) != EOF && iterator < (MAX_LEN - 1))
	{
		if (c == '\n')
			continue;
		if (line_size_counter > LINE_LIMIT && (c == ' ' || c == '\t' || c == '.' || c == ')' || c == '!' || c == '?' || c == ';'))
		{
			array[iterator++] = c;
			array[iterator++] = '\n';
			line_size_counter = 0;
			continue;
		}
		array[iterator++] = c;
		line_size_counter++;
	}

	array[iterator] = '\0';
	printf("\nOutput: \n");
	print(array);

	return 0;
}

void print(char array[])
{
	int iterator = 0;
	while (array[iterator++] != '\0')
		printf("%c", array[iterator - 1]);
}