#include <assert.h>
#include <stdio.h>

/// K&R 1.11 How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?
/// 
/// 
/// Inputs that are most likely to uncover bugs if there are any:

int main(void)
{
	FILE* f;
	unsigned long i;
	const char* first_expression = " \f\t\v"; // Length of array is 4, that we use in test 1.
	const char* second_expression = "abcdefghijklmnopqrstuvwxyz"; // Length of array is 26, that we use in test 1.
	const char* third_expression = "a b c d e f g h i j k l m "
								   "n o p q r s t u v w x y z "
								   "a b c d e f g h i j k l m "
								   "n o p q r s t u v w x y z "
								   "a b c d e f g h i j k l m "
								   "n\n"; // number of symbols is equal to 66

	/*0. input file contains zero words*/
	f = fopen("test0", "w");
	assert(f != NULL);
	fclose(f);

	/*1. input file contains 1 enormous word without any newlines*/
	f = fopen("test1", "w");
	assert(f != NULL);
	for (i = 0; i < ((66000ul / 26) + 1); i++)
		fputs(second_expression, f);
	fclose(f);

	/*2. input file contains only blanks*/
	f = fopen("test2", "w");
	assert(f != NULL);
	for (i = 0; i < ((66000ul / 4) + 1); i++)
		fputs(first_expression, f);
	fclose(f);

	/*3. input file contains 66000 newlines*/
	f = fopen("test3", "w");
	assert(f != NULL);
	for (i = 0; i < 66000; i++)
		fputs("\n", f);
	fclose(f);

	/*4. input file contains word + {huge sequence of whitespace of different kinds} + word */
	f = fopen("test4", "w");
	assert(f != NULL);
	fputs("word", f);
	for (i = 0; i < ((66000ul / 4) + 1); i++)
		fputs(first_expression, f);
	fputs("word", f);
	fclose(f);

	/*5.  input file contains 66000 single letter words, 66 to the line */
	f = fopen("test5", "w");
	assert(f != NULL);
	for (i = 0; i < 1000; i++)
		fputs(third_expression, f);
	fclose(f);

	/*6. input file contains 66000 word without any newlines*/
	f = fopen("test6", "w");
	assert(f != NULL);
	for (i = 0; i < 66000; i++)
	{
		fputs(second_expression, f);
		fputs(' ', f);
	}
	fclose(f);

	return 0;
}