/* Lab 2 - Stats Roll
 * Name: Grant Haataja
 * Date: 09/05/18
 */

import java.util.Random;

public class StatsRoll {
	
	//public global variables
	char createCharacter; // stores variable to confirm or deny character creation
	int strength;
	int dexterity;
	int constitution;
	int intelligence
	int wisdom;
	int charisma;
	String nameOfCharacter;
	int statsAvg = 0;
	
	//object constructor takes in user-typed name
	public StatsRoll(String inputName) {
		
		//assign inputName to a variable
		nameOfCharacter = inputName;
	
		//generate stats
		Random rndm = new Random(); // new random number generator
		strength = roll();
		dexterity = roll();
		constitution = roll();
		intelligence = roll();
		wisdom = roll();
		charisma = roll();
		String nameOfCharacter;
		statsAvg = (strength + dexterity + constitution + intelligence + wisdom + charisma)/6;
		
		
	}
	
	
	//public method to get stats value
	public int getstatsAvg() {
		return statsAvg;
	}
	
	public String getnameOfCharacter() {
		return nameOfCharacter;
	}


		// The following statements check user decision to create character and run program

        // ask if user wants to create character

        System.out.println("To create new character, press a");
		System.out.println("To exit, press b");

		while (true) {

            createCharacter = scnr.nextLine().charAt(0);
    
			if (createCharacter == 'a') {
				
				System.out.println("Enter your character's name: "); // get character name
				nameOfCharacter = scnr.nextLine();
				
				 // print results to the screen
				
				System.out.println("Bathe in the glory of " + nameOfCharacter + "!");
				System.out.println();
				System.out.println("Your strength is " + strength);
				System.out.println("Your dexterity is " + dexterity);
				
				System.out.println("Your constitution is " + constitution);
				System.out.println("Your intelligence is " + intelligence);
				System.out.println("Your wisdom is " + wisdom);
				System.out.println("Your charisma is " + charisma);
				System.out.println();
				
				// compute average stats and print result to screen
				
				statsAvg = (strength + dexterity + constitution + intelligence + wisdom + charisma)/6;
				System.out.println("You average stats roll is " + statsAvg);
				
				System.exit(1);
				
			} 
			// exit program if user chooses
			else if (createCharacter == 'b') {
                
                System.out.println("If you're sure you want to miss out, press c"); 
            }

			else if (createCharacter == 'c') {
					System.out.println("See ya, sucka");
					System.exit(0);
			}
		}

        // Program should never get here

	}

	// the following function rolls 4 six-sided dice and returns the sum of the top 3 rolls
	
	public static int roll() {
		Random rndm = new Random();
		
		int roll1 = rndm.nextInt(6) + 1;
		int roll2 = rndm.nextInt(6) + 1;
		int roll3 = rndm.nextInt(6) + 1;
		int roll4 = rndm.nextInt(6) + 1;
		int smt = 0;
		
		if ((roll1 >= roll2) && (roll3 >= roll2) && (roll4 >=roll2)) {
			smt = smt + roll1 + roll3 + roll4;
		}
		else if ((roll2 >= roll1) && (roll3 >= roll1) && (roll4 >=roll1)) {
			smt = smt + roll2 + roll3 + roll4;
		}
		else if ((roll1 >= roll3) && (roll2 >= roll3) && (roll4 >=roll3)) {
			smt = smt + roll1 + roll2 + roll4;
		}
		else if ((roll1 >= roll4) && (roll2 >= roll4) && (roll3 >=roll4)) {
			smt = smt + roll1 + roll2 + roll3;
		}

		return smt;
	}

    // the following function is the main menu where users can create characters
    // or load previous games

    /*public static void mainMenu() {
        Scanner scnr = new Scanner(System.in);
        
        String createCharacter;
        String characterName;

        System.out.println("Welcome to the DnD World of Arctansia...");
        System.out.println("\nTo create new character, type 'New'.");
        
        createCharacter = scnr.nextLine();
        
        if (createCharacter.equalsIgnoreCase("New")) {
            System.out.println("Enter your character name: ");
            characterName = scnr.nextLine();
            System.out.println("Greetings, " + characterName);
            
        }
        */
    }
}
