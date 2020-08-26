/* Lab 10
 * Name: Grant Haataja
 * Date: 11/14/18
 */
import java.util.*;

public class NewDriver {
	public static void main(String[] args) {
		
		//create new linked list of characters
		LinkedList<NewCharacter> characterList = new LinkedList<NewCharacter>();
		
		//create queue and deque
		Queue<NewCharacter> pleaseHold = new LinkedList<NewCharacter>();
		Deque<NewCharacter> yourCallIsImportantToUs = new LinkedList<NewCharacter>();
		
		//create and add 10 characters to list
		NewCharacter themis = new NewCharacter("Themis");
		characterList.add(themis);
		NewCharacter atlas = new NewCharacter("Atlas");
		characterList.add(atlas);
		NewCharacter prom = new NewCharacter("Prometheus");
		characterList.add(prom);
		NewCharacter hecate = new NewCharacter("Hecate");
		characterList.add(hecate);
		NewCharacter epim = new NewCharacter("Epimetheus");
		characterList.add(epim);
		NewCharacter meno = new NewCharacter("Menoetius");
		characterList.add(meno);
		NewCharacter hype = new NewCharacter("Hyperion");
		characterList.add(hype);
		NewCharacter theia = new NewCharacter("Theia");
		characterList.add(theia);
		NewCharacter iape = new NewCharacter("Iapetus");
		characterList.add(iape);
		NewCharacter crius = new NewCharacter("Crius");
		characterList.add(crius);
		
		int count = 1;
		
		//for loop to print stats of each character
		for (NewCharacter characterName : characterList) {
			System.out.println(characterName);
			if (count % 2 == 0) {
				pleaseHold.add(characterName);
			}
			else {
				yourCallIsImportantToUs.add(characterName);
			}
			count++;
		}
		
		//for loop to display contents of queue
		System.out.println("Contents of Queue: ");
		System.out.println();		
		for (NewCharacter characterName : pleaseHold) {
			System.out.println(characterName);
		}
		//for loop to display contents of deque
		System.out.println("Contents of Deque: ");
		System.out.println();
		for (NewCharacter characterName : yourCallIsImportantToUs) {
			System.out.println(characterName);
		}
		
		//remove 3 characters from the queue
		pleaseHold.poll();
		pleaseHold.poll();
		pleaseHold.poll();
		
		//for loop to display contents of queue
		System.out.println("New Contents of Queue: ");
		System.out.println();	
		for (NewCharacter characterName : pleaseHold) {
			System.out.println(characterName);
		}
		
		//remove first character from deque, then the last 2 characters
		yourCallIsImportantToUs.pollFirst();
		yourCallIsImportantToUs.pollLast();
		yourCallIsImportantToUs.pollLast();
		
		//for loop to display contents of deque
		System.out.println("New Contents of Deque: ");
		System.out.println();
		for (NewCharacter characterName : yourCallIsImportantToUs) {
			System.out.println(characterName);
		}
	
	}
}
