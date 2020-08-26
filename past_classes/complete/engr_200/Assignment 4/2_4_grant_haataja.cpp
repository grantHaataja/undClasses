/*******************************************************************************
ENGR 200.02                                                     DATE: 10/03/2017

PROGRAM: #4                              Author: Grant Haataja
********************************************************************************

PROGRAM DESCRIPTION:
This program will read radius and  height of the cylinder, the radius and height
of the  frustrum, the control  number and  the float heights from an input file,
and pass these values to a user-defined function. The user-defined function will
compute  the volume  of water in cubic  meters in the tank and pass the computed 
volume back to the main function. The results are printed to the computer screen
and to an output file.
         
DESCRIPTION OF VARIABLES:
NAME            | TYPE    | DESCRIPTION
--------------------------------------------------------------------------------
pi              | symbolic| value for pi
vc              | double  | water volume of cylindrical portion
rc              | double  | radius of the cylinder
hf              | double  | height of the frustum
vcf             | double  | total water volume of tank
computed_volume | double  | computed volume of water in tank
hc              | double  | height of the cylinder
rw              | double  | radius of water in frustum 
rf              | double  | raidus of frustum
hfl             | double  | height of float
i               | integer | for loop control variable
ndata           | integer | number of record lines in input file
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define pi 3.14159
#define inputfile "u:\\engr 200\\Assignment 4\\water_level.txt"
#define outputfile "u:\\engr 200\\Assignment 4\\water_volume.txt"

/* Main function */
int main(void)
{
   /* Declare variables */
   double volume(double rc, double hc, double hf, double hfl);   
   double computed_volume, vc, rc, hfl, hf, vcf, hc, rw, rf;
   int i, ndata;
   FILE *wlev, *wvol;

   /* Open input and output files */
   wlev = fopen(inputfile, "r");
   wvol = fopen(outputfile, "w");
   
   /* Verify input file and read input data */
   if(wlev == NULL)
   {
      printf("\n\n\nERROR OPENING INPUT FILE.");
      printf("\n\nPROGRAM TERMINATED.\n\n\n");
      return 0;
   }
   
   /* Read tank dimensions and control number */
   fscanf(wlev,"%lf, %lf, %lf, %lf,",&rc,&hc,&rf,&hf);
   fscanf(wlev,"%i",&ndata);
   /* Print headings */
   printf("*************************************************");
   printf("\n            CITY WATER SUPPLY PROGRAM"
          "\n\nWater tank dimensions: ");
   printf("\nCylinder radius = %4.1f "
          "\nCylinder height = %4.1f "
          "\nFrustum radius = %4.1f "
          "\nFrustum height = %4.1f ",rc,hc,rf,hf);
          
   fprintf(wvol,"*************************************************");
   fprintf(wvol,"\n            CITY WATER SUPPLY PROGRAM"
           "\n\nWater tank dimensions: ");
   fprintf(wvol,"\nCylinder radius = %4.1f "
          "\nCylinder height = %4.1f "
          "\nFrustum radius = %4.1f "
          "\nFrustum height = %4.1f ",rc,hc,rf,hf);
    printf("\n\nFloat Height          Water Volume ");
    printf("\n  (meters)           (cubic meters)");
    fprintf(wvol,"\n\nFloat Height          Water Volume ");
    fprintf(wvol,"\n  (meters)           (cubic meters)");
	      
   /* Read values, compute, and print */
   for(i=1; i<=ndata; i++)
   {
      fscanf(wlev,"%lf",&hfl);
      if(hfl<0.0)
      {
      	 printf("\n %5.1f    Height negative-Calibrate float.",hfl);
         fprintf(wvol,"\n %5.1f    Height negative-Calibrate float.",hfl);                
	  }
	  else if(hfl>(hc+hf))
	  {
	  	 printf("\n %5.1f    Height > %4.1f meters-Calibrate float.",hfl,
		   (hc+hf));
		 fprintf(wvol,"\n %5.1f    Height > %4.1f meters-Calibrate float.",
		 hfl,(hc+hf));
	  }
	  else if(hfl==0.0 || hfl<3.0)
	  {
	  	 printf("\n %5.1f    Height < 3.0 meters-Fill tank.",hfl);
	  	 fprintf(wvol,"\n %5.1f    Height < 3.0 meters-Fill tank.",hfl);
	  }
	  else if(hfl>=3.0 && hfl<=(hc+hf))
	  {
         computed_volume = volume(rc, hc, hf, hfl);
         printf("\n %5.1f                %8.2f   ",hfl,computed_volume);
         fprintf(wvol,"\n %5.1f                %8.2f   ",hfl,computed_volume);
      }
   }
   
   /* Print Final Headings */
   printf("\n\n                  END OF REPORT");
   printf("\n*************************************************\n\n\n");
   fprintf(wvol,"\n\n                  END OF REPORT");
   fprintf(wvol,"\n*************************************************\n\n\n");
  
   /* Close input and output files */
   fclose(wlev);
   fclose(wvol);
   
   /* Exit the program */
   return 0;
}
/*******************************************************************************
This function will calculate the total water volume of the tank after receiving 
the height of float, the height of the cylinder, the radius of the cylinder, and
the radius of the water in the frustum. 
*******************************************************************************/
double volume(double rc, double hc, double hf, double hfl)
{
   /* Declare variables */
   double computed_volume, rw;
   
   /* Compute water volume */
   {
   	  if(hfl>=3.0 && hfl<=hc)
   	  {
   	     computed_volume = pi*pow(rc,2)*hfl;
      }
      else
      {
	     rw = rc+10.5/hf*(hfl-hc);
         computed_volume = (pi*pow(rc,2)*hc)+1.0/3.0*pi*(hfl-hc)*(pow(rc,2)+rc*rw+pow(rw,2));
	  }
   }
   
   /* Return water volume */
   return computed_volume;
}
/******************************************************************************/









