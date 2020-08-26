/*******************************************************************************
ENGR 200.02                                                     DATE: 10/24/2017

PROGRAM: #6                              Author: Grant Haataja
********************************************************************************

PROGRAM DESCRIPTION:
This  program  reads  in  data  concerning  lake  powell  from an input file and 
computes the average water height for an eight-year period. It will also compute
the  average water  height for  each year  and for  each  month, as  well as the 
minimum and maximum water heights for the eight-year period, and how many months
the water level exceeded  the eight-year average. The results are printed to the 
computer screen and an ouput file.

DESCRIPTION OF VARIABLES
NAME      | TYPE   | DESCRIPTION
--------------------------------------------------------------------------------
height    | double | two-dimensional array for heights in feet above sea level
month     | char   | two-dimensional character array for month names
year_avg  | double | one-dimensional array for yearly average water height
month_avg | double | one-dimensional array for monthly average water height
year_tot  | double | one-dimensional array for yearly avg water height values
month_tot | double | one-dimensional array for monthly avg water height values
minwh     | double | minimum water height above sea level value
maxwh     | double | maximum water height above sea level value
nrows     | int    | number of rows in the array
ncols     | int    | number of columns in the array
i         | int    | outer for loop control variable
j         | int    | inner for loop control variable
num_month | int    | number of months that exceeded avg height above sea level
tot_wh    | double | total water height for 8 year period
avg_wh    | double | computed average for all water height values
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define inputfile "u:\\engr 200\\lake_powell.txt"
#define outputfile "u:\\engr 200\\lake_powell_report.txt"

/* Main function */
int main(void)
{
   /* Declare variables */
   double height[12][8], year_avg[8], month_avg[12], month_tot[12], year_tot[8],
          avg_wh, minwh, maxwh, tot_wh=0.0;
   int i, j, nrows, ncols, num_month=0;
   char month[12][10];
   FILE *powell, *report;

   /* Open input and output files */
   powell = fopen(inputfile,"r");
   report = fopen(outputfile,"w");
      
   /* Verify input file and read input data */
   if(powell == NULL)
   {
      printf("\n\n\nERROR OPENING INPUT FILE.");
      printf("\n\nPROGRAM TERMINATED.\n\n\n");
      return 0;
   }
   
   /* Read control numbers */
   fscanf(powell,"%i %i",&nrows,&ncols);
      
   /* Read month names and water height data into arrays */
   for(i=0; i<=nrows-1; i++)
   {
   	  for(j=0; j<=9; j++)
      {
      	fscanf(powell,"%c",&month[i][j]);
	  }
      for(j=0; j<=ncols-1; j++)
      {
      	fscanf(powell,"%lf",&height[i][j]);
	  }
   }
   
   /* Compute total water height, determine minimum and maximum water height */
   minwh = height[0][0];
   maxwh = height[0][0];
   for(i=0; i<=nrows-1; i++)
   {
   	  for(j=0; j<=ncols-1; j++)
   	  {
   	     tot_wh = tot_wh+height[i][j];
   	     if(height[i][j] < minwh)
   	     {
   	    	minwh = height[i][j];
	     }
	     if(height[i][j] > maxwh)
   	     {
   	    	maxwh = height[i][j];
	     }
      }
   }
   
   /* Compute average water height for 8 years */
   avg_wh = tot_wh/(nrows*ncols);
   
   /* Compute total water height per year */
   for(i=0; i<=nrows-1; i++)
   {
   	  for(j=0; j<=ncols-1; j++)
      {
      	year_tot[j]=year_tot[j]+height[i][j];
	  }
   }   
   /* Compute average water height per year */
   for(j=0; j<=ncols-1; j++)
   {
   	year_avg[j]=year_tot[j]/nrows;
   }
   
   /* Compute total water height per month */
   for(j=0; j<=ncols-1; j++)
   {
   	  for(i=0; i<=nrows-1; i++)
   	  {
   	  	month_tot[i]=month_tot[i]+height[i][j];
	  }
   }
   
   /* Compute average water height per month */
   for(i=0; i<=nrows-1; i++)
   {
   	month_avg[i]=month_tot[i]/ncols;
   }
   
   /* Find number of months that exceed average height above sea level */
   for(j=0; j<=ncols-1; j++)
   {
   	  for(i=0; i<=nrows-1; i++)
   	  {
   	  	if(height[i][j]>avg_wh)
   	  	{
   	  		num_month=num_month+1;
			 }
		 }
   }
                  
   /* Print month names and column headings */
   printf("********************************************************************"
          "********************************");
   printf("\n                                   LAKE POWELL RESERVOIR ANALYSIS"
          "\n                                       (feet above sea level)"
          "\n\n\n                                                Year"
          "\n             2000      2001      2002      2003      2004      "
		  "2005      2006      2007     Monthly"
          "\nMonth                                                             "
		  "                          Average");
		  
   fprintf(report,"************************************************************"
          "****************************************");
   fprintf(report,"\n                                   LAKE POWELL RESERVOIR "
          "ANALYSIS\n                                       (feet above sea lev"
		  "el)\n\n\n                                                Year\n     "
		  "        2000      2001      2002      2003      2004      2005      "
		  "2006      2007     Monthly\nMonth                             "
		  "                                                          Average");
	
   /* Print month names and water height table */
   for(i=0; i<=nrows-1; i++)
   {
      for (j=0; j<=9; j++)
      {
      	printf("%c",month[i][j]);
      	fprintf(report,"%c",month[i][j]);
	  }
      for(j=0; j<=ncols-1; j++)
      {
      	printf("   %7.2f",height[i][j]);
        fprintf(report,"   %7.2f",height[i][j]);	
	  }
	  printf("   %7.2f",month_avg[i]);
	  fprintf(report,"   %7.2f",month_avg[i]);
   }
 	
   /* Print yearly average water height */
   printf("\n\n                                            Yearly Average\n    "
          "     ");
   fprintf(report,"\n\n                                            Yearly Avera"
                  "ge\n         ");
   for(j=0; j<=ncols-1; j++)
   {
   	  printf("   %7.2f",year_avg[j]);
   	  fprintf(report,"   %7.2f",year_avg[j]);
   }
  
   /* Print average, minimum, and maximum water height values, and number of 
      months that exceeded average height above sea level */
   printf("\n\nReservoir Statistics:");
   printf("\nAverage water height above sea level is %7.2f feet.",avg_wh);
   printf("\nMinimum water height above sea level is %7.2f feet.",minwh);
   printf("\nMaximum water height above sea level is %7.2f feet.",maxwh);
   printf("\nNumber of months that exceeded the average height above sea level "
          "is %2i.",num_month);
   printf("\n******************************************************************"
          "**********************************\n\n\n");
   
   fprintf(report,"\n\nReservoir Statistics:");
   fprintf(report,"\nAverage water height above sea level is %7.2f feet."
                 ,avg_wh);
   fprintf(report,"\nMinimum water height above sea level is %7.2f feet."
                 ,minwh);
   fprintf(report,"\nMaximum water height above sea level is %7.2f feet."
                 ,maxwh);
   fprintf(report,"\nNumber of months that exceeded the average height above se"
                  "a level is %2i.",num_month);
   fprintf(report,"\n**********************************************************"
                  "******************************************\n\n\n");
  
   /* Close input and output files */
   fclose(powell);
   fclose(report);
  
   /* Exit program */
   return 0;
}
/******************************************************************************/

