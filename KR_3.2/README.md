Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write
a function for the other direction as well, converting escape sequences into the real characters. 

the newline has a decimal value of 10
the tab has a decimal value of 9

init string: 
"Hello wor011ld109My name is 1 0HLEB!!1099BAM9BAM"
result:
"Hello wor011ld
	My name is 1 0HLEB!!
		BAM		BAM"