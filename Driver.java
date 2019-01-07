/* Pizza Run
 * Creator: Grant Haataja
 * Date: 11/02/18
 * 
 * Instructions:
 */
import java.util.*;
import java.io.*;
import java.awt.Desktop;

public class Driver {
	static ArrayList<Opponent> opponentArray = new ArrayList<Opponent>();
	static boolean fubar = true;	
	
	// Method to display map to screen (Lab 5) (Lab 6)
	public static void displayMap(Room[][] map) {
		for (int i = 0; i < map.length; ++i) {
			//print left boundary for map
			System.out.print("|");
			for (int j = 0; j < map.length; ++j) {
				//get ID for each space of map to print corresponding symbol
				switch (map[i][j].getID()) {
					case -1: 
						System.out.print("#"); //wall
					break;
						
					case 0:
						System.out.print(" "); //empty space
					break;
						
					case 1:
						System.out.print("@"); //player character
					break;
					
					case 2:
						System.out.print("!"); //enemy character
					break;
					
					case 3:
						System.out.print("*"); //end goal
					break;
						
					default:
						System.out.print("?"); //error
					break;
				}	
			}	
			//print right boundary for map
			System.out.println("|");
		}
	}
	
	//Starting Menu method (Lab 8)
	public static char mainMenu(Scanner scnr) {
		System.out.println("Welcome to Pizza Run!");
		System.out.println();
		System.out.println("Press 'N' to start new game");
		System.out.println("Press 'L' to load game from file");
		System.out.println("Press 'Z' to save game at any time");
		
		//get user input
		char input = scnr.nextLine().charAt(0);
		return input;
	}
	
	//Method to load map from file (Lab 8)
	public static void loadMap(Player playerCharacter, Room[][] map) {
		Scanner mapScnr = null; 
		Scanner newScnr = new Scanner(System.in);
		String fileName = "";
		//variable to make sure code doesn't run twice
		fubar = true;
		
		//try to open file (Lab 9)
		System.out.println("Enter file name in the form of file.txt");
		System.out.println(fileName);
		fileName = newScnr.nextLine();
		System.out.println("Opening file " + fileName + "...");
			
		try {
			File mapFile = new File(fileName);
			mapScnr = new Scanner(mapFile);
		} catch (FileNotFoundException excpt) {
			System.out.println("File not found." + excpt);
			loadMap(playerCharacter, map);
			//set to false to avoid executing the following loop a second time
			fubar = false;
		}
		
		if (fubar) {
			//for counting rows to correspond to 2D map array
			int i = 0;
			//for printing numbered enemies
			int num = 1;
			//enter loop if loaded file has input
			while (mapScnr.hasNextLine()) {
				//scan in first line of loaded file
				String input = mapScnr.nextLine();
				for (int j = 0; j < input.length(); j++) {
					//parse through scanned in line, position by position
					switch (input.charAt(j)) {
						//set player character
						case 'X':
							map[i][j] = new Room(0); 
							playerCharacter.xPlayerVal = j;
							playerCharacter.yPlayerVal = i;
						break;
						//set walls
						case 'W':
							map[i][j] = new Room(-1);
						break;
						//set empty spaces
						case ' ':
							map[i][j] = new Room(0);
						break;
						//set enemy characters
						case 'E':
							map[i][j] = new Room(2);
							//give vegan's unique names (Lab 8)
							Opponent opponent = new Opponent("Vegan" + num);
							map[i][j].opponent = opponent;
							opponentArray.add(opponent);
							num++;
						break;
						//set end goal
						case 'G':
							map[i][j] = new Room(3);
						break;
						//set errors as an undefined ID number
						default:
							map[i][j] = new Room(13);
						break;			
					}
				}
				i++;
			} 
			//set to false to avoid executing the loop a second time
			fubar = false;
		}
	}
	
