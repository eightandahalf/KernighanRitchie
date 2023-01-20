/*
	KR_1.24 Write a program to check a C program for rudimentary syntax errors like 
	unbalanced parentheses, brackets and braces. Don't forget about quotes, 
	both single and double, escape sequences, and comments
*/
///
/// (), {}, [] +
/// '', "", //, /**/ +
/// printf("% ", asdf);
/// printf("  ", var);
/// printf("d ", var);
/// printf("
/// 
#define MAX_LEN 1000

#include <stdio.h>

void counter(char c, int* left_amount, int* right_amount, char first_symbol, char second_symbol);
void check(int left_amount, int right_amount, char first_symbol, char second_symbol);
void quotes_check(int quotes_amount, char c);
void one_line_comment_check(int);
void big_comment_check(int);
void printf_check(int);
void print(char array[]);
int finding_printf(char arrray[], int i);

int main()
{
	int c, i = 0;
	char array[MAX_LEN];
	int left_parenth_amount = 0, right_parenth_amount = 0;
	int left_brackets_amount = 0, right_brackets_amount = 0;
	int left_braces_amount = 0, right_braces_amount = 0;
	int single_quotes_amount = 0;
	int double_quotes_amount = 0;

	int one_line_comment_state = 0, big_comment_open_state = 0, big_comment_close_state = 0;
	int not_properly_openend_one_line_comment = 0, not_properly_opened_big_comment = 0;

	int previous_printf_flag = 0;
	int escape_seq_mistakes = 0;

	printf("Input:\n");
	while ((c = getchar()) != EOF && i < (MAX_LEN - 1))
	{
		if (c == '/' && one_line_comment_state == 0)
		{
			one_line_comment_state++;
			big_comment_open_state++;
			continue;
		}
		else if (one_line_comment_state == 2)
		{
			if (c == '\n')
				one_line_comment_state = big_comment_open_state = big_comment_close_state = 0;
			continue;
		}
		else if (one_line_comment_state == 1 && c != '/' && c != '\*' && big_comment_close_state < 1)
		{
			not_properly_openend_one_line_comment++;
			not_properly_opened_big_comment++;
			one_line_comment_state = big_comment_open_state = big_comment_close_state = 0;
			continue;
		}
		else if (big_comment_close_state == 1 && c != '\*')
		{
			continue;
		}
		else if (big_comment_close_state == 2 && c != '/')
		{
			not_properly_opened_big_comment++;
			one_line_comment_state = big_comment_open_state = big_comment_close_state = 0;
			continue;
		}
		else if (big_comment_close_state == 2 && c == '/')
		{
			one_line_comment_state = big_comment_open_state = big_comment_close_state = 0;
			continue;
		}
		else if (big_comment_close_state == 1 && c == '\*')
		{
			big_comment_close_state++;
			continue;
		}
		else if (big_comment_open_state == 1 && c == '\*')
		{
			big_comment_close_state = 1;
			continue;
		}
		else if (one_line_comment_state == 1 && c == '/')
		{
			one_line_comment_state++; // 2
			continue;
		}
		else if (previous_printf_flag == 3 && c != '\"')
			continue;
		else if (previous_printf_flag == 3 && c == '\"')
			previous_printf_flag++;
		else if (previous_printf_flag == 4 && c == ',')
			previous_printf_flag = 0;
		else if (previous_printf_flag == 4 && c != ',')
		{
			escape_seq_mistakes++;
			previous_printf_flag = 0;
			continue;
		}

		counter(c, &left_parenth_amount, &right_parenth_amount, '(', ')'); // parentheses counting
		counter(c, &left_brackets_amount, &right_brackets_amount, '[', ']'); // brackets counting
		counter(c, &left_braces_amount, &right_braces_amount, '{', '}'); // braces counting
		if (c == '\'')
			single_quotes_amount++;
		else if (c == '\"')
			double_quotes_amount++;
		one_line_comment_state = 0;
		array[i++] = c;

		if (i > 5 && previous_printf_flag == 0)
		{
			if (finding_printf(array, i) == 0)
				;
			else
			{
				previous_printf_flag = 1;
				continue;
			}
		}
		else if (previous_printf_flag == 1 && c != '(')
		{
			escape_seq_mistakes++;
			previous_printf_flag == 0;
			continue;
		}
		else if (previous_printf_flag == 1 && c == '(')
		{
			previous_printf_flag = 2;
		}
		else if (previous_printf_flag == 2 && c != '\"')
		{
			escape_seq_mistakes++;
			previous_printf_flag = 0;
			continue;
		}
		else if (previous_printf_flag == 2 && c == '\"')
		{
			previous_printf_flag = 3;
		}
	}
	array[i] = '\0';
	check(left_parenth_amount, right_parenth_amount, '(', ')');
	check(left_brackets_amount, right_brackets_amount, '[', ']');
	check(left_braces_amount, right_braces_amount, '{', '}');
	quotes_check(single_quotes_amount, '\'');
	quotes_check(double_quotes_amount, '\"');
	one_line_comment_check(not_properly_openend_one_line_comment);
	big_comment_check(not_properly_opened_big_comment - not_properly_openend_one_line_comment);
	printf_check(escape_seq_mistakes);
}

