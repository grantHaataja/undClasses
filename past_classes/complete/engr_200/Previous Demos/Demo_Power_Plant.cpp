/*******************************************************************************
DEMO: DEMONSTRATION OF ONE-DIMENSIONAL ARRAYS

PROGRAM DESCRIPTION:
This program reads identification numbers and power output for 10 power plants
into two one-dimensional arrays.  Average, minimun, and maximum power is
computed.  The number of days power output is greater than average is also
determined.  The program prints a composite report summarizing power plant
output data to the computer screen and an output file.

DESCRIPTION OF VARIABLES:
NAME       | TYPE   | DESCRIPTION
--------------------------------------------------------------------------------
average    | double | computed average of all power output
power_data | int    | one-dimensional array of power data
plant_id   | int    | one-dimensional array of plant ID numbers
minimum    | int    | minimum power output
maximum    | int    | maximum power output
total      | int    | summation of all power output
i          | int    | for loop control variable
ndays      | int    | number of days power is greater than average
ndata      | int    | number of power plants
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define inputfile "u:\\engr 200\\power_plant.txt"
#define outputfile "u:\\engr 200\\plant_report.txt"

/* Main function */
int main(void)
{
   /* Declare and initialize variables */
   double average;
   int i, ndata, ndays=0, total=0, minimum, maximum, plant_id[10], 
        power_data[10];
   FILE *power, *report;

   /* Open input and output files */
   power = fopen(inputfile,"r");
   report = fopen(outputfile,"w");

   /* Verify input file */
   if(power == NULL)
   {
      printf("\n\nERROR OPENING INPUT FILE");
      printf("\n\nPROGRAM TERMINATED\n\n");
      return 0;
   }
   
   /* Read control number */
   fscanf(power,"%i",&ndata);
      
   /* Read input data into array */
   for (i=0; i<=ndata-1; i++)
   {
   	fscanf(power,"%i %i",&plant_id[i],&power_data[i]);
   }

   /* Compute total power and find the minimum and maximum power values */
   minimum = power_data[0];
   maximum = power_data[0];
   for(i=0; i<=ndata-1; i++)
   {
   	  total = total+power_data[i];
   	  if(power_data[i]<minimum)
	  {
	  	minimum = power_data[i];
	  }
	  if(power_data[i]>maximum)
	  {
	  	maximum = power_data[i];
	  }
   }
      
   /* Compute the average power output */    
   average = (double)total/ndata;
    
   /* Determine the number of days power output is greater than average */
   for(i=0; i<=ndata-1; i++)
   {
   	  if(power_data[i] > average)
   	  {
   	  	 ndays++;
	  }
   }
   
   /* Print report to computer screen and output file */
   printf("**************************************"
          "\n          POWER PLANT OUTPUT"
          "\n\n        Plant ID      Megawatts");
   fprintf(report,"**************************************"
           "\n          POWER PLANT OUTPUT"
           "\n\n        Plant ID      Megawatts");
    
   for (i=0; i<=ndata-1; i++)
   {
   	printf("\n          %3i            %3i",plant_id[i],power_data[i]);
	fprintf(report,"\n          %3i            %3i",plant_id[i],
		power_data[i]);
   }
   
   printf("\n\n\nCOMPOSITE REPORT");
   printf("\nAverage power output = %5.1f megawatts",average);
   printf("\nMinimum power output =   %3i megawatts",minimum);
   printf("\nMaximum power output =   %3i megawatts",maximum);
   printf("\nGreater than average =    %2i days",ndays);
   printf("\n**************************************\n\n\n");
   
   fprintf(report,"\n\n\nCOMPOSITE REPORT");
   fprintf(report,"\nAverage power output = %5.1f megawatts",average);
   fprintf(report,"\nMinimum power output =   %3i megawatts",minimum);
   fprintf(report,"\nMaximum power output =   %3i megawatts",maximum);
   fprintf(report,"\nGreater than average =    %2i days",ndays);
   fprintf(report,"\n**************************************\n\n\n");
	
   /* Close input and output files */
   fclose(power);
   fclose(report);

   /* Exit program */
   return 0;
}
/******************************************************************************/
