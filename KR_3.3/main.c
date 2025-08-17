/* Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
that a leading or trailing - is taken literally */

#include <stdio.h>

void expand(char* s1, char* s2);
void print(char str[]);

int main()
{
	char* s1 = "a-b-c";
	char s2[1000] = {0};

	print(s1);
	expand(s1, s2);
	print(s2);

	printf("Press any key to exit..\n");
	getchar();
	return 0;
}

void expand(char* s1, char* s2){
	int shorthand_found = 0;
	int symbol_count = 0, new_symbol_count = 0;
	while(*s1 != '\0'){	
		s2[symbol_count++] = *s1;
		if(symbol_count > 3 && (s2[symbol_count - 1] != '-' &&
		s2[symbol_count - 2] == '-' && s2[symbol_count - 3] != '-')){
			if(s2[symbol_count - 3] < s2[symbol_count - 1]){
				print("aaaaaaa");
				char begin_symbol = s2[symbol_count - 3], end_symbol = s2[symbol_count - 1];
				while(begin_symbol < end_symbol){
					s2[new_symbol_count++] = ++begin_symbol;
				}
			}
		}
		s1++;
	}
}


void print(char str[])
{
	int i = 0;
	while (str[i] != '\0' && str[i] != EOF)
		printf("%c", str[i++]);
	printf("\n");
}