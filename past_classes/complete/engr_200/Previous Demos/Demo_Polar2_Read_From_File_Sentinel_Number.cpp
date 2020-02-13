/*******************************************************************************
DEMO: THIS PROGRAM DEMONSTRATES READING FROM AN INPUT FILE USING A "while" LOOP
      AND A "sentinel" NUMBER.

PROGRAM DESCRIPTION:
This program will convert cartesian coordinates to polar coordinates.  It will
read the cartesian data from an input data file and it will print the cartesian
and polar data to the computer screen.
   
DESCRIPTION OF VARIABLES:
NAME    | TYPE     | DESCRIPTION
--------------------------------------------------------------------------------
xcoord  | double   | cartesian x coordinate
ycoord  | double   | cartesian y coordinate
radius  | double   | calculated polar coordinate
radians | double   | calculated arc value
degrees | double   | calculated polar coordinate
pi      | symbolic | math constant
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define pi 3.14159
#define inputfile "u:\\engr 200\\xy_coordinates.txt"

/* Main function */
int main(void)
{
   /* Declare variables */
   double xcoord, ycoord, radius, radians, degrees;
   FILE *xy;
   
   /* Open input file */
   xy = fopen(inputfile,"r");
   
   /* Verify input file */
   if(xy == NULL)
   {
      printf("\n\n\nERROR OPENING INPUT FILE.");
      printf("\n\nPROGRAM TERMINATED.\n\n\n");
      return 0;
   }
   
   /* Print main headings to computer screen */
   printf("******************************************");
   printf("\n  CONVERSION TABLE -- CARTESIAN TO POLAR"
          "\n\n  Cartesian                  Polar"
          "\n  X       Y          Radius     Angle(deg)");
   
   /* Read first x-y coordinates from input file */
   fscanf(xy,"%lf,%lf",&xcoord,&ycoord);
               
   /* Compute polar coordinates, print results, and read more x-y data */
   while(xcoord!=-999.0 && ycoord!=-999.0)
   {
      radius = sqrt(pow(xcoord,2) + pow(ycoord,2));
      radians = atan2(ycoord,xcoord);
      degrees = radians *180.0/pi;
      printf("\n%5.1f   %5.1f       %8.3f     %8.3f",
             xcoord,ycoord,radius,degrees);
      fscanf(xy,"%lf,%lf",&xcoord,&ycoord);
   }
   printf("\n******************************************\n\n\n");

   /* Close input file */
   fclose(xy);
        
   /* Exit program */
   return 0;
}
/******************************************************************************/
