/* K&R 1.6 verify that the expression c = (getchar() != EOF) is 0 or 1 */

#include <stdio.h>

void main()
{
	int c;
	while (c = (getchar() != EOF))
	{
		printf("%1d", c);
	}
	printf("False expression of c = (getchar() != EOF) is equal to %2d", c);
}