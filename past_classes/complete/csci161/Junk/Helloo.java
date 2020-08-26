
/* CSCI 161 Lab 1: Helloo
 * Name: Grant Haataja
 * Date: 08/29/18 */

import java.util.Scanner;

public class Helloo {
	public static void main(String[] args) {
		Scanner scnr = new Scanner(System.in);
		int getNum;

		System.out.println("What is your name, friend: ");
		String userName = scnr.nextLine(); // Receives Name from user

		System.out.println("Give me a number less than 10 and greater than 5: ");
		getNum = scnr.nextInt(); // Takes number between 5 and 10 from user

		if ((getNum > 5) && (getNum < 10)) {

			/*
			 * The following lines print the information to the computer screen and
			 * calculate the basic Math functions
			 */

			System.out.println("Hello, " + userName + " ,");
			System.out.println("you have input the number: " + getNum);
			System.out.println("your number divided by 2 is: " + (getNum / 2.0));
			System.out.println("your number plus 5 is: " + (getNum + 5));
			System.out.println("your number squared is " + (Math.pow(getNum, 2)));

		} else {
			System.out.println("that number is not in the right range, silly ");
			System.exit(0);
		}
	}
}
