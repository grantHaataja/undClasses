/*******************************************************************************
DEMO: SIMPLE CHARACTER INPUT AND OUTPUT USING getchar AND putchar FUNCTIONS

PROGRAM DESCRIPTION:
This program reads a character from the keyboard, computes a new character, and
prints the results to the computer screen.                                      

DESCRIPTION OF VARIABLES:
NAME          | TYPE | DESCRIPTION 
--------------------------------------------------------------------------------
any_character | char | a character enter from the keyboard                 
new_character | int  | calculation of new character
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#include <ctype.h>

/* Main function */
int main (void)
{
   /* Declare variables */
   char any_character;
   int new_character;
  
   /* Get character from the keyboard */
   printf("***************************************************");
   printf("\nEnter a character from the keyboard: ");
   any_character = getchar();  
  
   /* Print character */
   printf("\n\nThe character entered is ");
   putchar(any_character);
   printf("\nThe ASCII integer value of the character is %-3i",
          any_character);
   
   /* Compute new character */
   new_character = any_character + 7;

   /* Print new character */
   printf("\n\nThe ASCII integer value of the new character is %-3i",
          new_character);
   printf("\nThe new character is ");
   putchar(new_character);
   printf("\n***************************************************\n\n\n");
        
   /* Exit the program */
   return 0;
}
/******************************************************************************/
