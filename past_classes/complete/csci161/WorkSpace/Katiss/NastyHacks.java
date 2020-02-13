import java.util.Scanner;

public class NastyHacks {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		
		//get input
		int numCases = scn.nextInt(); //number of cases given to test
		int [] baseRevenue = new int[numCases];
		int [] advRevenue = new int[numCases];
		int [] advCost = new int[numCases];
		
		//loop to get input
		for (int i = 0; i < numCases; i++) {
			baseRevenue[i] = scn.nextInt(); //expected revenue without advertising
			advRevenue[i] = scn.nextInt(); //expected revenue with advertising
			advCost[i] = scn.nextInt(); //cost of advertising
		}
		
		//calculate and display results
		for (int i = 0; i < numCases; i++) {
			
			//advertise
			if (baseRevenue[i] < (advRevenue[i] - advCost[i])) {
				System.out.println("advertise");
			}
			//does not matter
			else if (baseRevenue[i] == (advRevenue[i] - advCost[i])) {
				System.out.println("does not matter");
			}
			//do not advertise
			else {
				System.out.println("do not advertise");
			}
		}
	}
}
