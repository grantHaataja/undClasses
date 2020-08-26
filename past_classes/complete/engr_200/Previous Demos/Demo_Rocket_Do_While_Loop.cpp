/*******************************************************************************
DEMO: THIS PROGRAM DEMONSTRATES THE "do/while" LOOP STRUCTURE

                         do
                         {
                            statements;
                         }while(condition); <--- Must end with a semicolon.
                         
PROGRAM DESCRIPTION:
This program simulates rocket flight by calculating distance, velocity, and
acceleration, where time is in seconds with increments of one second.  The
results are printed to the computer screen.  
 
DESCRIPTION OF VARIABLES:
NAME  | TYPE   | DESCRIPTION
--------------------------------------------------------------------------------
time  | double | time in seconds
accel | double | calculated rocket acceleration in ft/sec^2
velo  | double | calculated rocket velocity in ft/sec
dist  | double | calculated rocket distance traveled in feet
*******************************************************************************/
               
/* Preprocessor directives */
#include <stdio.h>
#include <math.h>

/* Main function */
int main(void)
{
   /* Declare variables */
   double accel, velo, dist, time=0.0;

   /* Print main headings and column headings */
   printf("********************************************"
          "\n          ROCKET FLIGHT SIMULATION"
          "\n\nTIME    ACCELERATION    VELOCITY    DISTANCE"
          "\n(sec)    (ft/sec^2)     (ft/sec)      (ft)");

   /* Calculate acceleration, velocity, distance, and print results */
   do
   {
      accel = 4.25 - 0.015*pow(time,2);
      velo = 4.25*time - .005*pow(time,3);
      dist = 90.0 + 2.125*pow(time,2) - 0.00125*pow(time,4);
      printf("\n%4.1f     %7.2f        %7.2f    %8.2f",
             time, accel, velo, dist);
      time++;
	}while(time <= 25.0);
   printf("\n********************************************\n\n\n");
        
   /* Exit program */
   return 0;
}
/******************************************************************************/







