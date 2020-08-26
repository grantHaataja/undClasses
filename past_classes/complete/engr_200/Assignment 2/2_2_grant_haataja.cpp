/*******************************************************************************
ENGR 200.02                                                     DATE: 09/12/2017

PROGRAM: #2                               Author: Grant Haataja
********************************************************************************

PROGRAM DESCRIPTION
This  program  will use known cylinder radius and spherical cap  radius to 
allow user to  calulate cylinder height, spherical  cap height, surface area 
and total volume of concrete needed for building. Results are printed to the 
computer screen.

DESCRIPTION OF VARIABLES
NAME    | TYPE     | DESCRIPTION 
--------------------------------------------------------------------------------
r_cyl   | double   | Inner radius of cylinder in feet
r_cap   | double   | Inner radius of spherical cap in feet
h_cyl   | double   | Height of cylindrical portion in feet
h_cap   | double   | Height of inner spherical cap in feet
v_cap   | double   | Inner volume spherical cap
h_cap2  | double   | Height of spherical cap including wall thickness in feet
r_cap2  | double   | Radius of spherical cap including wall thickness in feet 
r_cyl2  | double   | Radius of clylindrical portion plus wall thickness in feet 
pi      | symbolic | Value for pi  
s_inner | double   | Inner surface area of the building in square feet
wll_thk | double   | Wall thickness in feet
v_bldng | double   | Inner volume of the building in cubic feet 
theta   | double   | Angle theta for cap in degrees  
alpha   | double   | Angle alpha for cap plus wall thickness in degrees
v_conc  | double   | Total volume of concrete needed    
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define pi 3.14159

/* Main function */
int main(void)
{

    /* Declare variables */
    double r_cyl, r_cap, h_cyl, h_cap, v_cap, h_cap2, r_cap2, r_cyl2, s_inner,
	       wll_thk, v_bldng, theta, alpha, v_conc;

    /* Print main heading */
    printf("********************************************************");
    printf("\n       NUCLEAR CONTAINMENT BUILDING COMPUTATIONS");

    /* Input values */
    printf("\n\nEnter inner volume of the building in cubic feet: ");
    scanf("%lf",&v_bldng);
    printf("Enter inner radius of the cylinder in feet      : ");
    scanf("%lf",&r_cyl);
    printf("Enter inner radius of the spherical cap in feet : ");
    scanf("%lf",&r_cap);
    printf("Enter wall thickness of the building in feet    : ");
    scanf("%lf",&wll_thk);
    printf("\nRESULTS");
    
    /* Compute equations */
    theta = asin(r_cyl/r_cap);
    alpha = asin((r_cyl+wll_thk)/(r_cap+wll_thk));
    r_cap2 = r_cap+wll_thk;
    r_cyl2 = r_cyl+wll_thk;
	h_cap = r_cap*(1-cos(theta));
    h_cap2 =r_cap2*(1-cos(alpha)); 
	v_cap = 1.0/3.0*pi*pow(h_cap,2)*(3*r_cap-h_cap);
    h_cyl = (v_bldng - v_cap)/(pi*pow(r_cyl,2));
    s_inner = 2.0*pi*r_cyl*h_cyl + 2.0*pi*r_cap*h_cap;
	v_conc = pi*pow(r_cyl2,2)*h_cyl+1.0/3.0*pi*pow(h_cap2,2)*
			(3.0*r_cap2-h_cap2)-v_bldng;
	
    /* Print output values */
    printf("\nInner volume of the building       = %8.1f ft^3 ",v_bldng);
    printf("\nInner radius of the cylinder       = %8.1f feet ",r_cyl);
    printf("\nInner radius of spherical cap      = %8.1f feet ",r_cap);
    printf("\nWall thickness of the building     = %8.1f feet ",wll_thk);
    printf("\nHeight of the cylinder             = %8.1f feet ",h_cyl);
    printf("\nHeight of the spherical cap        = %8.1f feet ",h_cap2);
    printf("\nInner surface area of the building = %8.1f ft^2 ",s_inner);
    printf("\nTotal volume of concrete needed    = %8.1f ft^3 ",v_conc);
    printf("\n********************************************************\n\n\n");
    
    /* Exit program */
    return 0;
}

/******************************************************************************/
