#include <limits.h>
#include <float.h>
#include <stdio.h>
#include <float.h>

int main()
{
	int char_max = CHAR_MAX;
	int char_min = CHAR_MIN;
	int char_range = char_max - char_min;

	long shrt_max = SHRT_MAX;
	long shrt_min = SHRT_MIN;
	long shrt_range = shrt_max - shrt_min;

	long long int_max = INT_MAX;
	long long int_min = INT_MIN;
	long long int_range = int_max - int_min;

	long long long_max = LONG_MAX;
	long long long_min = LONG_MIN;
	long long long_range = long_max - long_min;

	unsigned long long ulong_range = ULONG_MAX;

	double float_max = FLT_MAX;
	double float_min = FLT_MIN;
	double float_range = float_max - float_min;

	long double double_max = DBL_MAX;
	long double double_min = DBL_MIN;
	long double double_range = double_max - double_min;
	
	long double long_double_max = LDBL_MAX;
	long double long_double_min = LDBL_MIN;
	long double long_double_range = long_double_max - long_double_min;

	printf("char range = %i\n", char_range);
	printf("short range = %li\n", shrt_range);
	printf("int range = %lli\n", int_range);
	printf("long signed range = %lli\n", long_range);
	printf("max long unsigned value = %llu\n", ulong_range);
	printf("float range = %lf\n\n", float_range);
	printf("double range = %Lf\n\n", double_range);
	printf("long double range = %Lf\n", long_double_range);

	printf("\nPress any key to exit..\n");
	getchar();
	return 0;
}