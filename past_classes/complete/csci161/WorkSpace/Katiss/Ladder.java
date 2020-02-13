import java.util.Scanner;

public class Ladder {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		
		//get input
		short wallHeight = scn.nextShort();	
		byte ladderAngle = scn.nextByte();
		double convert = (Math.PI / 180.0);
		int ladderLength = 0;
		ladderLength = (int)(wallHeight / (Math.sin(ladderAngle * convert)));
		
		if (Math.abs((wallHeight / (Math.sin(ladderAngle * convert))) - ladderLength) > 0.000000000000001) {
			System.out.print(ladderLength + 1);
		}
		else 
			System.out.print(ladderLength);
	}
}
