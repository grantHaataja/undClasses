/*******************************************************************************
ENGR 200.02                                                     DATE: 11/11/2017

EXAM: #3                           Author: Grant Haataja
********************************************************************************

PROGRAM DESCRIPTION:
This program will read data from from an input file into an array of structures
and sort data by latitude degrees. It will then utilize a user-defined function
to compute angle gamma between two cities and return gammma to the main function
to calculate the great circle distance between pairs of cities. The results will
be printed to the computer screen and an output file.

DESCRIPTION OF VARIABLES
NAME      | TYPE     | DESCRIPTION
--------------------------------------------------------------------------------
pi      | symbol | the value for pi
rho     | symbol | the radius of the earth
phi1    | double | angle phi to compute rectangular coordinates for location 1
phi2    | double | angle phi to compute rectangular coordinates for location 2
theta1  | double | angle theta to compute rect. coordinates for location 1
theta2  | double | angle theta to compute rect. coordinates for location 2
x1      | double | x-coordinate for location 1
x2      | double | x-coordinate for location 2
y1      | double | y-coordinate for location 1
y2      | double | y-coordinate for location 2
z1      | double | z-coordinate for location 1
z2      | double | z-coordinate for location 2
dotp    | double | dot product to compute gamma
dist1   | double | magnitude of vector for location 1
dist2   | double | magnitude of vector for location 2
gamma   | double | angle between vectors 1 and 2 
gcd     | double | great circle distance
ndata   | int    | number of elements in the input file
i       | int    | outer for loop control variable
j       | int    | inner for loop control variable
city    | struct | array structure for city data
temp    | struct | temporary structure for sorting element data
cname   | char   | array for city names
latdeg  | int    | latitude degrees 
latmin  | int    | latitude minutes
londeg  | int    | longitude degrees 
lonmin  | int    | longitude minutes
hemi    | char   | character variable for hemisphere
direct  | char   | character variable for direction
*******************************************************************************/

/* Preprocessor directives */
#include<stdio.h>
#include<math.h>
#define pi 3.141592654
#define rho 3958.89
#define inputfile "u:\\engr 200\\cities.txt"
#define outputfile "u:\\engr 200\\great_circle_distance.txt"

/* Define structure for city data */
struct cities 
{
	char cname[12], hemi, direct;
	int latdeg, latmin, londeg, lonmin;
};

