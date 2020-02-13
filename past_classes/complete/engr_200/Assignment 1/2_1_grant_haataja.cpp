/*******************************************************************************
ENGR 200.02                                                     DATE: 09/05/2017

PROGRAM: #1                               Author: Grant Haataja
********************************************************************************

PROGRAM DESCRIPTION:
This program will allow the user to calculate intermediate  coefficients of lift 
by   inputting  2  angles  of  attack,  2  known  coefficients  of  lift, and an 
interpolate angle. The results are printed to the computer screen.

DESCRIPTION OF VARIABLES:
NAME        | TYPE     | DESCRIPTION                                
--------------------------------------------------------------------------------
com_co_lift | double   | computed coefficient of lift
co_lift1    | double   | first known coefficient of lift
co_lift2    | double   | second known coefficient of lift
int_angle   | double   | interpolation angle in degrees
angle1      | double   | first angle in degrees
angle2      | double   | second angle in degrees	
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>

/* Main function */
int main(void)
{

    /* Declare variables */
    double com_co_lift, co_lift1, co_lift2, int_angle, angle1, angle2;
    
    /* Print main heading */
    printf("******************************************");
    printf("\n       LINEAR INTERPOLATION PROGRAM");
    
    /* Input values */
    printf("\n\nEnter first angle in degrees        : ");
    scanf("%lf",&angle1);
    printf("Enter first coefficient of lift     : ");
    scanf("%lf",&co_lift1);
    printf("Enter second angle in degrees       : ");
    scanf("%lf",&angle2);
    printf("Enter second coefficient of lift    : ");
    scanf("%lf",&co_lift2);
    printf("Enter interpolation angle in degrees: ");
    scanf("%lf",&int_angle);

    /* Compute linear interpolation value */
    com_co_lift = ((co_lift2-co_lift1)*(int_angle-angle1)/(angle2-angle1))+co_lift1;
    
    /* Print output values */
    printf("\n\nRESULTS");
    printf("\nFirst angle in degrees         = %6.3f ",angle1);
    printf("\nFirst coefficient of lift      = %6.3f ",co_lift1);
    printf("\n\nSecond angle in degrees        = %6.3f ",angle2);
    printf("\nSecond coefficient of lift     = %6.3f ",co_lift2);
    printf("\n\nInterpolation angle in degrees = %6.3f ",int_angle);
    printf("\nComputed coefficient of lift   = %6.3f ",com_co_lift);
    printf("\n******************************************\n\n\n");
    
    /* Exit program */
    return 0;
    }
/******************************************************************************/
