//Grant Haataja

//Includes
#include <stdlib.h>
#include <stdio.h>

//Main Routine
int main (void) {
	//delcare variables
	float interestRate = 0.25; //annual interest rate
	float amountBorrowed = 2000.0; //amount of money borrowed in dollars
	float monthlyPayment = 0.0; //user-entered monthly payment in dollars
	float interest = 0.0; //interest due after the first month in dollars
	float newInterest = 0.0; //interest due after the nth month in dollars
	float remainingBalance = 0.0; //total balance remaining in dollars 
	float totalInterest = 0.0; //total interest paid in dollars
	int currentMonth = 1; //show current month in table
	
	//promt user for monthly payment	
	printf("Enter your montly payment in dollars: ");
	scanf("%f", &monthlyPayment);
	
	//display interestRate, amountBorrowed, and monthlyPayment
	printf("\nAnnual interest rate = %1.2f \n", interestRate);
	printf("Total amount borrowed = %.2f \n", amountBorrowed);
	printf("Monthly payment = %.2f \n\n", monthlyPayment);
	
	//calculate interest
	interest = (interestRate / 12.0) * amountBorrowed;
	newInterest = interest;
	remainingBalance = amountBorrowed;
	
	//check to see if monthly payment is less than interest
	if (monthlyPayment < interest) {
		printf("Interest due: %.2f\n", interest);
		printf("Your monthly payment is less than your interest due.\n");
		printf("Please run program again and choose a higher monthly");
		printf("payment.\n\n");
		exit(0);
	}
	
	//loop to display month-by-month table
	while (1) {
		printf("%d %.2f %.2f\n", currentMonth, newInterest, remainingBalance);
		totalInterest = totalInterest + newInterest;
		interest = newInterest;
		remainingBalance = remainingBalance - monthlyPayment + interest;
		newInterest = (interestRate / 12.0) * remainingBalance;
		currentMonth++;
		//break out of loop if balance is less than or equal to zero
		if (remainingBalance <= 0.0) {
			printf("%d %.2f %.2f\n", currentMonth, newInterest, 
				remainingBalance);
			break;
		}
	}
	printf("\nTotal interest paid: %.2f\n\n", totalInterest);
}
