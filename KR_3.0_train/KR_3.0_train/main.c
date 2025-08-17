#include <ctype.h>
#include <stdio.h>
/* atoi: convert s to integer; version 2 */
int atoi(char s[]);

int main()
{
	char s[] = " 12 3 2 2 + #234";
	int atoi_res;

	atoi_res = atoi(s);

	printf("res = %d\n", atoi_res);

	printf("Press any key to exit..\n");
	getchar();
	return 0;
}


int atoi(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++)
		;

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		i++;

	for (n = 0; isdigit(s[i]); i++)
		n = n * 10 + s[i] - '0';

	return n;
}
