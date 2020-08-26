import java.util.Scanner;

public class Workspace {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		
		//scan in number of stars on the flag
		int stars = scn.nextInt();
		int row1 = 2;
		int row2 = 1;
		int col = 0;
		int count = stars;
		
		//print out the leading stuff
		System.out.println(stars + ":");
		
		for (int i = 0; i < (stars / 2) + 1; i++) {
			for (int j = 0; j < stars / 2; j++) {
				if (stars % (row1 + row2 + row1) == 0) {
					System.out.println(row1 + "," + row2);
				} 
				else if (stars % row1 == 0 && stars % row2 == 0) {
					System.out.println(row1 + "," + row2);
				}
				else if (stars % (row1 + row2) == 0) {
					System.out.println(row1 + "," + row2);
				}
				row2++;
			}
			row1++;
		}
	
	}
}
