/**
 * VolunteerComputingClient.java
 */
package Client;

import java.util.List;
import java.util.Random;
import java.rmi.Naming;
import api.Worker;
import api.ClientManager;

/**
 * @author grant haataja
 *
 */
public abstract class VolunteerComputingClient implements api.ClientManager
{
	/**
	 * Main function to run the Client 
	 * @param args 
	 */
	public static void main(String[] args) 
	{
		String rmiHost = "";
		int rmiPort = -1;
		float clientScore = -1.0f;
		String userID = "";
		Random randy = new Random();
		
		//verify user-entered arguments
		if (args.length == 0) {
			System.err.println("Usage: java VolunteerComputingClient " + 
				"<client userID> <host name> <port>");
			System.exit(0);
		}
		else if (args.length == 1) {
			userID = args[0];
			rmiHost = "localhost";
			rmiPort = 1099;
		}
		else if (args.length == 2) {
			userID = args[0];
			rmiHost = args[1];
			rmiPort = 1099;
		}
		else if (args.length == 3) {
			userID = args[0];
			rmiHost = args[1];
			rmiPort = Integer.parseInt(args[2]);
		}
		else {
			System.err.println("Usage: java VolunteerComputingClient " + 
				"<client userID> <host name> <port>");
			System.exit(0);
		}
		
		try {
			System.out.println();
			//lookup RemoteObject from RMI registry
			ClientManager currentClient = (ClientManager) Naming.lookup("rmi://" + 
				rmiHost + ":" + rmiPort + "/ClientManager");
			
			//register with remote object
			List<String> taskList = currentClient.register(userID);
			
			//print the list of task names
			System.out.println("Available work tasks are: " + taskList);
			
			//enter loop to request work five times
			for (int i = 0; i < 5; i++) {
				int randomChoice = randy.nextInt(4);
				switch (randomChoice) {
					case 0:
						System.out.println("Requesting work task for " + 
							taskList.get(0) + "...");
						//request the work
						Worker sw = currentClient.requestWork(userID, taskList.get(0));
						//complete work task
						sw.doWork();
						//submit the worker task object back to RemoteObject
						currentClient.submitResults(userID, sw);
						//request running score and print it
						clientScore = currentClient.getScore(userID);
						System.out.println("This is client " + userID +
							" with a score of " + clientScore + ".");
						break;
					case 1:
						System.out.println("Requesting work task for " +
							taskList.get(1) + "...");
						Worker sr = currentClient.requestWork(userID, taskList.get(1));
						sr.doWork();
						currentClient.submitResults(userID, sr);
						clientScore = currentClient.getScore(userID);
						System.out.println("This is client " + userID +
							" with a score of " + clientScore + ".");						
						break;
					case 2:
						System.out.println("Requesting work task for " +
							taskList.get(2) + "...");
						Worker pc = currentClient.requestWork(userID, taskList.get(2));
						pc.doWork();
						currentClient.submitResults(userID, pc);
						clientScore = currentClient.getScore(userID);
						System.out.println("This is client " + userID +
							" with a score of " + clientScore + ".");
						break;
					case 3:
						System.out.println("Requesting work task for " +
							taskList.get(3) + "...");
						Worker fr = currentClient.requestWork(userID, taskList.get(3));
						fr.doWork();
						currentClient.submitResults(userID, fr);
						clientScore = currentClient.getScore(userID);
						System.out.println("This is client " + userID +
							" with a score of " + clientScore + ".");
						break;
					default:
						System.err.println("Task not found.");
						break;
				}
			}
		} catch (Exception e) {
			System.err.println(e);
		}
		System.out.println();
	}
}
