/*******************************************************************************
DEMO: DEMONSTRATES MATH FUNCTIONS

PROGRAM DESCRIPTION
This program computes the volume of a sphere, and the sine, cosine, and tangent
values of an angle.  The results are printed to the computer screen.

DESCRIPTION OF VARIALBES
NAME    | TYPE     | DESCRIPTION
--------------------------------------------------------------------------------
volume  | double   | calculated volume of a sphere
radius  | double   | radius of a sphere
pi      | symbolic | mathematical constant
sine    | double   | computed sin of an angle
cosine  | double   | computed cos of an angle
tangent | double   | compute tan of an angle
angle   | double   | input angle in degrees
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define pi 3.14159

/* Main function */
int main(void)
{
   /* Declare identifiers */
   double angle, volume, radius, sine, cosine, tangent;

   /* Input radius from the keyboard */
   printf("********************************************");
   printf("\nEnter sphere radius in feet [< 10]: ");
   scanf("%lf",&radius);

   /* Compute volume of sphere */
   volume = 4.0/3.0*pi*pow(radius,3);

   /* Print volume of the sphere */
   printf("\n\nVolume = %7.2f cubic feet",volume);
   printf("\n********************************************");
   printf("\n\n********************************************");
   
   /* Enter angle */
   printf("\nEnter angle in degrees: ");
   scanf("%lf",&angle);
   
   /* Compute sine, cosine, and tangent */
   sine = sin(angle*pi/180.0);
   cosine = cos(angle*pi/180.0);
   tangent = tan(angle*pi/180.0);
   
   /* Print angle, sine, cosine, and tangent */
   printf("\nSine of %3.1f degrees    = %6.4f\nCosine of %3.1f degrees  = %6.4f"
          "\nTangent of %3.1f degrees = %6.4f",angle,sine,angle,cosine,
          angle,tangent);
   printf("\n********************************************\n\n\n");
   
   /* Exit the program */
   return 0;
}
/******************************************************************************/












