/**
 * RemoteObject.java
 */
package server;

import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;
import java.util.Random;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import api.Worker;

/**
 * @author grant haataja
 *
 */
public class RemoteObject extends UnicastRemoteObject implements api.ClientManager
{
	private float score = 0.0f;
	private int instanceID = 0;
	private HashMap<String, Float> clients = new HashMap<>();
	private HashMap<Integer, String> taskIDtoInput = new HashMap<>();
	private HashMap<Integer, String> taskIDtoTaskName = new HashMap<>();
	private HashMap<Integer, String> taskIDtoTaskOutput = new HashMap<>();
	Random randy = new Random();
	
	RemoteObject() throws RemoteException
	{
		super();
	}
	
	/**
	 * Registers a client with the volunteer computing server.
	 * 
	 * @param userID the client name
	 * @return a List of available work task names. The names are unique.
	 * @throws RemoteException 
	 */
	public List<String> register(String userID) throws RemoteException
	{	
		List<String> workTasks = new ArrayList<String>();
		workTasks.add("SortWorker");
		workTasks.add("SumReducer");
		workTasks.add("PrimeChecker");
		workTasks.add("FractionReducer");
		
		//add the client who is registering to the clients hashmap
		if (!clients.containsKey(userID)) {
			clients.put(userID, 0.0f);
		}
		//print all client names and their scores
		System.out.println();
		System.out.println("List all current clients and their scores:");
		for (HashMap.Entry<String,Float> entry : clients.entrySet())  
            System.out.println(entry.getKey() + ": " + entry.getValue()); 
		
		return workTasks;
	}
	
	/**
	 * Requests work from the server.
	 * 
	 * @param userID the client requesting work
	 * @param taskName the type of worker 
	 * @return a Worker object that can perform
	 * @throws RemoteException if userID is unknown or if taskName does not
	 * exist
	 */
	public Worker requestWork(String userID, String taskName) throws RemoteException
	{
		switch(taskName) {
			case "SortWorker":
				List<Integer> arr = new ArrayList<Integer>();
				for (int i = 0; i < 5; i++)
					arr.add(randy.nextInt(1000) + 1);
				SortWorker<Integer> boi = 
					new SortWorker<Integer>(instanceID, arr.toArray(new Integer[0]));
				instanceID++;
				//upkeep
				taskIDtoTaskName.put(boi.getTaskId(), boi.getTaskName());
				taskIDtoInput.put(boi.getTaskId(), arr.toString());				
				return boi;
			case "SumReducer":
				List<Double> rarr = new ArrayList<Double>();
				for (int i = 0; i < 5; i++)
					rarr.add(randy.nextDouble() * 1000.0 + 1.0);				
				SumReducer grl = 
					new SumReducer(instanceID, rarr.toArray(new Double[0]));
				instanceID++;
				//upkeep
				taskIDtoTaskName.put(grl.getTaskId(), grl.getTaskName());
				taskIDtoInput.put(grl.getTaskId(), rarr.toString());
				return grl;
			case "PrimeChecker":
				int val = randy.nextInt(1000000) + 1;
				PrimeChecker non = new PrimeChecker(instanceID, val);
				instanceID++;
				//upkeep
				taskIDtoTaskName.put(non.getTaskId(), non.getTaskName());
				taskIDtoInput.put(non.getTaskId(), val+"");
				return non;
			case "FractionReducer":
				val = randy.nextInt(1000) + 1;
				int vall = randy.nextInt(1000) + 1;
				String input = val + " / " + vall;
				FractionReducer bin = new FractionReducer(instanceID, val, vall);
				instanceID++;
				//upkeep
				taskIDtoTaskName.put(bin.getTaskId(), bin.getTaskName());
				taskIDtoInput.put(bin.getTaskId(), input);
				return bin;
			default:
				System.err.println("Improper Worker Specified.");
				return null;
		}
	}
	
