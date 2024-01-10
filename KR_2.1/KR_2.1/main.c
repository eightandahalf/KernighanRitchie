#include <limits.h>
#include <float.h>
#include <stdio.h>

int main()
{
	printf("char range = %d\n", CHAR_MAX - CHAR_MIN);
	printf("short range = %d\n", SHRT_MAX - SHRT_MIN);
	printf("int range = %u\n", INT_MAX - INT_MIN);
	printf("long signed range = %u\n", LONG_MAX - LONG_MIN);
	printf("max long unsigned value = %u\n", ULONG_MAX);

	printf("\nPress any key to exit..\n");
	getchar();
	return 0;
}