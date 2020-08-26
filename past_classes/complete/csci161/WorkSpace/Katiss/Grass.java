import java.util.Scanner;

public class Grass {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		
		//get input
		double cost = scn.nextDouble();
		int numLawns = scn.nextInt();
		double[][] dimensions = new double[numLawns][2];
		double[] area = new double[numLawns];
		double totalArea = 0;
		double totalCost = 0; 
		
		//loop to get width (i) and length (j) of the lawns
		for (int i = 0; i < numLawns; i++) {
			for (int j = 0; j < 2; j++) {
				dimensions[i][j] = scn.nextDouble();
			}
		}
		
		//loop to calculate areas
		for (int i = 0; i < numLawns; i++) {
			area[i] = dimensions[i][0] * dimensions[i][1];
			totalArea += area[i];
		}
		
		totalCost = cost * totalArea;
		System.out.printf("%10.7f",totalCost);
		
	}
}
