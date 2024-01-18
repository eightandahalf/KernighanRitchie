// Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case,
// with a conditional expression instead of if-else. 

#include <stdio.h>

/* lower: convert c to lower case; ASCII only */
int lower(int c); 
int lower_without_ifelse(int c); 
int arr_size(const char* str);

int main()
{
	// KR_2.10
	printf("KR_2.10:\n");
	int c = 65;
	printf("before lower function: int c = %d, equivalent to char \"%c\"\n\n", c, c); 
	int c_lower = lower(c);
	printf("after lower function: int c = %d, equivalent to char \"%c\"\n\n", c_lower, c_lower); 
	c = 65;
	printf("before lower_without_ifelse function: int c = %d, equivalent to char \"%c\"\n\n", c, c); 
	int c_lower_without_ifelse = lower_without_ifelse(c);
	printf("after lower_without_ifelse function: int c = %d, equivalent to char \"%c\"\n\n", c_lower_without_ifelse, c_lower_without_ifelse); 
	// KR_2.10

	// SOME EXPERIMENT WITH CONDITIONAL EXPRESSIONS
	printf("SOME EXPERIMENT WITH CONDITIONAL EXPRESSIONS:\n");
	printf("%.6d\n%6d\n\n",1,1);

	const char* str = "hello world, hello dj khaled";
	int array_size = arr_size(str);
	
	for(int i = 0; i < array_size; i++) 
		printf("%6d%s", str[i], (i%10 == 9) ? "\n" : " ");

	int n = 1;
	printf("\n\nyou have %d item%s.\n", n, n==1 ? "" : "s");
	// SOME EXPERIMENT WITH CONDITIONAL EXPRESSIONS

	printf("Press any key to exit..\n");
	getchar();
	return 0;
}

int lower_without_ifelse(int c)
{
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : (c);	
}

int lower(int c)
{
	if(c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

int arr_size(const char* str)
{
	int size = 0;
	while(str[size] != '\0' && str[size] != EOF)
		size++;
	return size;	
}