	// Method to create and generate map (Lab 5) (Lab 6)
	public static Room[][] mapGen(int wallChance, int opponentChance) {
		Room[][] map = new Room[20][20];
		Random rndm = new Random();
		//randomize end goal coordinate variables
		int goalX = rndm.nextInt(20);
		int goalY = rndm.nextInt(5) + 15;
		//for printing numbered enemies
		int num = 1;
			
			for (int i = 0; i < map.length; ++i) {
				for (int j = 0; j < map.length; ++j) {
					
					int compareTo = rndm.nextInt(100);
					
					if (i == 0 && j == 0) { //starting player position
						map[i][j] = new Room(1);					
					}
					else if (i == goalY && j == goalX) { //generate goal room
						map[i][j] = new Room(3);
					}
					else if (compareTo < opponentChance) { //generate monsters
						map[i][j] = new Room(2);
						//give vegan's unique names (Lab 8)
						Opponent opponent = new Opponent("Vegan" + num);
						map[i][j].opponent = opponent;
						opponentArray.add(opponent);
						num++;
					}
					else if (compareTo < wallChance + opponentChance) {	
						//generate walls
						map[i][j] = new Room(-1);
					}
					else { //if room is empty 
						map[i][j] = new Room(0);
					}
				}
			}
			return map;
	}
	
	//method to save and exit game (Lab 8)
	public static void saveGame(Room[][] map) throws IOException {
		FileWriter myWriter = new FileWriter("map.txt");
		PrintWriter myPrintWriter = new PrintWriter(myWriter);
		//go through entire 2D map to save each position in the proper format
		for (int i = 0; i < 20; i++) {
			for(int j = 0; j < 20; j++) {
				switch (map[i][j].getID()) {
					case -1: 
						myPrintWriter.print("W"); //save walls to file
					break;
						
					case 0:
						myPrintWriter.print(" "); //save empty spaces to file
					break;
						
					case 1:
						myPrintWriter.print("X"); //save player to file
					break;
					
					case 2:
						myPrintWriter.print("E"); //save enemies to file
					break;
					
					case 3:
						myPrintWriter.print("G"); //save end goal to file
					break;
						
					default:
						myPrintWriter.print("?"); //save errors to file
					break;
				}	
			}
			myPrintWriter.println();
		}
		//close file
		myPrintWriter.close();
	}
	
