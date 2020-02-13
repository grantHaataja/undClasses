/*******************************************************************************
DEMO: THIS PROGRAM DEMONSTRATES A user-defined FUNCTION

PROGRAM DESCRIPTION:
This program will read pressure, volume, and temperature from an input file,
and pass these values to a user-defined function. The user-defined function
will compute the mass of a balloon and pass the computed value back to the
main function.  The main function will compute the average of all the balloon
masses.  The program will check for missing input data and count the number of
values missing.  The results are printed to the computer screen and to an
output file.
         
DESCRIPTION OF VARIABLES:
NAME              | TYPE    | DESCRIPTION
--------------------------------------------------------------------------------
computed_mass     | double  | computed mass of the balloon
balloon_mass_aver | double  | computed average balloon mass
total_mass        | double  | computed total mass of balloons with valid data
press             | double  | pressure inside the balloon in pounds/ft^3
temp              | double  | temperature inside the balloon in degrees
vol               | double  | volume of the balloon in ft^3
i                 | integer | for loop control variable
ndata             | integer | number of record lines in input file
bnum              | integer | balloon number
missing_data      | integer | missing input data in input file
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define inputfile "u:\\engr 200\\balloon.txt"
#define outputfile "u:\\engr 200\\balloon_table.txt"

/* Main function */
int main(void)
{
   /* Declare variables */
   double mass(double, double, double);
   double computed_mass, balloon_mass_aver, total_mass=0.0, press, vol, temp;
   int i, ndata, bnum, missing_data=0;
   FILE *balloon, *table;

   /* Open input and output files */
   balloon = fopen(inputfile, "r");
   table = fopen(outputfile, "w");
   
   /* Verify input file and read input data */
   if(balloon == NULL)
   {
      printf("\n\n\nERROR OPENING INPUT FILE.");
      printf("\n\nPROGRAM TERMINATED.\n\n\n");
      return 0;
   }
   
   /* Print headings */
   printf("************************************************");
   printf("\n             TABLE OF BALLOON MASSES"
          "\n\nBalloon   Pressure   Volume   Temperature   Mass");
   fprintf(table,"************************************************");
   fprintf(table,"\n             TABLE OF BALLOON MASSES"
           "\n\nBalloon   Pressure   Volume   Temperature   Mass");
               
   /* Read control number */
   fscanf(balloon,"%i",&ndata);
          
   /* Read values, compute masses, and print table */
   for(i=1; i<=ndata; i++)
   {
      fscanf(balloon,"%i,%lf,%lf,%lf",&bnum,&press,&vol,&temp);
      if(press == 0.0 || vol == 0.0 || temp == 0.0)
      {
      	 missing_data++;
      	 printf("\n  %3i  Missing data. No computations performed.",bnum);
         fprintf(table,"\n  %3i  Missing data. No computations performed.",
		         bnum);
	  }
	  else
	  {
         computed_mass = mass(press,vol,temp);
         total_mass = total_mass + computed_mass;
         printf("\n  %3i      %5.1f     %5.1f       %5.1f     "
                "%5.1f",bnum,press,vol,temp,computed_mass);
         fprintf(table,"\n  %3i      %5.1f     %5.1f       %5.1f     "
                 "%5.1f",bnum,press,vol,temp,computed_mass);
      }
   }

   /* Compute average balloon mass */
   balloon_mass_aver = total_mass/(ndata-missing_data);

   /* Print average balloon mass and number of balloons missing data values */
   printf("\n\nThe average mass for %1i balloons is %5.1f",
          ndata-missing_data,balloon_mass_aver);
   fprintf(table,"\n\nThe average mass for %1i balloons is %5.1f",
           ndata-missing_data,balloon_mass_aver);
   printf("\n************************************************\n\n\n");
   fprintf(table,"\n************************************************\n\n\n");
  
   /* Close input and output files */
   fclose(balloon);
   fclose(table);
   
   /* Exit the program */
   return 0;
}
/*******************************************************************************
This function will calculate the MASS of a balloon after receiving pressure, 
volume, and temperature.
*******************************************************************************/
double mass(double press, double vol, double temp)
{
   /* Declare variables */
   double balloon_mass;
   
   /* Compute balloon mass */
   balloon_mass = (press*vol)/(0.42*(temp+460.0));
   
   /* Return balloon mass */
   return balloon_mass;
}
/******************************************************************************/









