//Exercise 2 - 2. Write a loop equivalent to the for loop above
//(for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
//	s[i] = c;) without using && or || .

#include <stdio.h>

#define MAXLINE 1000

int getline(char s[], int limit);

int main()
{
	char s[MAXLINE];
	int limit = MAXLINE;
	int array_size;

	array_size = getline(s, limit);
	printf("Array size equal to: %d\n", array_size);

	printf("Press any key to exit..\n");
	getchar();
	return 0;
}

int getline(char s[], int limit)
{
	char c, array_size = 0;

	//for (i = 0; i < limit - 1 && (c = getchar()) != '\n' && c != EOF; i++)
	//{
	//	s[i] = c;
	//}

	printf("Print some text: \n");
	while ((c = getchar()) != '\n') {
		if (c != EOF) {
			if (array_size < limit - 1)
				s[array_size++] = c;
			else break;
		} else break;
	}

	return array_size;
}