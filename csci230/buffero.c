//Grant Haataja
//Buffer Overflow Quiz

#include<stdio.h>
#include<stdlib.h>

/*********************************************/
/* Test cases:                               */
/* 12345 & abcde                             */
/* 123456789012345678901234567890 & abcde    */
/* 12345 & abcdefghijklmnopqrst              */

void buffero(void) {
	char string[5], strung[15];
	printf("Enter text for first string: ");
	scanf("%s", string);
	printf("Enter text for second string: ");
	scanf("%s", strung);
	printf("String: %s\n", string);
	printf("Strung: %s\n", strung);
}

int main(void) {
	buffero();
	return 0;
}


//Questions
//1. How many characters does it take to overflow the char[5] array?
//2. How many characters does it take to overflow the char[15] array?
//3. Which array is at the bottom of the stack?

//Answers
//1. It takes 16 characters to overflow the char[5] array
//2. It takes 25 characters to overflow the char[15] array
//3. The second string is at the bottom of the stack
