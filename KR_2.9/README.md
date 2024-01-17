Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x. Explain why. Use this observation to write a faster version of bitcount. 

EXAMPLE of bitcount function that counts the number of 1-bits in its integer argument:
x = 01100110
int i = 0;
x &= (x - 1):
x &= (01100110 - 1) = 01100110 
					 &
					 01100101
					 =
					 01100100 != 0 -> i++
i++: x &= (01100100 - 1) = 01100100 
					 &
					 01100011
					 =
					 01100000 != 0 -> i++
i++: x &= (01100000 - 1) = 01100000 
					 &
					 01011111
					 =
					 01000000 != 0 -> i++
x &= (01000000 - 1) = 01000000 
					 &
					 00111111
					 =
					 00000000 = 0 -> end