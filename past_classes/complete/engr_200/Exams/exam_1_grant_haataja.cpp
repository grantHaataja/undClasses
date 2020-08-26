/*******************************************************************************
ENGR 200.02                                                     DATE: 09/18/2017

EXAM: #1                               Author: Grant Haataja
********************************************************************************

PROGRAM DESCRIPTION:
This program  looks  at a situation  where a train is  heading toward a crossing 
from south to north, and a car is heading toward the crossing from west to east.
It  allows the  user to compute  the positions of both the  car  and  train,  as 
well  as the distance  between them at any given time,  by entering the speed of 
the car,  acceleration of the car,  distance of the car from the crossing, speed 
of the train, distance of the train from the crossing, and the time. The results
are printed to the computer screen.

DESCRIPTION OF VARIABLES:
NAME        | TYPE     | DESCRIPTION                                
--------------------------------------------------------------------------------
spe_c       | double   | Initial speed of the car in miles per hour
acc_c       | double   | Acceleration of the car in feet per second per second
dis_c       | double   | Initial distance of the car from the crossing in feet
spe_t       | double   | Initial speed of the train in miles per hour
dis_t       | double   | Initial distance of the train from the crossing in feet
time        | double   | Time in seconds
pos_c       | double   | Computed position of car from crossing in feet
pos_t       | double   | Computed position of train from crossing in feet	
vel_c       | double   | Initial speed of the car in feet per second
vel_t       | double   | Initial speed of the train in feet per second
distance    | double   | Computed distance between car and train 
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>

/* Main function */
int main(void)
{
	
	/* Declare variables */
	double spe_c, acc_c, dis_c, spe_t, dis_t, time, pos_c, pos_t, vel_c, vel_t,
	       distance;
	
	/* Print main heading */
	printf("*********************************************************");
	printf("\n                  MOTION OF TWO VEHICLES\n\n");
	
	/* Input values */
	printf("Enter the car speed in mph                : ");
	scanf("%lf",&spe_c);
	printf("Enter the train speed in mph              : ");
	scanf("%lf",&spe_t);
	printf("Enter the car initial position in feet    : ");
	scanf("%lf",&dis_c);
	printf("Enter the train initial position in feet  : ");
	scanf("%lf",&dis_t);
	printf("Enter the car acceleration in feet/sec/sec: ");
	scanf("%lf",&acc_c);
	printf("Enter the time in seconds                 : ");
	scanf("%lf",&time);
	
	/* Compute equations */
	vel_c = spe_c*5280.0/3600.0; 
	vel_t = spe_t*5280.0/3600.0; 
	pos_c = -dis_c+vel_c*time+0.5*acc_c*pow(time,2);
	pos_t = -dis_t+vel_t*time;
	distance = sqrt(pow(pos_c,2)+pow(pos_t,2));
	
	/* Print output values */
	printf("\n\nRESULTS");
	printf("\nThe car speed               = %6.1f mph ",spe_c);
	printf("\nThe train speed             = %6.1f mph ",spe_t);
	printf("\nThe car initial position    = %6.1f feet ",dis_c);
	printf("\nThe train initial position  = %6.1f feet ",dis_t);
	printf("\nThe car acceleration        = %6.1f feet/sec/sec ",acc_c);
	printf("\nThe computed distance       = %6.1f feet ",distance);
	printf("\nThe computed car position   = %6.1f feet ",pos_c);
	printf("at %4.1f seconds ",time);
	printf("\nThe computed train position = %6.1f feet ",pos_t);
	printf("at %4.1f seconds ",time);
	printf("\n*********************************************************\n\n\n");
	
	/* Exit program */
    return 0;
    }
