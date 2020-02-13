/*******************************************************************************
ENGR 200.02                                                     DATE: 09/26/2017

PROGRAM: #3                               Author: Grant Haataja
********************************************************************************

PROGRAM DESCRIPTION:
This  program  will allow  the user  to obtain  useful seismic  readings for oil 
exploration  by  computing  specific  ratios between depth of hole and amount of 
dynamite. It will read in values from an input file, calculate the hole to depth
ration, ideal number of sticks,  ideal powder charge, actual powder charge,  and 
the actual number of sticks. The results will be printed to the  computer screen
and to an output data file.

DESCRIPTION OF VARIABLES:
NAME    | TYPE     | DESCRIPTION
--------------------------------------------------------------------------------
xcoord  | double   | cartesian x coordinate
ycoord  | double   | cartesian y coordinate
radius  | double   | calculated polar coordinate
radians | double   | calculated arc value
degrees | double   | calculated polar coordinate
i       | integer  | loop control variable
ndata   | integer  | number of record lines in the input file
pi      | symbolic | math constant
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define pi 3.14159
#define inputfile "u:\\engr 200\\xy_coordinates.txt"
#define outputfile "u:\\engr 200\\polar_coordinates.txt"

/* Main function */
int main(void)
{
   /* Declare variables */
   double xcoord, ycoord, radius, radians, degrees;
   int i, ndata;
   FILE *xy, *polar;

   /* Open input & output files */
   xy = fopen(inputfile,"r");
   polar= fopen(outputfile,"w");
   
   /* Verify input file */
   if(xy == NULL)
   {
      printf("\n\n\nERROR OPENING INPUT FILE.");
      printf("\n\nPROGRAM TERMINATED.\n\n\n");
      return 0;
   }
   
   /* Read control number */
   fscanf(xy,"%i",&ndata);
   
   /* Print main headings and column headings */
   printf("******************************************");
   printf("\n  CONVERSION TABLE -- CARTESIAN TO POLAR"
          "\n\n  Cartesian                  Polar"
          "\n  X       Y          Radius     Angle(deg)");
   fprintf(polar,"******************************************");
   fprintf(polar,"\n  CONVERSION TABLE -- CARTESIAN TO POLAR"
          "\n\n  Cartesian                  Polar"
          "\n  X       Y          Radius     Angle(deg)");
                
   /* Read xy-coordinates, compute polar coordinates, and print results */
   for(i=1; i<=ndata; i++)
   {
      fscanf(xy,"%lf,%lf",&xcoord,&ycoord);
      radius = sqrt(pow(xcoord,2) + pow(ycoord,2));
      radians = atan2(ycoord,xcoord);
      degrees = radians *180.0/pi;
      printf("\n%5.1f   %5.1f      %8.3f     %8.3f",
             xcoord,ycoord,radius,degrees);
      fprintf(polar,"\n%5.1f   %5.1f      %8.3f     %8.3f",
             xcoord,ycoord,radius,degrees);
   } 
   printf("\n******************************************\n\n\n");
   fprintf(polar,"\n******************************************\n\n\n");
   
   /* Close input & output files */
   fclose(xy);
   fclose(polar);
            
   /* Exit program */
   return 0;
}
/******************************************************************************/




