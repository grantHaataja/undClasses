/* Lab 9
 * Name: Grant Haataja
 * Date: 11/02/18
 */
public class Player extends Character {

	//CHARACTER CREATION: default constructor if user does not input a name 
	public Player() {
		armorClass = 15 + ((dexterity - 10) / 2);
	}

	//CHARACTER CREATION: object constructor takes in user-typed name
	public Player(String inputName) {
		//assign inputName to a variable
		nameOfCharacter = inputName;
		armorClass = 15 + ((dexterity - 10) / 2);	
	}
	
	//set character name
	public String setName(String input) {
		nameOfCharacter = input;
		return nameOfCharacter;
	}
}