	// Method for moving character on the map (Lab 6)
    public static void moveCharacter(Player playerCharacter, Room[][] map, 
    	Scanner scnr, Random rndm) throws IOException, InvalidMoveException {
		char moveInput = ' ';
		String smooth = "";
		int i = 0;
		//loop to move player until game exits
		while (true) {
		    //set player character space
		    map[playerCharacter.yPlayerVal]
		       [playerCharacter.xPlayerVal].roomID = 1;
		    //call method to generate and display map to screen
		    displayMap(map);
		    //gets input for motion from user
		    smooth = scnr.nextLine();
		    if (smooth.length() >= 1) {
		    	//moveInput stays the same if just enter key is pressed
		    	moveInput = smooth.charAt(0);
		    }
		    //test to see if Override toString() method works
		    if (moveInput == 'p') {
		    	System.out.print(playerCharacter);
		    }
		    //throw invalid move exception if user enters wrong key
		    if (moveInput != 'w' && moveInput != 'W' && moveInput != 's' && 
		    	moveInput != 'S' && moveInput != 'a' && moveInput != 'A' &&
		    	moveInput != 'd' && moveInput != 'D' && moveInput != 'z' &&
		    	moveInput != 'Z') {
		    	throw new InvalidMoveException();
		    }
			//save and exit game if user chooses
			if(moveInput == 'z' || moveInput == 'Z') {
				saveGame(map);
				System.out.println("Saving game...");
				System.exit(0);
			}
			//moving up	
		    if (moveInput == 'w' || moveInput == 'W') {
					//make sure player cannot move out of bounds
					if (playerCharacter.yPlayerVal == 0) {
							System.out.println("You cannot go that way.");
					}
					//cannot move into a space that is a wall
					else if (map[playerCharacter.yPlayerVal - 1]
					            [playerCharacter.xPlayerVal].roomID == -1) {
							System.out.println("That is a wall. It will not" +
												"move for the likes of you.");
					}
					//this is the part where the battle takes place
					else if (map[playerCharacter.yPlayerVal - 1]
								[playerCharacter.xPlayerVal].roomID == 2) {
							//print opponent's stats
							printToScreen(opponentArray.get(i));
							//fight
							fight(playerCharacter, opponentArray.get(i), rndm);
							//set opponent-occupied space to empty
							map[playerCharacter.yPlayerVal - 1]
							   [playerCharacter.xPlayerVal].roomID = 0;
							//delete vanquished opponent from array
							opponentArray.set(i,null);
							//set player-occupied space to empty
							map[playerCharacter.yPlayerVal]
							   [playerCharacter.xPlayerVal].roomID = 0;
							//move player to opponent's space
							playerCharacter.yPlayerVal -= 1;
							i++;
					}
					else {
						//set player-occupied space to empty
						map[playerCharacter.yPlayerVal]
						   [playerCharacter.xPlayerVal].roomID = 0;
						//move player to empty space
						playerCharacter.yPlayerVal -= 1;
					}
		    }
			//moving right	
		    if (moveInput == 'd' || moveInput == 'D') {
		    		//make sure player cannot move out of bounds
					if (playerCharacter.xPlayerVal + 1 == 20) {
							System.out.println("You cannot go that way.");
					}
					//cannot move into a space that is a wall	
					else if (map[playerCharacter.yPlayerVal]
								[playerCharacter.xPlayerVal + 1].roomID == -1) {
							System.out.println("That is a wall. It will not" +
												"move for the likes of you.");
					}	
					//this is the part where the battle takes place
					else if (map[playerCharacter.yPlayerVal]
								[playerCharacter.xPlayerVal + 1].roomID == 2) {
							//print opponent's stats
							printToScreen(opponentArray.get(i));
							//fight
							fight(playerCharacter, opponentArray.get(i), rndm);
							//set opponent-occupied space to empty
							map[playerCharacter.yPlayerVal]
							   [playerCharacter.xPlayerVal + 1].roomID = 0;
							//delete vanquished opponent from array
							opponentArray.set(i,null);
							//set player-occupied space to empty
							map[playerCharacter.yPlayerVal]
							   [playerCharacter.xPlayerVal].roomID = 0;
							//move player to opponent's space   
							playerCharacter.xPlayerVal += 1;
							i++;
					}
					else {
						//set player-occupied space to empty
		        		map[playerCharacter.yPlayerVal]
		        		   [playerCharacter.xPlayerVal].roomID = 0;
		        		//move player to empty space
		        		playerCharacter.xPlayerVal += 1;
					}
		    }
			//moving down	
		    if (moveInput == 's' || moveInput == 'S') {
		    		//make sure player cannot move out of bounds
					if (playerCharacter.yPlayerVal + 1 == 20) {
							System.out.println("You cannot go that way.");
					}
					//cannot move into a space that is a wall
					else if (map[playerCharacter.yPlayerVal + 1]
								[playerCharacter.xPlayerVal].roomID == -1) {
							System.out.println("That is a wall. It will not" +
												"move for the likes of you.");
					}
					// this is the part where the battle takes place
					else if (map[playerCharacter.yPlayerVal + 1]
								[playerCharacter.xPlayerVal].roomID == 2) {
							//print opponent's stats
							printToScreen(opponentArray.get(i));
							//fight
							fight(playerCharacter, opponentArray.get(i), rndm);
							//set opponent-occupied space to epmty
							map[playerCharacter.yPlayerVal + 1]
							   [playerCharacter.xPlayerVal].roomID = 0;
							//delete vanquished opponent from array
							opponentArray.set(i,null);
							//set player-occupied space to empty
							map[playerCharacter.yPlayerVal]
							   [playerCharacter.xPlayerVal].roomID = 0;
							//move player to opponent's space
							playerCharacter.yPlayerVal += 1;
							i++;
					}
					else {
						//set player-occupied space to empty
						map[playerCharacter.yPlayerVal]
						   [playerCharacter.xPlayerVal].roomID = 0;
						//move player to empty space
						playerCharacter.yPlayerVal += 1;
					}
		    }
			//moving left	
		    if (moveInput == 'a' || moveInput == 'A') {
		    		//make sure player cannot move out of bounds
					if (playerCharacter.xPlayerVal == 0) {
							System.out.println("You cannot go that way.");
					}
					//cannot move into a space that is a wall
					else if (map[playerCharacter.yPlayerVal]
								[playerCharacter.xPlayerVal - 1].roomID == -1) {
							System.out.println("That is a wall. It will not" +
												"move for the likes of you.");
					}
					// this is the part where the battle takes place
					else if (map[playerCharacter.yPlayerVal]
								[playerCharacter.xPlayerVal - 1].roomID == 2) {
							//print opponent's stats
							printToScreen(opponentArray.get(i));
							//fight
							fight(playerCharacter, opponentArray.get(i), rndm);
							//set opponent-occupied space to epmty
							map[playerCharacter.yPlayerVal]
							   [playerCharacter.xPlayerVal - 1].roomID = 0;
							//delete vanquished opponent from array
							opponentArray.set(i,null);
							//set player-occupied space to empty
							map[playerCharacter.yPlayerVal]
							   [playerCharacter.xPlayerVal].roomID = 0;
							//move player to opponent's space
							playerCharacter.xPlayerVal -= 1;
							i++;
					}
					else {
						//set player-occupied space to empty
						map[playerCharacter.yPlayerVal]
						   [playerCharacter.xPlayerVal].roomID = 0;
						//move player to empty space
						playerCharacter.xPlayerVal -= 1;
					}
		    }		
				//end game if player occupies end goal space
		    if (map[playerCharacter.yPlayerVal]
		    	   [playerCharacter.xPlayerVal].roomID == 3) {
		        File endSong = new File("/home/grant/Documents/undClasses"
		        						+ "/Civil");
		        System.out.println("Pizza time!"); //FIXME  
		        //endSong.open();	//FIXME
				System.exit(0);
	      }
		}
	}
	
