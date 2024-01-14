//Exercise 2 - 3. Write a function htoi(s), which converts a string of hexadecimal digits
//(including an optional 0x or 0X) into its equivalent integer value.The allowable digits are 0
//through 9, a through f, and A through F.

#include <stdio.h>

#define MAXLINE 1000

void upper(char s[]) // procedure to transform string to uppercase string
{
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] >= 'a' && s[i] <= 'f')
		{
			s[i] = s[i] - ('a' - 'A');
		}
	}
}

int htoi(char s[])
{
	int n = 0;

	for (int i = 0; (s[0] == '0' && s[1] == 'x') && (s[i] != '\0' && s[i] != EOF); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			n = n * 16 + (s[i] - '0');
		else if (s[i] >= 'A' && s[i] <= 'F')
			n = n * 16 + (s[i] - 55); 
		// i write (s[i] - 55) because this expression transform string literal s[i] that 
		// represent hexadecimal value like 'A' or 'Z' to decimal value, 
		// e.g. literal 'A' equal to 65 decimal value in ascii, so, 
		// to convert this literal that represent hex A 
		// to decimal we should substract 55 from 65, to get 10.
		// also, every iteration we multiplication prev sum to 10, as we have hexadecimal notation
	}

	return n;
}

int atoi(char s[])
{
	int n = 0;

	for (int i = 0; (s[i] >= '0' && s[i] <= '9') && (s[i] != '\0' && s[i] != EOF); i++)
		n = n * 10 + (s[i] - '0'); 
		// i write (s[i] - '0') because this expression transform string literal s[i] that 
		// represent decimal value like '0' or '9' to decimal value, e.g. literal '9' equal 
		// to 57 decimal value in ascii, so, to convert dec literal '9' to decimal we should 
		// substract 48 from 57, to get 9 dec value. and, as 48 dec in ascii equal to '0' literal, 
		// then we write (s[i] - '0') instead of (s[i] - 48).
		// also, every iteration we multiplication prev sum to 10, as we have decimal notation
	return n;
}

void arr_print(char s[])
{
	for (int i = 0; s[i] != '\0' && s[i] != EOF; i++)
		printf("%c", s[i]);
	printf("\n");
}

int main()
{
	int dec_number;
	char s1[MAXLINE] = "0xFFaf123"; // string of hex 
	char s2[MAXLINE] = "1234"; // string of dec

	upper(s1);

	dec_number = htoi(s1);
	printf("from string of hex = "); arr_print(s1);
	printf("to dec = %d\n", dec_number);

	dec_number = atoi(s2);
	printf("\nfrom string of dec = "); arr_print(s2);
	printf("to dec = %d\n", dec_number);

	printf("\nPress any key to exit..\n");
	getchar();
	return 0;
}