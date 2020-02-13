/*******************************************************************************
DEMO: THIS PROGRAM DEMONSTRATES A TWO-DIMENSIONAL ARRAY

PROGRAM DESCRIPTION:
This program computes the average horsepower that a power plant uses for
multiple flow rates and cooling loops.  It determines the minimum and maximum
horsepower values, and determines the associated cooling loop and flow rate
for the minimum and maximum values.  A report is printed to the computer screen.

DESCRIPTION OF VARIABLES
NAME      | TYPE   | DESCRIPTION
--------------------------------------------------------------------------------
hpower    | double | two-dimensional array for horsepower values
flow_tot  | double | one-dimensional array for flow rate totals in gps
flow_aver | double | one-dimensional array for computed average flow rates
cloop     | char   | two-dimensional character array for cooling loop names
minhp     | double | minimum horsepower value
maxhp     | double | maximum horsepower value
nrows     | int    | number of rows in the array
ncols     | int    | number of columns in the array
i         | int    | outer for loop control variable
j         | int    | inner for loop control variable
minloop   | int    | cooling loop containing minimum horsepower
minflow   | int    | flow rate containing minimum horsepower
maxloop   | int    | cooling loop containing maximum horsepower
maxflow   | int    | flow rate containing maximum horsepower
avehp     | double | computed average for all horsepower values
totalhp   | double | total for all horsepower values
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define inputfile "u:\\engr 200\\horsepower.txt"

/* Main function */
int main(void)
{
   /* Declare variables */
   double minhp, maxhp, avehp, totalhp=0.0, hpower[5][6], flow_tot[6]={0.0},
          flow_aver[6];
   int i, j, nrows, ncols, minloop, minflow, maxloop, maxflow;
   char cloop[5][10];
   FILE *power;

   /* Open input file */
   power = fopen(inputfile,"r");
   
   /* Verify input file and read input data */
   if(power == NULL)
   {
      printf("\n\n\nERROR OPENING INPUT FILE.");
      printf("\n\nPROGRAM TERMINATED.\n\n\n");
      return 0;
   }
   
   /* Read control numbers */
   fscanf(power,"%i %i",&nrows,&ncols);
      
   /* Read cooling loop names and horse power table into arrays */
   for(i=0; i<=nrows-1; i++)
   {
   	  for(j=0; j<=9; j++)
      {
      	fscanf(power,"%c",&cloop[i][j]);
	  }
      for(j=0; j<=ncols-1; j++)
      {
      	fscanf(power,"%lf",&hpower[i][j]);
	  }
   }
   
   /* Compute total horsepower, determine minimum and maximum horsepower */
   minhp = hpower[0][0];
   maxhp = hpower[0][0];
   for(i=0; i<=nrows-1; i++)
   {
   	  for(j=0; j<=ncols-1; j++)
   	  {
   	     totalhp = totalhp+hpower[i][j];
   	     if(hpower[i][j] < minhp)
   	     {
   	    	minhp = hpower[i][j];
   	    	minloop=i+1;
   	    	minflow=j+1;
	     }
	     if(hpower[i][j] > maxhp)
   	     {
   	    	maxhp = hpower[i][j];
   	    	maxloop=i+1;
   	    	maxflow=j+1;
	     }
      }
   }
   
   /* Compute average horsepower */
   avehp = totalhp/(nrows*ncols);
   
   /* Compute total horsepower per flow rate */
   for(i=0; i<=nrows-1; i++)

   {
   	  for(j=0; j<=ncols-1; j++)
      {
      	flow_tot[j]=flow_tot[j]+hpower[i][j];
	  }
   }   
   /* Compute average horsepower per flow rate */
   for(j=0; j<=ncols-1; j++)
   {
   	flow_aver[j]=flow_tot[j]/nrows;
   }
                  
   /* Print power plant name and column headings */
   printf("***************************************************");
   printf("\n          MISSOURI RIVER POWER COMPANY"
          "\n\n                        HORSE POWER TABLE"
          "\n                  (flow rates in gallons/second)\n              1"
		  "      2      3      4      5      6\n");
	
   /* Print cooling loop names and horsepower table */
   for(i=0; i<=nrows-1; i++)
   {
      for (j=0; j<=9; j++)
      {
      	printf("%c",cloop[i][j]);
	  }
      for(j=0; j<=ncols-1; j++)
      {
      	printf("  %5.1f",hpower[i][j]);
	  }
   }
 	
   /* Print average horsepower per flow rate */
   printf("\n\n                      Hosepower Averages\n         ");
   for(j=0; j<=ncols-1; j++)
   {
   	  printf("  %5.1f",flow_aver[j]);
   }
  
   /* Print average, minimum and maximum horsepower values */
   printf("\n\nReport Summary:");
   printf("\nAverage horsepower is %5.1f",avehp);
   printf("\nMinimum horsepower is %5.1f in loop %1i flow rate %1i",minhp,
          minloop,minflow);
   printf("\nMaximum horsepower is %5.1f in loop %1i flow rate %1i",maxhp,
          maxloop,maxflow);
   printf("\n**************************************************\n\n\n");
  
   /* Close input file */
   fclose(power);
  
   /* Exit program */
   return 0;
}
/******************************************************************************/

