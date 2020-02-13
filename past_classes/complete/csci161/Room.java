/* Lab 7
 * Name: Grant Haataja
 * Date: 10/17/18
 */
public class Room {
	
	//public global variables
	int roomID = 0;
	public Character opponent;
	
	//constructor to set ID number for each space on map
	public Room(int ID) {
		roomID = ID;
	}
	
	//FIXME add toString() method to display room information?
	
	//method to get ID number for each space on map for generating map
	public int getID() {
		return roomID;
	}
}
