/*******************************************************************************
DEMO: DEVELOPING A "C" PROGRAM

PROGRAM DESCRIPTION:
This program will calculate the centrifugal force of a train traveling around a
level curved track.  The results are printed to the computer screen.

DESCRIPTION OF VARIABLES:
NAME    | TYPE  | DESCRIPTION 
--------------------------------------------------------------------------------
force   | float | calculated centrifugal force in pounds
weight  | float | weight of the train in tons
speed   | float | speed of the train in miles per hour
radius  | float | radius of the track curve in feet
gravity | float | gravitation constant (ft/s/s)
*******************************************************************************/
   
/* Preprocessor directives */
#include <stdio.h>
#include <math.h>

/* Main function */
int main(void)
{
  /* Declare and initialize variables */
  float force,weight=150.0,speed=65.2,radius=2640.0,gravity=32.0;
  
  /* Compute centrifugal force */
  force=((weight*2000.0)/gravity)*(((speed*1.4667)*(speed*1.4667))/radius);
   
  /* Print weight, speed, radius, and force */
  printf("%f   %f   %f   %f",weight,speed,radius,force);
  
  /* Exit program */
  return 0;
}
/******************************************************************************/















