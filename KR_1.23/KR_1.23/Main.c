/*
	KR_1.23 Write a program to remove all comments from a C program.
	Don't forget to handle quoted strings and character constant properly.
	C comments do not nest
*/

#define MAX_LEN 1000

#include <stdio.h>

void print(char array[]);

int main()
{
	int c, iterator = 0;
	char array[MAX_LEN];
	int forward_slash_state = 0, single_q_flag = 0, double_q_flag = 0;
	int line_comment_state = 0, big_comment_state = 0;
	while ((c = getchar()) != EOF && iterator < (MAX_LEN - 1))
	{
		// /**/ comment
		if (c == '/' && forward_slash_state == 0)
		{
			array[iterator++] = c;
			forward_slash_state++;
			continue;
		}
		// line comment start, i.e.every symbol after will commenting
		else if (forward_slash_state == 1 && c == '/')
		{
			forward_slash_state++;
			line_comment_state++;
			continue;
		}
		else if (forward_slash_state == 2 && line_comment_state == 1)
		{
			if (c == '\n')
			{
				line_comment_state = 0;
				forward_slash_state = 0;
				iterator--;
			}
			continue;
		}
		//
		else if (forward_slash_state == 1 && c == '*')
		{
			forward_slash_state++; // we inside comment
			big_comment_state++;
			continue;
		}
		else if (forward_slash_state == 2 && big_comment_state == 1)
		{
			if (c == '*')
				forward_slash_state = 3;
			continue;
		}
		else if (forward_slash_state == 3 && big_comment_state == 1)
		{
			if (c == '/')
			{
				forward_slash_state = 0;
				big_comment_state = 0;
				iterator--;
			}
			continue;
		}
		//
		// '...' - not shouldn't deleted
		if (c == '\'' && single_q_flag == 0)
		{
			single_q_flag = 1;
			array[iterator++] = c;
			continue;
		}
		else if (single_q_flag == 1)
		{
			if (c == '\'')
				single_q_flag = 0;
			array[iterator++] = c;
			continue;
		}
		//

		// "..." - not shouldn't deleted
		else if (c == '\"' && double_q_flag == 0)
		{
			double_q_flag = 1;
			array[iterator++] = c;
			continue;
		}
		else if (double_q_flag == 1)
		{
			if (c == '\'')
				double_q_flag = 0;
			array[iterator++] = c;
			continue;
		}
		//
		single_q_flag = 0;
		double_q_flag = 0;
		forward_slash_state = 0;
		array[iterator++] = c;
	}
	array[iterator] = '\0';

	print(array);
	return 0;
}

void print(char array[])
{
	int iterator = 0;
	printf("\n\n			PRINTING START:			\n");
	while (array[iterator++] != '\0')
		printf("%c", array[iterator - 1]);
}