/*
	K&R 1.14. Write a program to print a histogram of the frequencies of
	different characters in its input
*/

#include <stdio.h>

void fill_with_minus_one(int array[], int amount)
{
	for (int i = 0; i < amount; i++)
		array[i] = -1;
}

void find_out(int input[], int amount)
{
	int i = 0, count = 0, j = 0;
	int temp;
	int used_elem[100];
	int how_many_used[100];
	fill_with_minus_one(how_many_used, amount);
	fill_with_minus_one(used_elem, amount);

	while (i < amount && input[i] != -1)
	{
		temp = input[i];
		count++;
		j = i;
		while (j < amount && input[j] != -1)
		{
			j++;
			if (input[j] == temp)
			{
				count++;
			}
		}
		used_elem[i] = temp;
		how_many_used[i] = count;
		count = 0;
		i++;
	}

	i = 0;
	while (i < amount && used_elem[i] != -1)
	{
		printf("Number in ascii - %d\tAppeared %d times\n", used_elem[i], how_many_used[i]);
		i++;
	}
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
			find_out(encountered_elements, amount);
			fill_with_minus_one(encountered_elements, amount);
			count = 0;
		}
		encountered_elements[count] = c;
		count++;
	}
}