/*******************************************************************************        
DEMO: BASIC PROGRAM STRUCTURE

PROGRAM DESCRIPTION:
This program requires the user to specify the length of his or her leg in feet.
The program computes the time required for a walking stride and prints the
results to the computer screen.
  
DESCRIPTION OF VARIABLES:
NAME    | TYPE   | DESCRIPTION                                
--------------------------------------------------------------------------------
leg_len | double | length of a leg in feet                                           
time    | double | time required for a stride                                           
pi      | double | mathematical constant                                      
gravity | double | gravitational constant (ft/s/s)
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>

/* Main function */
int main(void)
{
   /* Declare and initialize variables */
   double leg_len=?????, gravity=32.2, pi=3.141593, time;
   
   /* Calculate time */
   time = pi*sqrt((2.0*leg_len)/(3.0*gravity));

   /* Print results to computer screen */
   printf("\n\nThe stride time is %4.2f seconds for a leg length of %3.1f "
          "feet.\n\n\n",time,leg_len);

   /* Exit program */
   return 0;
}
/******************************************************************************/
