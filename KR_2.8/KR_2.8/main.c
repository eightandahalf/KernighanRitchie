// Exercise 2-8. Write a function rightrot(x,n) that returns the value of 
// the chareger x rotated to the right by n positions. 

// what should we get as the result? - Circular Right Shift:
// In this micro shift operation each bit in the register is shifted 
// to the right one by one. After shifting, the MSB becomes empty, 
// so the value of the LSB is filled in there.
// 
// let x = 100, n = 4
// x in bin look like this x = 100 = 01100(100)
// we should shilf x three times to the right, and as the result
// we will get (100)01100
// The bits in parentheses indicate that they will be shifted. 
// There is a photo attached in the folder that also shows how 
// Circular Right Shift works

//The char rightrot(char x, char n) function is written for the char type, 
//and also demonstrated in the body of the function is the situation if a 
//variable overflow situation occurs during bit shifts. 
//Any type can be chosen, then only all variables that are related to the 
//function must be replaced with the corresponding type, in this case any 
//other type instead of char, and as the return type of the function, and 
//the parameters and local variables of the function.
//
//Another strange but probably fair point, which is that if a variable 
//is overflowed and the high bit of msb starts storing one, then until this 
//msb bit is programmatically changed to zero, all subsequent numbers that 
//appeared during the change of that overflowed one will be negative. The 
//example in the overflow procedure shows what I am talking about.
//
#include <stdio.h>

char rightrot(char x, char n);
void overflow();

char main()
{
	char x = 52, n = 6;

	printf("x before rightrot is equal to %d\n"
		"n is equal to %d\n", x, n);
	char res = rightrot(x, n);
	printf("x after rightrot is equal to %d\n", res);

	printf("\nchar overflow demonstration: \n");
	overflow();

	printf("\nPress any key to exit..\n");
	getchar();
	return 0;
}

void overflow() 
{
	char a = 0b10000000;
	printf("a first_exp = %d\n", a);
	//a first_exp = -128

	a = a >> 7; // 0b10000001
	printf("a sec_exp = %d\n", a);
	//a sec_exp = -1

	a = a & 0b10000000; // 0b1000000
	printf("a third_exp = %d\n", a);
	//a third_exp = -128

	a = a >> 4; // 0b10001000
	printf("a fourth_exp = %d\n", a);
	//a fourth_exp = -8

	a = a + 50; // overflow, from -8 to 52
	printf("a fifth_exp = %d\n", a);
	//a fifth_exp = 42

	// rollback, from 52 to 88. it means that the variable 
	// has gone partially the way of positive numbers, all 
	// the way of negative numbers, and rolled back to a positive one
	a = a - 210; 
	printf("a sixth_exp = %d\n", a);
	//a sixth_exp = 88

	a = 0b10000000 & 0b00000001; // 0b00000000
	printf("a seventh_exp = %d\n", a);
	//a seventh_exp = 0
}

char rightrot(char x, char n)
{
	// for example: x = 52 = 00(110100); n = 6;
	// res will be res = (110100)00 = 208(in calculator, but since signed char 
	// has range [-128; 127] then it will be equal to -48 - overflow
	// e.g. 127,-128,-127,...,-48, and 1 + 127 +(-48-(-128)) = 208
	char res = x;
	char maska_lsb = ~(~0 << 1); // 00000001
	char lsb = 0;
	char maska_msb = ~0 << 7; // 10000000
	char msb = 0;
	while (n > 0)
	{
		lsb = res & maska_lsb;
		res = res >> 1;

		msb = (res & maska_msb) >> 7;
		
		// here we will set a new bit msb which will be equal to lsb.
		// The replacement can be realized in two ways, the first one is simple, 
		// and the second one is more complicated
		//
		// !!!!!!!!!!!!!The unnecessary one realisation should be commented out!!!!!!!!!!!
		//
		// The first implementation is more correct, but the 
		// second one tries to take into account the overflow 
		// and somehow compensate for it by zeroing the msb bit 
		// if lsb is zero during the transfer 
		//
		// first realisation
		res = res | (lsb << 7);
		// second realisation
		if (msb == -1 && lsb == 0)
			res = res & ~(maska_msb);
		else if (msb == -1 && lsb == 1)
			res = res & (~0);
		else if (msb == 0)
			res = res | (lsb << 7);
		//

		printf("temp res: %d\n", res);
		n--;
	}
	return res;
}