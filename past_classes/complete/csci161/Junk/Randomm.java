import java.util.Random;

public class Randomm {
   public static void main (String[] args) {
      Random randGen = new Random(); //New random number generator 
	  
	  int dice1;
	  int dice2;
	  int dice3;
	  int dice4;
	  
	  dice1 = randGen.nextInt(6) + 1; // Simulates a D6
	  dice2 = randGen.nextInt(6) + 1;
	  dice3 = randGen.nextInt(6) + 1;
	  dice4 = randGen.nextInt(20) + 1; //Simulates a D20
	  
	  System.out.println("dice1 rolls a " + dice1);
	  System.out.println("dice2 rolls a " + dice2);
	  System.out.println("dice3 rolls a " + dice3);
	  System.out.println("dice4 rolls a " + dice4);

	   
   }
}   