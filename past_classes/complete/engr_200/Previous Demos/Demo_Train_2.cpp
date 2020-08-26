/*******************************************************************************
DEMO: THIS PROGRAM DEMONSTRATES INPUT AND OUTPUT

PROGRAM DESCRIPTION:
This program will prompt the user to enter the weight of the train, the speed of
the train, and the radius of the track curve.  It will calculate the centrifugal
force of a train traveling around a level curved track.  The results are printed
to the computer screen.

DESCRIPTION OF VARIABLES:
NAME    | TYPE     | DESCRIPTION 
--------------------------------------------------------------------------------
force   | double   | calculated centrifugal force in pounds
weight  | double   | weight of the train in tons
speed   | double   | speed of the train in miles per hour
radius  | double   | radius of the track curve in feet
gravity | symbolic | gravitation constant in ft/s/s
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define gravity 32.0

/* Main function */
int main(void)
{
  /* Declare variables */
  double force, weight, speed, radius;

  /* Print main heading */
  printf("*****************************************");
  printf("\n        CENTRIFUGAL FORCE PROGRAM");
             
  /* Enter weight, speed, radius */
  printf("\n\nEnter weight of train in tons      : ");
  scanf("%lf",&weight);
  printf("Enter speed of train in mph        : ");
  scanf("%lf",&speed);
  printf("Enter radius of track curve in feet: ");
  scanf("%lf",&radius);
             
  /* Compute centrifugal force */
  force = (weight*2000.0/gravity)*pow(speed*1.4667,2)/radius;
  	  
  /* Print weight, speed, radius, and force */
  printf("\n\nRESULTS");
  printf("\nWeight of train   = %7.1f tons",weight);
  printf("\nSpeed of train    = %7.1f mph",speed);
  printf("\nRadius of curve   = %7.1f feet",radius);
  printf("\nCentrifugal force = %7.1f pounds",force);
  printf("\n*****************************************\n\n\n");
        
  /* Exit program */
  return 0;
}
/******************************************************************************/


















