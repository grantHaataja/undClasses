import java.util.Scanner;

public class Planina {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);	
		
		//get input (number of iterations)
		int iterations = scn.nextInt();
		int sidePoints = 2;
		
		//count number of points on one side
		for (int i = 0; i < iterations; i++) {
			sidePoints = sidePoints + (sidePoints - 1);
		}
		
		// calculate and print answer
		System.out.println(sidePoints * sidePoints);
		
	}
}
