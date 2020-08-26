/*******************************************************************************
DEMO: THIS PROGRAM DEMONSTRATES READING FROM AN INPUT DATA FILE USING A
      "control" NUMBER AND A "for" LOOP.

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
i       | integer  | loop control variable
ndata   | integer  | number of data record lines in the input file
pi      | symbolic | mathematical constant
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
   int i, ndata;
   FILE *xy;
  
   /* Open input file */
   xy = fopen(inputfile,"r");
     
   /* Verify input file */
   if(xy == NULL)
   {
      printf("\n\nERROR OPENING INPUT FILE"
             "\n\nPROGRAM TERMINATED\n\n");
      return 0;
   }
   
   /* Read control number from input file */
   fscanf(xy,"%i",&ndata);
      
   /* Print main headings to computer screen */
   printf("******************************************");
   printf("\n  CONVERSION TABLE -- CARTESIAN TO POLAR"
          "\n\n  Cartesian                  Polar"
          "\n  X       Y          Radius     Angle(deg)");
      
   /* Read x-y coordinates, compute polar coordinates, and print results */
   for(i=1; i<=ndata; i++)
   {
      fscanf(xy,"%lf,%lf",&xcoord,&ycoord);
      radius = sqrt(pow(xcoord,2) + pow(ycoord,2));
      radians = atan2(ycoord,xcoord);
      degrees = radians *180.0/pi;
      printf("\n%5.1f   %5.1f      %8.3f      %8.3f",
             xcoord,ycoord,radius,degrees);
   }
   printf("\n******************************************\n\n\n");
   
   /* Close input file */
   fclose(xy);
   
   /* Exit program */
   return 0;
}
/******************************************************************************/

