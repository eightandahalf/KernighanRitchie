Exercise 2-8. Write a function rightrot(x,n) that returns the value of 
the chareger x rotated to the right by n positions. 

what should we get as the result? - Circular Right Shift:
In this micro shift operation each bit in the register is shifted 
to the right one by one. After shifting, the MSB becomes empty, 
so the value of the LSB is filled in there.
 
let x = 100, n = 4
x in bin look like this x = 100 = 01100(100)
we should shilf x three times to the right, and as the result
we will get (100)01100
The bits in parentheses indicate that they will be shifted. 
There is a photo attached in the folder that also shows how 
Circular Right Shift works

The char rightrot(char x, char n) function is written for the char type, 
and also demonstrated in the body of the function is the situation if a 
variable overflow situation occurs during bit shifts. 
Any type can be chosen, then only all variables that are related to the 
function must be replaced with the corresponding type, in this case any 
other type instead of char, and as the return type of the function, and 
the parameters and local variables of the function.

Another strange but probably fair point, which is that if a variable 
is overflowed and the high bit of msb starts storing one, then until this 
msb bit is programmatically changed to zero, all subsequent numbers that 
appeared during the change of that overflowed one will be negative. The 
example in the overflow procedure shows what I am talking about.
