/**
 * ClientManager.java
 */
package api;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.List;

/**
 * @author david apostal
 *
 */
public interface ClientManager extends Remote {
	/**
	 * The String that identifies the remote object.
	 */
	public static final String REMOTE_OBJECT = "ClientManager";
	
	/**
	 * Registers a client with the volunteer computing server.
	 * 
	 * @param userid the client name
	 * @return a List of available work task names. The names are unique.
	 * @throws RemoteException 
	 */
	public List<String> register(String userID) throws RemoteException;
	
	/**
	 * Requests work from the server.
	 * 
	 * @param userID the client requesting work
	 * @param taskName the project name
	 * @return a Worker object that can perform
	 * @throws RemoteException if userID is unknown or if taskName does not
	 * exist.
	 */
	public Worker requestWork(String userID, String taskName) throws RemoteException;

	/**
	 * Submits work results from a volunteer to the server.
	 * 
	 * @param userID the client submitting results
	 * @param answer the completed Worker
	 * @throws RemoteException if userID is unknown or if an invalid Worker is
	 * submitted to the remote object
	 */
	public void submitResults(String userID, Worker answer) throws RemoteException;
	
	/**
	 * Gets the score for a specified client.
	 * 
	 * @param userID the client name
	 * @return the client's current score
	 * @throws RemoteException if userID is unknown
	 */
	public float getScore(String userID) throws RemoteException;
}
