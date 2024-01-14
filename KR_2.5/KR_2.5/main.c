//Exercise 2 - 5. Write the function any(s1, s2), which returns the first location in a string s1
//where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
//(The standard library function strpbrk does the same job but returns a pointer to the
//	location.)

#include <stdio.h>

#define MAXLINE 1000

int any(char s1[], char s2[]);
void print(char s[]);

int main()
{
	char s1[MAXLINE] = "hello, my name is max +100500";
	//char s1[MAXLINE] = "123";
	char s2[MAXLINE] = "syy jay";

	printf("first string: ");
	print(s1);
	printf("second string: ");
	print(s2);

	int first_location = any(s1, s2);

	printf("Press any key to exit..\n");
	getchar();
	return 0;
}

int any(char s1[], char s2[])
{
	int pos = -1, i = 0, j = 0, k = 0;	// i - index through s1 array
										// j - index through new s1 array
									    // k - index through s2 array
	int find_flag = 0;					// find_flag - a flag telling us that we have 
									    // found a similar element in s1 and s2.
									    // a value of 0 indicates that we didn't find a similar element
									    // a value of 1 indicates that we did
	
	while (s1[i] != '\0' && s1[i] != EOF)
	{
		while (s2[k] != '\0' && s2[k] != EOF)
		{
			if (s1[i] == s2[k++])
			{
				find_flag = 1;
				pos = i;
				printf("\nfirst location in a first string where any character from the second string occurs,\n"
					"or -1 if first string contains no characters from second string is equal to %d\n"
					"and this character is '%c', his ascii code is %d\n"
					"P.S. countdown in a string from zero\n\n", pos, s1[i], s1[i]);
				break;
			}
		}
		if (find_flag == 1) {
			return pos;
		}

		i++;
		k = 0;
	}

	printf("\nfirst location in a first string where any character from the second string occurs,\n"
		"or -1 if first string contains no characters from second string is equal to %d,\n"
		"no matches found\n\n", pos);
	return pos;
}

void print(char s[]) {
	for (int i = 0; s[i] != '\0' && s[i] != EOF; i++)
		printf("%c", s[i]);
	printf("\n");
}