	//method for BATTLE (Lab 7)
	public static void fight(Player player, Opponent enemy, Random rndm) {
		//looping variable
		boolean dead = false;
		int attackRoll = 0;
		int attackDamage = 0;		
		while (dead != true) {
			//when player attacks first
			if (player.getDexterity() >= enemy.getDexterity()) {
				//generate random D20 attack roll for player attack
				attackRoll = rndm.nextInt(20) + 1;				
				//see if attack hits
				if (attackRoll > (enemy.getArmorClass() + enemy.getModifier
					(enemy.getDexterity()))) {
					//random D6 attack damage
					attackDamage = (rndm.nextInt(6) + 1) + player.getModifier
						(player.getStrength());
					//see if attack does damage
					if (attackDamage <= 0) {
						attackDamage = 0;
						System.out.println(player.getNameOfCharacter() 
							+ "\'s attack missed!");
					}
					else {
						//destroy enemy recursively (Lab 9) 
						enemy.takeDamage(enemy.getHitPoints()); 
						dead = true;
						System.out.println(player.getNameOfCharacter() + 
							" slew the Vegan. They deserve a pizza for their" +
							" skills...");
						break;
					}
				}
				//generate random D20 attack roll for opponent attack
				attackRoll = rndm.nextInt(20) + 1;
				//see if attack hits
				if (attackRoll > (player.getArmorClass() + player.getModifier
					(player.getDexterity()))) {
					//random D6 attack damage
					attackDamage = (rndm.nextInt(6) + 1) + enemy.getModifier
						(enemy.getStrength());
					//see if attack does damage
					if (attackDamage <= 0) {
						attackDamage = 0;
						System.out.println(enemy.getNameOfCharacter() 
							+ " missed their attack!");
					}
					else {
						//do damage to player
						player.setHitPoints(player.getHitPoints()
							- attackDamage);
						//see if player is dead
						if (player.getHitPoints() <= 0) {
							//print damage done to player
							System.out.println(enemy.getNameOfCharacter() 
								+ " hit " + player.getNameOfCharacter() 
								+ " and dealt " + attackDamage + " damage!");
							//print player DEATH
							System.out.println(player.getNameOfCharacter() 
								+ " was slain by the vicious " 
								+ enemy.getNameOfCharacter() + "!");
							//exit game 
							System.exit(0);						
						}
						else {
							//print damage done to player
							System.out.println(enemy.getNameOfCharacter() 
								+ " hit " + player.getNameOfCharacter() 
								+ " and dealt " + attackDamage + " damage!");
						}						
					}
				}
			}
			//when enemy attacks first
			else if (player.getDexterity() < enemy.getDexterity()) {
				//generate random D20 attack roll for opponent attack
				attackRoll = rndm.nextInt(20) + 1;
				//see if attack hits
				if (attackRoll > (player.getArmorClass() 
					+ player.getModifier(player.getDexterity()))) {
					//random D6 attack damage
					attackDamage = (rndm.nextInt(6) + 1) 
						+ enemy.getModifier(enemy.getStrength());
					//see if attack does damage
					if (attackDamage <= 0) {
						attackDamage = 0;
						System.out.println(enemy.getNameOfCharacter() 
							+ " missed their attack!");
					}
					else {
						//do damage to player
						player.setHitPoints(player.getHitPoints() 
							- attackDamage);
						//see if player is dead
						if (player.getHitPoints() <= 0) {
							//print damage done to player
							System.out.println(enemy.getNameOfCharacter() 
								+ " hit " + player.getNameOfCharacter() 
								+ " and dealt " + attackDamage + " damage!");
							//print player DEATH
							System.out.println(player.getNameOfCharacter() 
								+ " was slain by the vicious " 
								+ enemy.getNameOfCharacter() + "!");
							//exit game
							System.exit(0);						
						}
						else {
							//print damage done to player
							System.out.println(enemy.getNameOfCharacter() 
								+ " hit " + player.getNameOfCharacter() 
								+ " and dealt " + attackDamage + " damage!");
						}						
					}
				}
				//generate random D20 attack roll for player attack
				attackRoll = rndm.nextInt(20) + 1;
				//see if attack hits			
				if (attackRoll > (enemy.getArmorClass() 
					+ enemy.getModifier(enemy.getDexterity()))) {
					//random D6 attack damage
					attackDamage = (rndm.nextInt(6) + 1) 
						+ player.getModifier(player.getStrength());
					//see if attack does damage
					if (attackDamage <= 0) {
						attackDamage = 0;
						System.out.println(player.getNameOfCharacter() 
							+ "\'s attack missed!");
					}
					else {
						//destroy enemy recursively (Lab 9) 
						enemy.takeDamage(enemy.getHitPoints());
						dead = true;
						System.out.println(player.getNameOfCharacter() + 
							" slew the Vegan. They deserve a pizza for their" +
							" skills...");
					}
				}
			}
		}
	}
	
