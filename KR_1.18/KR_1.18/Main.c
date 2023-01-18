/*
	Write a program to remove trailing blanks and tabs from each line of input, 
	and to delete entirely blank lines
*/
#define MAX_LEN 1000

#include <stdio.h>

main()
{
	int c;
	int line_length = 0, text_length = 0, space_flag = 0;
	char array[MAX_LEN];
	while ((c = getchar()) != EOF)
	{
		if (line_length == 0 && c == '\n') // +
			continue;
		else if (line_length == 0 && (c == '\t' || c == ' ')) // +
			continue;
		else if ( c == ' ' && space_flag == 0 && line_length > 1)
			space_flag = 1;
		else if (c == '\t' && space_flag == 0 && line_length > 1)
		{
			space_flag = 1;
			c = ' '; // i replace tab to blank that text could be more beautiful
		}
		else if ((c == '\t' || c == ' ') && space_flag == 1 && line_length > 1)
			continue;
		else if (c == '\n' && line_length < 2 && space_flag == 1)
		{
			putchar('\b');
			continue;
		}
		else if (c == '\n' && line_length > 1)
		{
			line_length = 0;
			array[text_length++] = c;
			space_flag = 0;
			continue;
		}
		if (c != ' ' && c != '\t')
			space_flag = 0;
		array[text_length] = c;
		line_length++;
		text_length++;
	}

	array[text_length++] = '\0';
	///
	///	Down below you can find two ways to print array of char
	/// 
	/*for (int i = 0; i < text_length; i++)
		printf("%c", array[i]);*/
	int iterator = 0;
	while (array[iterator] != '\0') 
	{
		printf("%c", array[iterator]);
		iterator++;
	}
}