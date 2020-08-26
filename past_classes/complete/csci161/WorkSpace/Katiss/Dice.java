import java.util.Scanner;

public class Dice {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		
		//get input
		int dice1 = scn.nextInt();
		int dice2 = scn.nextInt();		
		int bound1 = dice1 + 1;
		int bound2 = dice2 + 1;
		int number = 0;
		
		if (bound1 == bound2) {
			System.out.println(bound1);
		}
		else if (bound1 < bound2) {
			number = bound1;
			while (number <= bound2) {
				System.out.println(number);
				number++;
			}
		}
		else {
			number = bound2;
			while (number <= bound1) {
				System.out.println(number);
				number++;
			}
		}		
	}
}
