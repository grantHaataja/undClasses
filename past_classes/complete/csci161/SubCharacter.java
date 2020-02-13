public class SubCharacter extends Character {

	public SubCharacter () {
		armorClass = 15 + ((dexterity - 10) / 2);
	}
	
	//CHARACTER CREATION: object constructor takes in user-typed name
	public SubCharacter(String inputName) {
		//assign inputName to a variable
		nameOfCharacter = inputName;
		armorClass = 15 + ((dexterity - 10) / 2);	
	}
	
	@Override
	public String toString(){
			String string = "My name is definitely not : "+nameOfCharacter
				+" and these are definitely not my stats,\n";
			string += "["+strength+", "+dexterity+", "+constitution+", "+intelligence
				+", "+wisdom+", "+charisma+"]\n";
			if(hitPoints <= 0){
				string += "I'm so alive right now\n";
			}else{
				string += "I'm almost dead with only "+hitPoints+" HP left\n";
			}
			return string;
		}

}
