/*******************************************************************************
DEMO: THIS PROGRAM DEMONSTRATES THE "for" LOOP AND NESTED "if/else" STRUCTURE

         for(expression_1;expression_2;expression_3)
         {
            statements;
         }

PROGRAM DESCRIPTION:
This program calculates sine, cosine, and tangent values based on an angle in
degrees.  The results are printed to the computer screen.

DESCRIPTION OF VARIABLES:
NAME     | TYPE     | DESCRIPTION
--------------------------------------------------------------------------------
angle    | double   | angle in degress
sine     | double   | calculated sine value of angle
cosine   | double   | calculated cosine value of angle
tangent  | double   | calculated tangent value of angle
radians  | double   | conversion of degrees to radians
pi       | symbolic | mathematical constant
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define pi 3.14159

/* Main function */
int main(void)
{
   /* Declare variables */
   double sine, cosine, tangent, radians, angle=0.0;
   int i; 
   
   /* Print main headings and column headings */
   printf("*****************************************"
          "\n          TABLE OF TRIG VALUES"
          "\n\n Angle      Sine      Cosine     Tangent");

   /* Calculate and print output results */   
   for(i=1; i<=37; i++)
   {
      radians = angle*pi/180.0;
      sine = sin(radians);
      cosine = cos(radians);
      tangent = tan(radians);
      
      
      
      if(radians < pi/2.0 || radians > pi/2.0)
         printf("\n %5.1f    %7.4f    %7.4f     %7.4f",angle,sine,cosine,
		       tangent);
	  else
		 printf("\n%5.1f    %7.4f    %7.4f     UNDEFINED",angle,sine,cosine);
		 
		 
		 
		 
	  angle+=5.0;	 
	}
   printf("\n*****************************************\n\n\n");
  
   /* Exit program */
   return 0;
}
/******************************************************************************/

