/*******************************************************************************
Demo: PC System Analysis

This program determines PC system limitations for integer and floating-point
numbers using Bloodshed's Dev-C++ 5.8.3 compiler.  The results are printed to
the computer screen.                    
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <limits.h>
#include <float.h>

/* Main Function */
int main(void)
{
  /* Print main heading */
  printf("\n*********************************************");
  printf("\n            PC SYSTEM LIMITATIONS");
  printf("\n (using Bloodshed's Dev C++ 5.8.3 compiler)");
  
  /* Print integer type maximums */
  printf("\n\nShort integer maximum: %5i",SHRT_MAX);
  printf("\nInteger maximum      : %10i",INT_MAX);
  printf("\nLong integer maximum : %10i",LONG_MAX);
  
  /* Print float precision, range, maximum */
  printf("\n\nFloat precision digits: %1i",FLT_DIG);
  printf("\nFloat maximum exponent: %2i",FLT_MAX_10_EXP);
  printf("\nFloat maximum         : %13.6e",FLT_MAX);
  
  /* Print double precision, range, maximum */
  printf("\n\nDouble precision digits: %2i",DBL_DIG);
  printf("\nDouble maximum exponent: %3i",DBL_MAX_10_EXP);
  printf("\nDouble maximum         : %13.6e",DBL_MAX);
  
  /* Print long precision, range, maximum */
  printf("\n\nLong double precision digits: %2i",LDBL_DIG);
  printf("\nLong double maximum exponent: %4i",LDBL_MAX_10_EXP);
  printf("\nLong double maximum         : %13.6e",LDBL_MAX);
  printf("\n*********************************************\n\n\n");
  
  /* Exit program */
  return 0;
}
/******************************************************************************/
