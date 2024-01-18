//Exercise 3 - 2. Write a function escape(s, t) that converts characters like newline and tab
//into visible escape sequences like \n and \t as it copies the string t to s.Use a switch.Write
//a function for the other direction as well, converting escape sequences into the real characters.

// the newline has a decimal value of 10
// the tab has a decimal value of 9

// init string: 
// Hello wor011ld109My name is 1 0HLEB!!1099BAM9BAM
// result:
// Hello wor011ld
//		My name is 1 0HLEB!!
//			 BAM     BAM

#include <stdio.h>

#define MAXLINE 1000 

void escape(char s[], char t[]);
void print(char str[]);

int main()
{
	char s[1000] = "Hello wor011ld109My name is 1 0HLEB!!1099BAM9BAM";
	char t[1000] = {0};

	print(s);
	escape(s, t);
	print(t);

	printf("Press any key to exit..\n");
	getchar();
	return 0;
}

void escape(char s[], char t[])
{
	int i = 0, j = 0;
	while (s[i] != '\0' && s[i] != EOF)
	{
		switch (s[i]) {
		case '1':
			if (s[++i] == '0')
			{
				i++;
				t[j++] = '\n';
			}	else { t[j++] = s[--i]; i++; }
			break;
		case '9':
			i++;
			t[j++] = '\t';
			break;
		default:
			t[j++] = s[i++];
		}
	}
	
	t[j] = '\0';
}

void print(char str[])
{
	int i = 0;
	while (str[i] != '\0' && str[i] != EOF)
		printf("%c", str[i++]);
	printf("\n");
}