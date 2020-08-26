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
sn      | integer  | well site number from first column of input file
hd      | double   | hole depth of well from second column of input file
ipthdr  | double   | ideal powder to hole depth ratio
inos    | double   | ideal number of sticks of dynamite
ipc     | double   | ideal powder charge
i       | integer  | loop control variable
anos    | integer  | actual number of sticks of dynamite
apc     | integer  | actual powder charge
ndata   | integer  | number of record lines in the input file
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define inputfile "u:\\engr 200\\oil_explore.txt"
#define outputfile "u:\\engr 200\\oil_report.txt"

/* Main function */
int main(void)
{
   /* Declare variables */
   double hd, ipthdr, inos, ipc;
   int i, sn, anos, apc, ndata;
   FILE *oile, *oilr;

   /* Open input & output files */
   oile = fopen(inputfile,"r");
   oilr = fopen(outputfile,"w");
   
   /* Verify input file */
   if(oile == NULL)
   {
      printf("\n\nERROR READING INPUT FILE\n\nPROGRAM TERMINATED\n\n");
      return 0;
   }
   
   /* Read control number */
   fscanf(oile,"%i",&ndata);
   
   /* Print main headings and column headings */
   printf("****************************************************");
   printf("\n               DAILY DRILLING REPORT"
          "\n\nSITE   DEPTH   IDEAL POWDER   ACTUAL POWDER   STICKS"
          "\n ID     (ft)      (lbs)           (lbs)");
   fprintf(oilr,"****************************************************");
   fprintf(oilr,"\n               DAILY DRILLING REPORT"
          "\n\nSITE   DEPTH   IDEAL POWDER   ACTUAL POWDER   STICKS"
          "\n ID     (ft)      (lbs)           (lbs)");
                
   /* Read input values and print results */
   for(i=1; i<=ndata; i++)
   {
      fscanf(oile,"%i,%lf",&sn,&hd);
      ipthdr = hd/3.0;
      inos = ipthdr/2.0;
      ipc = inos*5.0;
      anos = ipthdr/2;
      apc = anos*5;      
      if(hd<30.0)
      {
      	printf("\n%4i     %3.0lf   HOLE TOO SHALLOW FOR BLASTING",
	  		 sn,hd);
	  	fprintf(oilr,"\n%4i     %3.0lf   HOLE TOO SHALLOW FOR BLASTING",
	  		 sn,hd);
	  }
	  else		   		 
	  {
	  	printf("\n%4i     %3.0lf      %6.2lf            %3i          %3i",
	         sn,hd,ipc,apc,anos);
     	fprintf(oilr,"\n%4i     %3.0lf      %6.2lf            %3i          %3i",
	         sn,hd,ipc,apc,anos);
	  }
   } 
   printf("\n****************************************************\n\n\n");
   fprintf(oilr,"\n****************************************************\n\n\n");
   
   /* Close input & output files */
   fclose(oile);
   fclose(oilr);
            
   /* Exit program */
   return 0;
}
/******************************************************************************/




