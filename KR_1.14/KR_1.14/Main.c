/*
	K&R 1.14. Write a program to print a histogram of the frequencies of
	different characters in its input
*/

#include <stdio.h>
#include <stdbool.h>

int symbols_count(const char* text)
{
	int count = 0;
	while (text[count] != '\0')
		count++;
	return count;
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

int max_word_length(int* words_counter, int length_arr[])
{
	int max_length = 0;
	for (int i = 0; i < *words_counter; i++)
	{
		if (length_arr[i] > max_length)
			max_length = length_arr[i];
	}
	return max_length;
}

void horiz_histogram(int* elements_amount, int how_many_elem_appear[], int elemen_num_in_ascii[])
{
	int i = 0;
	int place_to_print_last_symb_to_beatiful_table = 0;
	printf("\n//////////////////////////////////////\n");
	printf("//////////HORIZONTAL HISTOGRAM////////\n");
	printf("//////////////////////////////////////\n\n");
	int max_length = max_word_length(elements_amount, how_many_elem_appear);
	int bound = max_length + symbols_count("$ Symbol \\n with ascii %3d appear %2d times! ") + 2; 
	horiz_boundary_print(bound - 1);
	while (i < *elements_amount && elemen_num_in_ascii[i] != -1)
	{
		place_to_print_last_symb_to_beatiful_table = symbols_count("$ Symbol \\n with ascii %3d appear %2d times! ");
		if (elemen_num_in_ascii[i] == 10)
			printf("$ Symbol \\n with ascii %3d appear %2d times! ", elemen_num_in_ascii[i], how_many_elem_appear[i]);
		else 
			printf("$ Symbol %2c with ascii %3d appear %2d times! ", elemen_num_in_ascii[i], elemen_num_in_ascii[i], how_many_elem_appear[i]);
		putchar('|');
		place_to_print_last_symb_to_beatiful_table++;;
		while (how_many_elem_appear[i] > 0)
		{
			putchar('-');
			how_many_elem_appear[i]--;
			place_to_print_last_symb_to_beatiful_table++;;
		}
		putchar('|');
		place_to_print_last_symb_to_beatiful_table++;
		while (place_to_print_last_symb_to_beatiful_table <= bound)
		{
			putchar(' ');
			place_to_print_last_symb_to_beatiful_table++;
		}
		putchar('$');
		putchar('\n');
		place_to_print_last_symb_to_beatiful_table = 0;
		i++;
	}
	horiz_boundary_print(bound - 1);
	putchar('\n');
}

void fill_with_minus_one(int array[], int amount)
{
	for (int i = 0; i < amount; i++)
		array[i] = -1;
}

bool already_exist(int used_elem[], int to_check, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		if (used_elem[i] == to_check)
			return true;
	}
	return false; // not found similar elements
}

void find_out(int input[], int amount)
{
	int elements_amount;
	int output_iterator = 0, count = 0, j = 0;
	int temp;
	int used_elem[100];
	int how_many_used[100];
	fill_with_minus_one(how_many_used, amount);
	fill_with_minus_one(used_elem, amount);
	int input_iterator = 0;
	while (input_iterator < amount && input[input_iterator] != -1)
	{
		temp = input[input_iterator];
		if (already_exist(used_elem, temp, amount))
		{
			input_iterator++;
			continue;
		}
		count++;
		j = input_iterator;
		while (j < amount && input[j] != -1)
		{
			j++;
			if (input[j] == temp)
			{
				count++;
			}
		}
		used_elem[output_iterator] = temp;
		how_many_used[output_iterator] = count;
		output_iterator++;
		input_iterator++;
		count = 0;
	}

	output_iterator = 0;
	while (output_iterator < amount && used_elem[output_iterator] != -1)
	{
		printf("Number in ascii - %d\tAppeared %d times\n", used_elem[output_iterator], how_many_used[output_iterator]);
		output_iterator++;
	}

	elements_amount = sizeof(used_elem) / sizeof(used_elem[0]);
	horiz_histogram(&elements_amount, how_many_used, used_elem);
}

void main()
{
	int c, count = 0;
	int encountered_elements[100];
	int amount = sizeof(encountered_elements) / sizeof(encountered_elements[0]);
	fill_with_minus_one(encountered_elements, amount);
	while ((c = getchar()) != EOF)
	{
		if (c == '\n' && count != 0)
		{
			encountered_elements[count] = c;
			find_out(encountered_elements, amount);
			fill_with_minus_one(encountered_elements, amount);
			count = 0;
			continue;
		}
		encountered_elements[count] = c;
		count++;
	}
}