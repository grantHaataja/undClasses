import java.util.Scanner;

public class Datum {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		
		//get input
		int day = scn.nextInt();
		int month = scn.nextInt();
		String weekday = "";
		int[] year = new int[365];
		int count = 4;
		int tracker = 0;
		
		//fill array
		for (int i = 0; i < 365; i++) {
			year[i] = count % 7;
			count++;
		}
			
		//find position
		if (month == 1) {
			tracker = year[day-1];
		}
		else if (month == 2) {
			tracker = year[day+31-1];
		}
		else if (month == 3) {
			tracker = year[day+31+28-1];
		}
		else if (month == 4) {
			tracker = year[day+31+28+31-1];
		}
		else if (month == 5) {
			tracker = year[day+31+28+31+30-1];
		}
		else if (month == 6) {
			tracker = year[day+31+28+31+30+31-1];
		}
		else if (month == 7) {
			tracker = year[day+31+28+31+30+31+30-1];
		}
		else if (month == 8) {
			tracker = year[day+31+28+31+30+31+30+31-1];
		}
		else if (month == 9) {
			tracker = year[day+31+28+31+30+31+30+31+31-1];
		}
		else if (month == 10) {
			tracker = year[day+31+28+31+30+31+30+31+31+30-1];
		}
		else if (month == 11) {
			tracker = year[day+31+28+31+30+31+30+31+31+30+31-1];
		}
		else if (month == 12) {
			tracker = year[day+31+28+31+30+31+30+31+31+30+31+30-1];
		}
		
		if (tracker == 6) {
			weekday = "Saturday";
		}
		else if (tracker == 0) {
			weekday = "Sunday";
		}
		else if (tracker == 1) {
			weekday = "Monday";
		}
		else if (tracker == 2) {
			weekday = "Tuesday";
		}
		else if (tracker == 3) {
			weekday = "Wednesday";
		}
		else if (tracker == 4) {
			weekday = "Thursday";
		}
		else if (tracker == 5) {
			weekday = "Friday";
		}
		System.out.print(weekday);
		
		
	}
}