/* Main function */
int main(void)
{
	/* Declare variables */ 
	double angle(double dotp, double dist1, double dist2, double x1, double x2,
	             double y1, double y2, double z1, double z2);
	struct cities city[6], temp;
	double phi1, phi2, theta1, theta2, x1, x2, y1, y2, z1, z2, dotp, dist1, 
	       dist2, gamma, gcd;
	int ndata, i, j, latdeg, latmin, londeg, lonmin;
	char cname, hemi, direct;
	FILE *cities, *distance;       
	
	/* Open input and output files */
   cities = fopen(inputfile,"r");
   distance = fopen(outputfile,"w");
   
   /* Verify input file */
   if(cities == NULL)
   {
      printf("\n\nERROR OPENING INPUT FILE.");
      printf("\n\nPROGRAM TERMINATED.\n\n");
      return 0;
   }
	
	/* Read control number */
   fscanf(cities,"%i",&ndata);
   
   /* Read element data in array */
   for(i=0; i<=ndata-1; i++)
   {
   	  fscanf(cities,"%s %i %i %c %i %i %c",&city[i].cname,&city[i].latdeg,
		    &city[i].latmin,&city[i].hemi,&city[i].londeg,&city[i].lonmin,
			&city[i].direct);
   }
   
   /* Sort data by latitude degrees */
   for(i=0; i<=ndata-1; i++)
   {
   	  for(j=0; j<=ndata-2; j++)
   	  {
   	  	 if(city[j].latdeg > city[j+1].latdeg)
   	  	 {
   	  	 	temp = city[j];
   	  	    city[j] = city[j+1];
   	  	    city[j+1] = temp;
		 }
	  }
   }
  
   /* Print headings */
   printf("**********************************************"
          "\n      GREAT CIRCLE DISTANCE CALCULATIONS");
   printf("\n\n                     LATITUDE      LONGITUDE");
   printf("\nCITY                 Deg  Min       Deg  Min\n");
   
   fprintf(distance,"**********************************************"
          "\n      GREAT CIRCLE DISTANCE CALCULATIONS");
   fprintf(distance,"\n\n                     LATITUDE      LONGITUDE");
   fprintf(distance,"\nCITY                 Deg  Min       Deg  Min\n");
				  
   /* Print  */ 
   for(i=0; i<=ndata-1; i=i+2)
   {
   	 
   	  printf("\n%-12s         %3i   %2i %c     %3i   %2i %c"
		    ,city[i].cname,city[i].latdeg,city[i].latmin,city[i].hemi
			,city[i].londeg,city[i].lonmin,city[i].direct);
	  printf("\n\%-12s         %3i   %2i %c     %3i   %2i %c"
		    ,city[i+1].cname,city[i+1].latdeg,city[i+1].latmin,city[i+1].hemi
			,city[i+1].londeg,city[i+1].lonmin,city[i+1].direct);		
     
     	 
	  fprintf(distance,"\n%-12s         %3i   %2i %c     %3i   %2i %c"
		    ,city[i].cname,city[i].latdeg,city[i].latmin,city[i].hemi
			,city[i].londeg,city[i].lonmin,city[i].direct);
	   fprintf(distance,"\n\%-12s         %3i   %2i %c     %3i   %2i %c"
		    ,city[i+1].cname,city[i+1].latdeg,city[i+1].latmin,city[i+1].hemi
			,city[i+1].londeg,city[i+1].lonmin,city[i+1].direct);		
     
     
    /* Compute rectangular coordinates */
	 phi1=90.0-(city[i].latdeg+city[i].latmin/60.0);
     theta1=360.0-(city[i].londeg+city[i].lonmin/60.0);
     
     x1=rho*sin(phi1)*cos(theta1);
     y1=rho*sin(phi1)*sin(theta1);
     z1=rho*cos(phi1);
     
     phi2=90.0-(city[i+1].latdeg+city[i+1].latmin/60.0);
     theta2=360.0-(city[i+1].londeg+city[i+1].lonmin/60.0);
     
     x2=rho*sin(phi2)*cos(theta2);
     y2=rho*sin(phi2)*sin(theta2);
     z2=rho*cos(phi2);
    
     /* Compute great circle distance */
        gamma=angle(dotp,dist1,dist2,x1,x2,y1,y2,z1,z2);
		gcd=rho*gamma;
     
     /* Print computed distance */
      printf("\nDistance between the two cities = %6.1f miles\n",gcd);
      fprintf(distance,"\nDistance between the two cities = %6.1f miles\n",gcd);  
   }
		
/* Print headings */
   printf("***********************************************"
          "\n\n\n");
          
   fprintf(distance,"\n***********************************************"
          "*\n\n\n");

   /* Close input and output files */
   fclose(cities);
   fclose(distance);	
	
   /* Exit program */
   return 0;
}
/*******************************************************************************
This user-defined function will compute the dot product, 2 distances and the 
angle gamma between 2 vectors and return gamma to the main function
*******************************************************************************/
double angle(double dotp, double dist1, double dist2, double x1, double x2,
	             double y1, double y2, double z1, double z2)
{
   /* Declare variables */
   double gamma;   
   /* Compute angle between two vectors */
   dotp=x1*x2+y1*y2+z1*z2;
   dist1=sqrt(pow(x1,2)+pow(y1,2)+pow(z1,2));
   dist2=sqrt(pow(x2,2)+pow(y2,2)+pow(z2,2));
   gamma=acos(dotp/(dist1*dist2));
   
   
   /* Return gamma */
   return gamma;
}
/******************************************************************************/


