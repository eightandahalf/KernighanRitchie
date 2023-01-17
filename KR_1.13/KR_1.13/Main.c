/*
	K&R 1.13 Write a program to print a histogram of the lengths of words in its input.
	It is easy to draw histogram with the bars horizontal; a vertical orientation is more
	challenging
*/
#define IN 1
#define OUT 0

#include <stdio.h>

int max_word_length(int *words_counter, int length_arr[])
{
	int max_length = 0;
	for (int i = 0; i < *words_counter; i++)
	{
		if (length_arr[i] > max_length)
			max_length = length_arr[i];
	}
	return max_length;
}

void horiz_boundary_print(int max_length)
{
	putchar('$');
	while (max_length > 0)
	{
		putchar('$');
		max_length--;
	}
	putchar('$');
	putchar('\n');
}

void horiz_histogram(int *words_counter, int length_arr[])
{
	printf("\n\n//////////////////////////////////////\n");
	printf("//////////HORIZONTAL HISTOGRAM////////\n");
	printf("//////////////////////////////////////\n\n");
	int max_length = max_word_length(words_counter, length_arr);
	horiz_boundary_print(max_length);
	for (int i = 0; i < *words_counter; i++)
	{
		putchar('|');
		while (length_arr[i] > 0)
		{
			putchar('-');
			length_arr[i]--;
		}
		putchar('|');
		putchar('\n');
	}
	horiz_boundary_print(max_length);
}

void vertic_histogram(int* words_counter, int words_length_arr[])
{
	printf("\n//////////////////////////////////////\n");
	printf("//////////VERTICAL HISTOGRAM//////////\n");
	printf("//////////////////////////////////////\n\n");
	int max_column_length = max_word_length(words_counter, words_length_arr);
	int columns_num, current_column_length = max_column_length;
	int i = 0;
	columns_num = *words_counter;
	while (current_column_length > 0)
	{
		while (i < columns_num)
		{
			if (words_length_arr[i] < current_column_length)
				;
			else if (words_length_arr[i] == current_column_length)
				putchar('-');
			else if(words_length_arr[i] > current_column_length)
				putchar('|');
			putchar('\t');
			i++;
		}
		i = 0;
		putchar('\n');
		current_column_length--;
	}
	while (i < columns_num)
	{
		putchar('-');
		putchar('\t');
		i++;
	}
}


void main()
{
	int length_arr[20];
	int c, condition = OUT;
	int words_counter = 0;
	int word_length = 0;
	while ((c = getchar()) != EOF)
	{
		if (((c == ' ') || (c == '\t')) && condition == IN)
		{
			length_arr[words_counter] = word_length;
			condition = OUT;
			word_length = 0;
			words_counter++;
		}
		else if (condition == OUT && c != ' ' && c != '\n' && c != '\t')
		{
			condition = IN;
			word_length++;
		}
		else if (condition == IN && c != ' ' && c != '\n' && c != '\t')
		{
			word_length++;
		}
		else if (c == '\n' && words_counter != 0)
		{
			vertic_histogram(&words_counter, &length_arr);
			horiz_histogram(&words_counter, &length_arr);
			for (int i = 0; i < words_counter; i++)
				length_arr[i] = 0;
			words_counter = 0;
			word_length = 0;
			condition = OUT;
			putchar('\n');
		}
	}
}