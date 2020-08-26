import java.util.Scanner;
import java.util.ArrayList;

public class Zanzibar {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);	
	
		//get input 
		int testCases = scn.nextInt();
		
		//loop through all test cases
		for (int i = 0; i < testCases; i++) {
			//create array list booklet of total number of turtles every new year's day
			ArrayList<Integer> booklet = new ArrayList<Integer>();
			int numElements = 0; //variable to count number of elements (turtles) in the bookletr
			//test to see if there is more numbers
			int temp = scn.nextInt(); //variable to store keyboard input and compare it
			while (temp != 0) {
				//compare to check for end of test case
				booklet.add(temp); //add element to array list
				numElements++; //count number of elements in array list
				temp = scn.nextInt(); 
			}
			//once a zero is reached and booklet contains a single entire test case
			int importCount = 0; //number of turtles who imported to Zanzibar
			//parse through booklet
			for (int j = 0; j < numElements - 1; j++) {
				//if the number of turtles could occur naturally, do nothing
				if (booklet.get(j+1) > ((booklet.get(j)) * 2)) {
					importCount += booklet.get(j+1) - (booklet.get(j) * 2);
				}
			}
			System.out.println(importCount);
		}
	}
}