int finding_printf(char array[], int i)
{
	// length of printf is 6 words then we should start from "iterator - 6" and also we should have char array[] = "printf" to find
	// this word in text
	int func_iterator = 0, arr_iterator = i - 6;
	char word_find[6];
	char word_printf[] = "printf";
	int flag_ok = 1; // meaning either "printf" correspond to last 6 symbols from array[] or not. When yes - flag_ok = 1, no - flag_ok = 0
	while (func_iterator < 6)
	{
		word_find[func_iterator++] = array[arr_iterator++];
	}
	for (int it = 0; it < 6; it++)
	{
		if (word_find[it] == word_printf[it])
			;
		else 
		{
			flag_ok = 0;
			return flag_ok;
		}
	}
	return flag_ok;
}


void quotes_check(int quotes_amount, char c)
{
	if ((quotes_amount % 2) != 0)
		printf("\n\t\t\t\t\tWARNING:\nInput code is incorrect!!!\nAmount of symbol %c is equal to %d and mod to 2 of this is not equal to 0\n", c, quotes_amount);
}

void big_comment_check(int not_properly_openend_big_comment)
{
	if (not_properly_openend_big_comment != 0)
		printf("\n\t\t\t\t\tWARNING:\nInput code is incorrect!!!\n%d time user didn't fully open area for big_comment(/* */)\n", not_properly_openend_big_comment);

}

void printf_check(int mistakes_amount)
{
	if (mistakes_amount != 0)
		printf("\n\t\t\t\t\tWARNING:\nInput code is incorrect!!!\n%d time user made mistakes while using function printf\n", mistakes_amount);

}

void one_line_comment_check(int not_properly_openend_one_line_comment)
{
	if(not_properly_openend_one_line_comment != 0)
		printf("\n\t\t\t\t\tWARNING:\nInput code is incorrect!!!\n%d time user didn't fully open area for one_line_comment(// )\n", not_properly_openend_one_line_comment);
}

void check(int left_amount, int right_amount, char first_symbol, char second_symbol)
{
	if (left_amount > right_amount)
		printf("\n\t\t\t\t\tWARNING:\nInput code is incorrect!!!\nAmount of symbol %c is equal to %d and more than amount of symbol %c which amount is %d\n", first_symbol, left_amount, second_symbol, right_amount);
	if (left_amount < right_amount)
		printf("\n\t\t\t\t\tWARNING:\nInput code is incorrect!!!\nAmount of symbol %c is equal to %d and more than amount of symbol %c which amount is %d\n", second_symbol, right_amount, first_symbol, left_amount);
}

void counter(char c, int *left_amount, int *right_amount, char first_symbol, char second_symbol)
{
	if (c == first_symbol)
		(*left_amount)++;
	else if (c == second_symbol)
		(*right_amount)++;
}

void print(char array[])
{
	int i = 0;
	while (array[i++] != '\0')
		printf("%c", array[i - 1]);
}