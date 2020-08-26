/*******************************************************************************
DEMO: THIS PROGRAM DEMONSTRATES PROGRAMMING USING AN ARRAY OF defined-data-
      structures.

PROGRAM DESCRIPTION:
This program will read hurricane data from an input file, average the hurricane
categories, and sort the hurricanes by year.  The program will determine the
number of hurricanes that occurred in the Atlantic and the number that occurred
in the Gulf.  The hurricane data, the average category, and the numbers of
hurricanes by ocean are printed to the computer screen.

DESCRIPTION OF VARIABLES:
NAME      | TYPE   | DESCRIPTION
--------------------------------------------------------------------------------
hname     | char   | array containing a hurricane name
ocean     | char   | originating ocean
year      | int    | year the hurricane occurred
category  | int    | hurricane category
ndata     | int    | number of hurricanes in the input file
i         | int    | outer for loop control variable
j         | int    | inner for loop control variable
avercat   | int    | average of all hurricane categories
totalcat  | int    | total of all hurricane categories
atlantic  | int    | number of Atlantic hurricanes
gulf      | int    | number of Gulf hurricanes
hurri     | struct | array structure for hurricane data
temporary | struct | temporary structure for sorting hurricane data
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define inputfile "u:\\engr 200\\hurricanes.txt"

/* Define the structure to represent a hurricane */
struct hurricane
{
	char hname[9], ocean;
	int year, category;
};

/* Main function */
int main(void)
{
   /* Declare variables */
   struct hurricane hurri[7], temporary;
   int ndata, i, j, totalcat=0, gulf=0, atlantic=0, avercat;
   FILE *storms;

   /* Open input file */
   storms = fopen(inputfile,"r");
   
   /* Verify input file */
   if(storms == NULL)
   {
      printf("\n\nERROR OPENING INPUT FILE.");
      printf("\n\nPROGRAM TERMINATED.\n\n");
      return 0;
   }
   
   /* Read control number */
   fscanf(storms,"%i",&ndata);
      
   /* Read hurricane data into array */
   for(i=0; i<=ndata-1; i++)
   {
   	  fscanf(storms,"%s %i %i %c",&hurri[i].hname,&hurri[i].year,
		     &hurri[i].category,&hurri[i].ocean);
   }
   
   /* Sort hurricanes by year */
   for(i=0; i<=ndata-1; i++)
   {
   	  for(j=0; j<=ndata-2; j++)
   	  {
   	  	 if(hurri[j].year > hurri[j+1].year)
   	  	 {
   	  	 	temporary = hurri[j];
   	  	    hurri[j] = hurri[j+1];
   	  	    hurri[j+1] = temporary;
		 }
	  }
   }

   /* Sum hurricane categories */
   for(i=0; i<=ndata-1; i++)
   {
   	  totalcat = totalcat+hurri[i].category;
   }

   /* Determine the number of storms in the Gulf and the number of
      storms in the Atlantic */
   for(i=0; i<=ndata-1; i++)
   {
   	  if(hurri[i].ocean == 'A')
   	  {
   	  	 atlantic++;
      }
      if(hurri[i].ocean == 'G')
   	  {
   	  	 gulf++;
      } 
   }
   

   /* Compute average hurricane category */ 
   avercat = totalcat/ndata;
      
   /* Print headings */
   printf("*****************************************"
          "\n           HURRICANE DATA");
   printf("\n\nHurricane     Year     Category     Ocean");
   
   /* Print array */
   for(i=0; i<=ndata-1; i++)
   {
   	printf("\n%-9s     %4i         %1i          %c",hurri[i].hname,
	      hurri[i].year,hurri[i].category,hurri[i].ocean);
   }
   
   /* Print average category */
   printf("\n\nAverage category = %1i",avercat);
   
   /* Print number of storms in the Gulf and the number of storms
      in the Atlantic */   
   printf("\n\nNumber of Gulf storms = %1i"
	      "\nNumber of Atlantic storms = %1i",gulf,atlantic);
	      
   /* Print headings */
   printf("\n*****************************************\n\n\n");

   /* Close input file */
   fclose(storms);

   /* Exit program */
   return 0;
}
/******************************************************************************/
