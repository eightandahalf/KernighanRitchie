/*
	Write a program that reads a set of text lines and print the longest
*/
#define MAX_WORD_LEN 1000
#include <stdio.h>

int getline(char array[], int limit, int* length);
void copy(char array[], char longest_array[], int limit);
void print(char longest_array[], int longest_length);

main()
{
	char array[MAX_WORD_LEN];
	char longest_array[MAX_WORD_LEN];
	int longest_length = 0;
	int current_length = 0;
	printf("P.S To emulate EOF enter CTR-Z\n");
	printf("Welcome ladies and gentelmens\nPlease, type some piece of text, and this program will find the longest line and print it: \n");
	while (getline(array, MAX_WORD_LEN, &current_length))
	{
		if (longest_length == 0)
		{
			copy(array, longest_array, MAX_WORD_LEN);
			longest_length = current_length;
			current_length = 0;
		}
		else if (current_length < longest_length)
			;
		else if (current_length > longest_length)
		{
			copy(array, longest_array, MAX_WORD_LEN);
			longest_length = current_length;
			current_length = 0;
		}
	}

	if (longest_length > 0)
		print(longest_array, longest_length);
	else
		printf("\nSur, you didn't type even ony symbol\n");
}

void print(char longest_array[], int longest_length)
{
	int i = 0;
	printf("\nThe longest line of text is: \n");
	while (i < longest_length)
	{
		printf("%c", longest_array[i]);
		i++;
	}
}

void copy(char array[], char longest_array[], int limit)
{
	int i = -1;
	while (++i < limit)
		longest_array[i] = array[i];
}

int getline(char array[], int limit, int *length)
{
	int eof_flag = 1;
	int c, i = -1;
	while (((c = getchar()) != EOF) && c != '\n' && ++i < limit)
	{
		array[i] = c;
		(*length)++;
	}
	if (c == EOF)
		eof_flag = 0;
	if (c == '\n')
	{
		array[++i] = c;
		array[++i] = '\0';
		(*length)++;
	}
	return eof_flag;
}