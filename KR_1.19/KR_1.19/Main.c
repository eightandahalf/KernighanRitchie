/*
	Write a function reverse(s) that reverses the character string s.
	Use it to write a program that reverses	its input a line at a time
*/
#define MAX_LEN 1000

#include <stdio.h>

void reverse(char array[], char rev_arr[], int limit);
void print(char array[], int line_length);

main()
{
	char arr[MAX_LEN], rev_arr[MAX_LEN];
	int c, line_length = 0, text_length = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\n' && line_length == 0)
			continue;
		else if (c == '\n' && line_length > 0)
		{
			arr[line_length++] = '\0';
			reverse(arr, rev_arr, line_length - 1);
			print(rev_arr, line_length);
			line_length = 0;
			text_length = 0;
			continue;
		}
		arr[text_length] = c;
		line_length++;
		text_length++;
	}

}

void print(char array[], int line_length)
{
	for (int i = 0; i < line_length; i++)
		printf("%c", array[i]);
	putchar('\n');
}

void reverse(char array[], char rev_arr[], int line_length)
{
	int iterator = 0;
	while (line_length > 0)
	{
		rev_arr[iterator++] = array[--line_length];
	}
	rev_arr[iterator++] = '\0';
}