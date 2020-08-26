import java.util.*;

public class Spavanac {
    public static void main(String[] args) {
    Scanner scnr = new Scanner(System.in);
    
    // declare variable and get input
    int hours = scnr.nextInt();
    int minutes = scnr.nextInt();
    int temp;
    
    // easy case where time is 45 minutes or more
    if (minutes > 44) {
        minutes = minutes - 45;
        System.out.print(hours + " " + minutes);
    }
    // harder case where minutes is less than 45 and hours must change
    else if (hours > 0) {
        temp = 45 - minutes;
        minutes = 60 - temp;
        hours = hours - 1;
        System.out.print(hours + " " + minutes);
    }
    // other harder case where minutes is less than 45 and hours is at 0
    else if (hours == 0) {
        temp = 45 - minutes;
        minutes = 60 - temp;
        hours = 23;
        System.out.print(hours + " " + minutes);
    }
    
    }

}