	/**
	 * Submits work results from a volunteer to the server.
	 * 
	 * @param userID the client submitting results
	 * @param answer the Worker after completing work
	 * @throws RemoteException if userID is unknown or if an invalid Worker is
	 * submitted to the remote object
	 */
	public void submitResults(String userID, Worker answer) throws RemoteException
	{
		//check what kind of worker this instance is
		if (answer instanceof SortWorker) {
			//cast the worker as SortWorker and call getResult method
			SortWorker<Integer> sw = (SortWorker<Integer>) answer;
			List<Integer> result = sw.getResult();
			//add the result to the hashmap of tasks to results
			taskIDtoTaskOutput.put(answer.getTaskId(), result.toString());
			//print all inputs and results for all instances of SortWorker
			System.out.println("\nListed below are all the inputs and results " +
				"for SortWorker tasks.");
			for (HashMap.Entry<Integer,String> entry : taskIDtoTaskOutput.entrySet()) {
				if (taskIDtoTaskName.get(entry.getKey()) == "SortWorker") {
					System.out.println("Task ID: " + entry.getKey());
					System.out.println("\tInput: " + taskIDtoInput.get(entry.getKey()));
					System.out.println("\tResult: " + entry.getValue());
				}
			}
		}
		else if (answer instanceof SumReducer) {
			SumReducer sr = (SumReducer) answer;
			String result = sr.getResult();
			taskIDtoTaskOutput.put(answer.getTaskId(), result);
			//print all inputs and results for all instances of SumReducer
			System.out.println("\nListed below are all the inputs and results " +
				"for SumReducer tasks.");
			for (HashMap.Entry<Integer,String> entry : taskIDtoTaskOutput.entrySet()) {
				if (taskIDtoTaskName.get(entry.getKey()) == "SumReducer") {
					System.out.println("Task ID: " + entry.getKey());
					System.out.println("\tInput: " + taskIDtoInput.get(entry.getKey()));
					System.out.println("\tResult: " + entry.getValue());
				}
			}
		}
		else if (answer instanceof PrimeChecker) {
			PrimeChecker pc = (PrimeChecker) answer;
			String result = pc.getResult();
			taskIDtoTaskOutput.put(answer.getTaskId(), result);
			//print all inputs and results for all instances of PrimeChecker
			System.out.println("\nListed below are all the inputs and results " +
				"for PrimeChecker tasks.");
			for (HashMap.Entry<Integer,String> entry : taskIDtoTaskOutput.entrySet()) {
				if (taskIDtoTaskName.get(entry.getKey()) == "PrimeChecker") {
					System.out.println("Task ID: " + entry.getKey());
					System.out.println("\tInput: " + taskIDtoInput.get(entry.getKey()));
					System.out.println("\tResult: " + entry.getValue());
				}
			}
		}
		else if (answer instanceof FractionReducer) {
			FractionReducer fr = (FractionReducer) answer;
			String result = fr.getResult();
			taskIDtoTaskOutput.put(answer.getTaskId(), result);
			//print all inputs and results for all instances of FractionReducer
			System.out.println("\nListed below are all the inputs and results " +
				"for FractionReducer tasks.");
			for (HashMap.Entry<Integer,String> entry : taskIDtoTaskOutput.entrySet()) {
				if (taskIDtoTaskName.get(entry.getKey()) == "FractionReducer") {
					System.out.println("Task ID: " + entry.getKey());
					System.out.println("\tInput: " + taskIDtoInput.get(entry.getKey()));
					System.out.println("\tResult: " + entry.getValue());
				}
			}
		}
		else {
			System.err.println("Received unknown Worker object from client.");
			System.exit(0);
		}
		//update the client's score
		if (clients.containsKey(userID))
			clients.put(userID, clients.get(userID) + 1.0f);
		else {
			System.err.println("No client found in database.");
			System.exit(0);
		}
	}
	
	/**
	 * Gets the score for a specified client
	 * 
	 * @param userID the client name
	 * @return the client's current score
	 * @throws RemoteException if userID is unknown
	 */
	public float getScore(String userID) throws RemoteException
	{		
		return clients.get(userID);
	}
}
