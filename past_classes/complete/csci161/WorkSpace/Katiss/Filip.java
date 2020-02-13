import java.util.Scanner;

public class Filip {
	
	//method to reverse 3-digit numbers
	public static int reverseNumber(Scanner scn, int number) {
		
		int digit1 = number % 10;
		number = number / 10;
		int digit10 = number % 10;
		int digit100 = number / 10;
		int newNumber = (digit1 * 100) + (digit10 * 10) + digit100;
		
		return newNumber;	
	}
	
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		
		//get input
		int num1 = scn.nextInt();
		int num2 = scn.nextInt();
		
		//reverse the 2 numbers
		int newNumber1 = reverseNumber(scn, num1);
		int newNumber2 = reverseNumber(scn, num2);
		
		//compare reversed numbers and print greatest value
		if (newNumber1 > newNumber2) {
			System.out.print(newNumber1);
		}
		else
			System.out.print(newNumber2);
	}
}
