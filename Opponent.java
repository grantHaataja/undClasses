/* Lab 9
 * Name: Grant Haataja
 * Date: 11/02/18
 */
public class Opponent extends Character {
	
	//CHARACTER CREATION: default constructor if user does not input a name 
	public Opponent() {
		armorClass = 10 + ((dexterity - 10) / 2);	
	}
	
	//CHARACTER CREATION: object constructor takes in user-typed name
	public Opponent(String inputName) {
		//assign inputName to a variable
		nameOfCharacter = inputName;
		armorClass = 10 + ((dexterity - 10) / 2);
	}
}
