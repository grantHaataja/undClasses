/**
 * VolunteerComputingServer.java
 */
package server;

import java.rmi.registry.LocateRegistry;
import java.rmi.Naming;
import api.ClientManager;

/**
 * @author grant haataja
 *
 */
public class VolunteerComputingServer
{
	/**
	 * Main function to run the server 
	 * @param args 
	 */
	public static void main(String[] args) 
	{
		String rmiHost = "";
		int rmiPort = -1;
		
		//verify user-entered arguments
		if (args.length == 0) {
			rmiHost = "localhost";
			rmiPort = 1099;
		}
		else if (args.length == 1) {
			rmiHost = args[0];
			rmiPort = 1099;
		}
		else if (args.length == 2) {
			rmiHost = args[0];
			rmiPort = Integer.parseInt(args[1]);
		}
		else {
			System.err.println("Usage: java VolunteerComputingServer " + 
				"<host name> <port>");
			System.exit(0);
		}
		
		//set up the remote registry 
		try { 
            //print welcome message
			System.out.println("~Starting the Volunteer Computing Server~");

			//create an object of the interface implementation class 
            ClientManager obj = new RemoteObject(); 
  
            //rmiregistry within the server JVM with port number rmiPort 
            LocateRegistry.createRegistry(rmiPort); 
  
            //binds the remote object by the name ClientManager 
            Naming.rebind("rmi://" + rmiHost + ":" + rmiPort + "/ClientManager",obj);
			
        } catch(Exception ae) { 
            System.err.println(ae);
        } 		
	}
}
