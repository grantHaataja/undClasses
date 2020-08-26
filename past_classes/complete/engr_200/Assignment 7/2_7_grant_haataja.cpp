/*******************************************************************************
ENGR 200.02                                                     DATE: 11/02/2017

PROGRAM: #7                              Author: Grant Haataja
********************************************************************************

PROGRAM DESCRIPTION:
This program will read data from from an input file into an array of structures,
sort elements by atomic number, compute mean atomic weight of elements, compute
median atomic weight of elements, determine the element with the maximum atomic
weight, and determine the element with the minimum density. The results will be 
printed to the computer screen and to an output file named element_report.

DESCRIPTION OF VARIABLES
NAME      | TYPE   | DESCRIPTION
--------------------------------------------------------------------------------
elem      | struct | array structure for element data
temp      | struct | temporary structure for sorting element data
ename     | char   | array containing element name
sname     | char   | array containing element symbol
anum      | int    | atomic number of element
aweight   | double | atomic weight of element
density   | double | density of element
crystal   | char   | array containing crystal structure of element
aw_avr    | double | mean atomic weight
aw_med    | double | median atomic weight
min_den   | char   | element with minimum density
max_aw    | char   | element with maximum atomic weight
aw_tot    | double | array of totals for atomic weights
ndata     | int    | number of elements in the input file
i         | int    | outer for loop control variable
j         | int    | inner for loop control variable
k         | int    | subscript variable
min_row   | int    | row position where minimum density occurs
max_row   | int    | row position where maximum atomic weight occurs	
*******************************************************************************/

/* Preprocessor directives */
#include<stdio.h>
#include<math.h>
#define inputfile "u:\\ENGR 200\\Assignment 7\\elements.txt"
#define outputfile "u:\\ENGR 200\\Assignment 7\\element_report.txt"

/* Define structure to represent elements */
struct element 
{
	char ename[11], sname[3], crystal[3];
	int anum;
	double aweight, density;
};

/* Main function */
int main(void)
{
	/* Declare variables */ 
	struct element elem[8], temp;
	double aw_avr, aw_med, aw_tot=0.0;
	int ndata, i, j, k, min_row, max_row;
	char min_den, max_aw;
	FILE *elements, *report;
	
	/* Open input and output files */
   elements = fopen(inputfile,"r");
   report = fopen(outputfile,"w");
   
   /* Verify input file */
   if(elements == NULL)
   {
      printf("\n\nERROR OPENING INPUT FILE.");
      printf("\n\nPROGRAM TERMINATED.\n\n");
      return 0;
   }
	
	/* Read control number */
   fscanf(elements,"%i",&ndata);
   
   /* Read element data in array */
   for(i=0; i<=ndata-1; i++)
   {
   	  fscanf(elements,"%s %s %i %lf %lf %s",&elem[i].ename,
		     &elem[i].sname,&elem[i].anum,&elem[i].aweight,&elem[i].density,
			 &elem[i].crystal);
   }
   
   /* Calculate mean atomic weight */
   for(i=0; i<=ndata-1; i++)
   {
   	  aw_tot=aw_tot+elem[i].aweight;
   }
      aw_avr=aw_tot/ndata;
   
   /* Sort by atomic weight */
   for(i=0; i<=ndata-1; i++)
   {
   	  for(j=0; j<=ndata-2; j++)
   	  {
   	  	 if(elem[j].aweight > elem[j+1].aweight)
   	  	 {
   	  	 	temp = elem[j];
   	  	    elem[j] = elem[j+1];
   	  	    elem[j+1] = temp;
		 }
	  }
   }
   
   /* Calculate median atomic weight */
   	  k=floor(ndata/2);
   	  if((ndata%2)!=0)
   	  {
   	  	aw_med=elem[k].aweight;
	  }
	  else
	  {
	  	aw_med=(elem[k].aweight+elem[k-1].aweight)/2;
	  }
   
   /* Find element with minimum density */
   min_den=elem[0].density;
   for(i=0; i<=ndata-1; i++)
   {
   	  if(elem[i].density<min_den)
   	  {
   	  	min_den=elem[i].density;
   	  	min_row=i;
      }
   }

   /* Find element with maximum atomic weight */
   max_aw=elem[0].aweight;
   for(i=0; i<=ndata-1; i++)
   {
   	  if(elem[i].aweight>max_aw)
   	  {
   	  	max_aw=elem[i].aweight;
		max_row=i;
	  }
   }
   
   /* Print headings */
   printf("***********************************************************"
          "\n                    ELEMENT DATA TABLE");
   printf("\n\nElement     Symbol   Atomic   Atomic   Density    Crystal");
   printf("\n                     Number   Weight    g/cm^3   Structure");
   printf("\n-----------------------------------------------------------");
   
   fprintf(report,"***********************************************************"
          "\n                    ELEMENT DATA TABLE");
   fprintf(report,"\n\nElement     Symbol   Atomic   Atomic   Density    Crysta"
                  "l");
   fprintf(report,"\n                     Number   Weight    g/cm^3   Structure"
                  "\n----------------------------------------------------------"
				  "-");
				  
   /* Print array */ 
   for(i=0; i<=ndata-1; i++)
   {
   	  printf("\n%-11s  %3s       %2i     %6.2f    %6.3f      %3s"
		    ,elem[i].ename,elem[i].sname,elem[i].anum,elem[i].aweight,
			 elem[i].density,elem[i].crystal);
   }
	
	for(i=0; i<=ndata-1; i++)
   {
   	  fprintf(report,"\n%-11s  %3s       %2i     %6.2f    %6.3f      %3s"
		    ,elem[i].ename,elem[i].sname,elem[i].anum,elem[i].aweight,
			 elem[i].density,elem[i].crystal);
   }
	
	/* Print summary report */
	printf("\n-----------------------------------------------------------");
	printf("\n\nSUMMARY REPORT:\nMean atomic weight = %5.2f",aw_avr);
	printf("\nMedian atomic weight = %5.2f",aw_med);
	printf("\nThe element with the minimum density is %-11s",
	        elem[min_row].ename);
	printf("\nThe element with the maximum atomic weight is %-11s",
	        elem[max_row].ename);
	
	fprintf(report,"\n---------------------------------------------------------"
	               "--");
	fprintf(report,"\n\nSUMMARY REPORT:\nMean atomic weight = %5.2f",aw_avr);
	fprintf(report,"\nMedian atomic weight = %5.2f",aw_med);
	fprintf(report,"\nThe element with the minimum density is %-11s",
	        elem[min_row].ename);
	fprintf(report,"\nThe element with the maximum atomic weight is %-11s",
	        elem[max_row].ename);
	
/* Print headings */
   printf("\n***********************************************************"
          "\n\n\n");
          
   fprintf(report,"\n**********************************************************"
          "*\n\n\n");

   /* Close input and output files */
   fclose(elements);
   fclose(report);	
	
   /* Exit program */
   return 0;
}
/******************************************************************************/
