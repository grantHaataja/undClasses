/*******************************************************************************
DEMO: THIS PROGRAM DEMONSTRATES WRITING TO AN OUTPUT FILE USING THE file, fopen,
      fprintf, AND fclose statements.

PROGRAM DESCRIPTION:
This program simulates rocket flight by calculating distance, velocity, and
acceleration, where time is in seconds with increments of one second.  The
results are printed to the computer screen and to an output file.

DESCRIPTION OF VARIABLES:
NAME  | TYPE   | DESCRIPTION
--------------------------------------------------------------------------------
time  | double | time in seconds
accel | double | rocket acceleration in ft/sec^2
velo  | double | rocket velocity in ft/sec
dist  | double | rocket distance traveled in feet
*******************************************************************************/
               
/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define outputfile "u:\\engr 200\\rocket_flight.txt"

/* Main function */
int main(void)
{
   /* Declare variables */
   double accel, velo, dist, time;
   FILE *rocket;
   
   /* Open output file */
   rocket = fopen(outputfile,"w");
   
   /* Print main headings to computer screen and output file */
   printf("********************************************");
   printf("\n          ROCKET FLIGHT SIMULATION\n\n"
          "TIME    ACCELERATION    VELOCITY    DISTANCE\n"
          "(sec)    (ft/sec^2)     (ft/sec)      (ft)");
   fprintf(rocket,"********************************************");
   fprintf(rocket,"\n          ROCKET FLIGHT SIMULATION\n\n"
          "TIME    ACCELERATION    VELOCITY    DISTANCE\n"
          "(sec)    (ft/sec^2)     (ft/sec)      (ft)");
                 
   /* Calculate and print results to computer screen and output file */
   for(time=0.0; time<=25.0; time++)
   {
      accel = 4.25 - 0.015*pow(time,2);
      velo = 4.25*time - .005*pow(time,3);
      dist = 90.0 + 2.125*pow(time,2) - 0.00125*pow(time,4);
      printf("\n%4.1f     %7.2f       %7.2f     %8.2f",
             time, accel, velo, dist);
     fprintf(rocket,"\n%4.1f     %7.2f       %7.2f     %8.2f",        
     		 time, accel, velo, dist);
   }
   printf("\n********************************************\n\n\n");
   fprintf(rocket,"\n********************************************\n\n\n");         

   /* Close output file */
   fclose(rocket);
   
   /* Exit program */
   return 0;
}
/******************************************************************************/











