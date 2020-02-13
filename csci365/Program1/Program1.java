//Grant Haataja
//Program 1
import java.util.Random;
public class Program1 {
	//function to fill the array
	static void fillArray(int[] arr) {
		//instantiate random
		Random randy = new Random();
		
		int temp = 0;
		for (int i = 0; i < arr.length; i++) {
			temp = randy.nextInt(101);
			arr[i] = temp;
		}
	}	
	//function to find and return highest value in array
	static int findHighest(int[] arr) {
		int max = 0;
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		return max;
	}
	//function to find and return lowest value in array
	static int findLowest(int[] arr) {
		int min = 100;
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] < min) {
				min = arr[i];
			}
		}
		return min;
	}
	//function to find and return average value in array
	static double findAverage(int[] arr) {
		double avg = 0.0;
		double sum = 0.0;
		for (int i = 0; i < arr.length; i++) {
			sum += arr[i];
			avg = sum / arr.length;
		}
		return avg;
	}
	//function to print counting values and the array values
	static void printValues(int[] arr) {
		System.out.println("\nValues");
		for (int i = 0; i < arr.length; i++) {
			System.out.printf("%2d " + " %3d\n", i+1, arr[i]);
		}
	}
		
	public static void main(String args[]) {
		//create array
		int[] dopeArray = new int[20];
		
		//call function to fill array with random values
		fillArray(dopeArray);
		
		//call function to return high value of array
		int highValue = findHighest(dopeArray);
		
		//print highest value
		System.out.print("High value " + highValue + "\n");
		
		//call function to return low value of array
		int lowValue = findLowest(dopeArray);

		//print lowest value
		System.out.print("Low value " + lowValue + "\n");
		
		//call function to return average value of array
		double avgValue = findAverage(dopeArray);
		
		//print average value
		System.out.print("Average " + avgValue + "\n");
		
		//call function to print out the values of array
		printValues(dopeArray);	
	}
}
