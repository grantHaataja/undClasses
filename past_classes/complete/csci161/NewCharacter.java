/* Lab 9
 * Name: Grant Haataja
 * Date: 11/02/18
 */
import java.util.Random;

public class NewCharacter {
		
	//private and protected variables
	protected int strength;
	protected int dexterity;
	protected int constitution;
	protected int intelligence;
	protected int wisdom;
	protected int charisma;
	protected String nameOfCharacter;
	protected int totalStats = 0;
	//hitpoint and armor class variables (Lab 4)
	protected int hitPoints;
	protected int armorClass;
	
	//create public integers to store X and Y coordinates of player character (Lab 6)
	public int xPlayerVal = 0;
	public int yPlayerVal = 0;
	
	//CHARACTER CREATION: default constructor if user does not input a name 
	public NewCharacter() {
		//assign inputName to a variable
		nameOfCharacter = "";
		//generate random stats
		strength = roll();
		dexterity = roll();
		constitution = roll();
		intelligence = roll();
		wisdom = roll();
		charisma = roll();
		//calculate total stat value	
		totalStats = (strength + dexterity + constitution + intelligence 
			+ wisdom + charisma);	
		//generate hipoints
		hitPoints = 10 + ((constitution - 10) / 2);
	}
	
	//CHARACTER CREATION: object constructor takes in user-typed name
	public NewCharacter(String inputName) {
		//assign inputName to a variable
		nameOfCharacter = inputName;
		//generate random stats
		strength = roll();
		dexterity = roll();
		constitution = roll();
		intelligence = roll();
		wisdom = roll();
		charisma = roll();
		//calculate total stat value	
		totalStats = (strength + dexterity + constitution + intelligence 
			+ wisdom + charisma);	
		//generate hipoints
		hitPoints = 10 + ((constitution - 10) / 2);	
	}
	
	//method to display information about character (Lab 6)
	public String toString() {
	    String output = "";
	    output = ("" + nameOfCharacter + "\'s Stats: \n");
	    output += ("Strength: " + strength + "\n");
	    output += ("Dexterity: " + dexterity + "\n");
	    output += ("Constitution: " + constitution + "\n");
	    output += ("Intelligence: " + intelligence + "\n");
	    output += ("Wisdom: " + wisdom + "\n");
	    output += ("Charisma: " + charisma + "\n");
	    //output += ("Total Stats: " + totalStats + "\n");
	    return output;  
	}
	
	//method to take in stats value and give it a modifier value (Lab 6)
	public int getModifier(int stat) {
	    int mod = 0; // modifier variable
	    mod = (stat - 10) / 2;
	    return mod;
	}
	
	//recursive method to take damage (Lab 9)
	public int takeDamage(int hitpoints) {
		if (hitpoints == 0) {
			return hitpoints;
		}
		else {
			hitpoints--;
			hitpoints = takeDamage(hitpoints);
		}
	return 0;
	}
	
	//public method to get armor class value
	public int getArmorClass() {
		return armorClass;
	}
	
	//public method to get hitpoints value
	public int getHitPoints() {
		return hitPoints;
	}
	
	//public method to set hitpoints value
	public int setHitPoints(int value) {
		hitPoints = value;
		return hitPoints;
	}
	
	//public method to get strength value
	public int getStrength() {
		return strength;
	}
	
	//public method to get dexterity value
	public int getDexterity() {
		return dexterity;
	}
	
	//public method to get constitution value
	public int getConstitution() {
		return constitution;
	}
	
	//public method to get intelligence value
	public int getIntelligence() {
		return intelligence;
	}
	
	//public method to get wisdom value
	public int getWisdom() {
		return wisdom;
	}
	
	//public method to get charisma value
	public int getCharisma() {
		return charisma;
	}
	
	public String getNameOfCharacter() {
		return nameOfCharacter;
	}
		
	// method to calculate random rolls for stats (Lab 2)
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
}
