//Exercise 2 - 4. Write an alternative version of squeeze(s1, s2) that deletes each character in
//s1 that matches any character in the string s2.

#include <stdio.h>

#define MAXLINE 1000

void squeeze(char s1[], char s2[]);
void print(char s[]);

int main()
{
	char s1[MAXLINE] = "hello, HELLO WORLD!";
	char s2[MAXLINE] = "hello, HLEB ARBUZAU!!";

	printf("first string: ");
	print(s1); // s1 before squeeze 
	printf("second string: ");
	print(s2); 

	squeeze(s1, s2);

	printf("first string after squeeze: ");
	print(s1); // s1 after squeeze 

	printf("Press any key to exit..\n");
	getchar();
	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i = 0, j = 0, k = 0; // i - index through s1 array
							 // j - index through new s1 array
							 // k - index through s2 array
	int find_flag = 0;		 // find_flag - a flag telling us that we have 
							 // found a similar element in s1 and s2.
							 // a value of 0 indicates that we didn't find a similar element
							 // a value of 1 indicates that we did

	for (i = j = 0; s1[i] != '\0' && s1[i] != EOF; i++)
	{
		while (s2[k] != '\0' && s2[k] != EOF)
		{
			if (s1[i] == s2[k++])
			{
				find_flag = 1;
				break;
			}
		}
		if (find_flag == 0)
			s1[j++] = s1[i];

		find_flag = 0;
		k = 0;
	}
	s1[j] = '\0';
}

void print(char s[])
{
	for (int i = 0; s[i] != '\0' && s[i] != EOF; i++)
		printf("%c", s[i]);
	printf("\n");
}