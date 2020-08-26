/*******************************************************************************
ENGR 200.02                                                     DATE: 10/10/2017

PROGRAM: #5                              Author: Grant Haataja
********************************************************************************

PROGRAM DESCRIPTION:
This program will read rainfall amounts from 2013 - 2017 into 5 one-dimensional
arrays, calculate the total rainfall for each year, average rainfall for each 
year, and determine the minimum and maximum rainfall values for the year 2015. 
The results will be printed to the screen and an output file. 

DESCRIPTION OF VARIABLES:
NAME       | TYPE   | DESCRIPTION
--------------------------------------------------------------------------------
avg13      | double | computed average rainfall for 2013
avg14      | double | computed average rainfall for 2014
avg15      | double | computed average rainfall for 2015
avg16      | double | computed average rainfall for 2016
avg17      | double | computed average rainfall for 2017
yr13       | double | one-dimensional array of rainfall data for year 2013
yr14       | double | one-dimensional array of rainfall data for year 2014
yr15       | double | one-dimensional array of rainfall data for year 2015
yr16       | double | one-dimensional array of rainfall data for year 2016
yr17       | double | one-dimensional array of rainfall data for year 2017
tot13      | double | total rainfall for all months in 2013
tot13      | double | total rainfall for all months in 2013
tot14      | double | total rainfall for all months in 2014
tot15      | double | total rainfall for all months in 2015
tot16      | double | total rainfall for all months in 2016
tot17      | double | total rainfall for all months in 2017
min        | double | minimum rainfall for 2015
max        | double | maximum rainfall for 2015
i          | int    | for loop control variable
ndata      | int    | number of months in a year
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define inputfile "u:\\engr 200\\rain_fall.txt"
#define outputfile "u:\\engr 200\\rain_fall_report.txt"

/* Main function */
int main(void)
{
   /* Declare and initialize variables */
   double yr13[12], yr14[12], yr15[12], yr16[12], yr17[12], min, max,
          tot13=0.0, tot14=0.0, tot15=0.0, tot16=0.0, tot17=0.0, avg13, avg14,
          avg15, avg16, avg17;
   int i, ndata;
   FILE *rainfall, *report;

   /* Open input and output files */
   rainfall = fopen(inputfile,"r");
   report = fopen(outputfile,"w");

   /* Verify input file */
   if(rainfall == NULL)
   {
      printf("\n\nERROR OPENING INPUT FILE");
      printf("\n\nPROGRAM TERMINATED\n\n");
      return 0;
   }
   
   /* Read control number */
   fscanf(rainfall,"%i",&ndata);
      
   /* Read input data into array */
   for (i=0; i<=ndata-1; i++)
   {
   	fscanf(rainfall,"%lf %lf %lf %lf %lf",&yr13[i]
	               ,&yr14[i],&yr15[i],&yr16[i],&yr17[i]);
   }

   /* Find the minimum and maximum 2015 rainfall values */
   min = yr15[0];
   max = yr15[0];
   for(i=0; i<=ndata-1; i++)
   {
   	  tot13+=yr13[i];
   	  tot14+=yr14[i];
      tot15+=yr15[i];
      tot16+=yr16[i];
      tot17+=yr17[i];
      
   	  if(yr15[i]<min)
	  {
	  	min = yr15[i];
	  }
	  if(yr15[i]>max)
	  {
	  	max = yr15[i];
	  }
   }
      
   /* Compute the average rainfalls */    
   avg13=(double)tot13/ndata;
   avg14=(double)tot14/ndata;
   avg15=(double)tot15/ndata;
   avg16=(double)tot16/ndata;
   avg17=(double)tot17/ndata;   
   
   /* Print report to computer screen and output file */
   printf("******************************************************"
          "\n               METROPOLIS RAINFALL DATA"
          "\n\n            2013     2014     2015     2016     2017\n");
   fprintf(report,"******************************************************"
           "\n               METROPOLIS RAINFALL DATA"
           "\n\n            2013     2014     2015     2016     2017\n");
    
   for (i=0; i<=ndata-1; i++)
   {
   	printf("\nMonth %2i    %4.2lf     %4.2lf     %4.2lf     %4.2lf     %4.2lf"
	         ,i+1,yr13[i],yr14[i],yr15[i],yr16[i],yr17[i]);
	fprintf(report,"\nMonth %2i    %4.2lf     %4.2lf     %4.2lf     %4.2lf"    
	               "     %4.2lf",i+1,yr13[i],yr14[i],yr15[i],yr16[i],yr17[i]);
   }
   
   printf("\n\nAverages:   %4.2lf     %4.2lf     %4.2lf     %4.2lf     %4.2lf"
           ,avg13,avg14,avg15,avg16,avg17);
   printf("\n\nREPORT SUMMARY:");
   printf("\nMinimum rainfall for 2015 is %4.2lf inches.",min);
   printf("\nMaximum rainfall for 2015 is %4.2lf inches.",max);
   printf("\n******************************************************\n\n\n");
   
   fprintf(report,"\n\nAverages:   %4.2lf     %4.2lf     %4.2lf     %4.2lf"     
                  "     %4.2lf",avg13,avg14,avg15,avg16,avg17);
   fprintf(report,"\n\nREPORT SUMMARY:");
   fprintf(report,"\nMinimum rainfall for 2015 is %4.2lf inches.",min);
   fprintf(report,"\nMaximum rainfall for 2015 is %4.2lf inches.",max);
   fprintf(report,"\n******************************************************\n"
                  "\n\n");
	
   /* Close input and output files */
   fclose(rainfall);
   fclose(report);

   /* Exit program */
   return 0;
}
/******************************************************************************/