	//Generic method for printing objects to the screen (Lab 9)
	public static <MyObject> void printToScreen(MyObject printMe) {
		System.out.println(printMe);
	}
	
	//Main Method
	public static void main(String[] args) throws IOException {
		Scanner scnr = new Scanner(System.in);
		Random rndm = new Random();
		
		//create new map array
		Room[][] map = new Room[20][20]; 
		String userChoice = "";  
		String userName = "";     
        		
		while(true) {
			// create wall variable and opponent variable (Lab 5)
			int wallChance = 25;
			int opponentChance = 5;
			//call main menu method (Lab 8)
			char getUserIn = mainMenu(scnr);
			//create new player character
							//System.out.println("Enter your character's name: ");
							//userName = scnr.nextLine();
			Player playerCharacter = new Player(userName);
			//convert user-entered char to a string
			String userIn = "" + getUserIn;
			//create new game
			if (userIn.equalsIgnoreCase("N")) {
				//set player name to user input
				System.out.println("Enter your character's name: ");
				userName = scnr.nextLine();
				playerCharacter.setName(userName);
				//call method to create and generate map (Lab 5)
				map = mapGen(wallChance, opponentChance);
				//print new player character stats
				printToScreen(playerCharacter);
			}
			//load existing game
			else if (userIn.equalsIgnoreCase("L")) {
				//set player name to user input
				System.out.println("Enter your character's name: ");
				userName = scnr.nextLine();
				playerCharacter.setName(userName);
				//call method to load map from file (Lab 8)
				loadMap(playerCharacter, map);
				//print loaded character stats FIXME also save character stats
				printToScreen(playerCharacter);
			}
			else {
				//if user enters incorrect input
				System.out.println("Invalid input.");
				//ask user if they want to go back to main menu or exit game
				System.out.println("Main menu? (Press 'Y' for Menu," 
					+ " any other key to quit).");
				userChoice = scnr.nextLine();
				//restart loop to go back to main menu
				if (userChoice.equalsIgnoreCase("Y")) {
					continue;
				}
				//exit game
				else {
					System.exit(0);
				}				
			}
			//play game
			while(true) {
				try {
					// call method to move player and begin gameplay (Lab 6)
					moveCharacter(playerCharacter, map, scnr, rndm);	
				}
				catch (InvalidMoveException e) {
					e.printStackTrace();
				}
			}
		}
	}
}
