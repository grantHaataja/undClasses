import java.util.Scanner;

public class Odd {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		
		//get input
		int cases = scn.nextInt();
		int[] numbers = new int[cases];
		
		for (int i = 0; i < cases; i++) {
			numbers[i] = scn.nextInt();
		}
		
		for (int i = 0; i < cases; i++) {
			if (numbers[i] % 2 == 0) {
				System.out.println(numbers[i] + " is even");
			}
			else 
				System.out.println(numbers[i] + " is odd");
		}		
	}
}
