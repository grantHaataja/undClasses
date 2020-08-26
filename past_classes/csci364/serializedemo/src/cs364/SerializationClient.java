/**
 * 
 */
package cs364;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.net.UnknownHostException;

/**
 * @author david
 *
 */
public class SerializationClient {

	/**
	 * 
	 */
	public SerializationClient() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		if (args.length != 4) {
			String msg = "Usage: java SerializationClient <host> <port>";
			msg += "<client name> <client id>";
			System.err.println(msg);
			System.exit(1);
		}
		
		String hostName = args[0];
		int portNumber = Integer.parseInt(args[1]);
		
		try {
			Socket socket = new Socket(hostName, portNumber);
			ObjectOutputStream out = 
					new ObjectOutputStream(socket.getOutputStream());
			ObjectInputStream in = 
					new ObjectInputStream(socket.getInputStream());
			
			int custId = Integer.parseInt(args[3]);
			CustomerInformation ciOut = new CustomerInformation(args[2], custId);
			out.writeObject(ciOut);
			CustomerInformation ciIn = (CustomerInformation)in.readObject();			
			System.out.println("Received: " + ciIn);

			SingletonExample x1 = SingletonExample.getInstance();
			System.out.println("Sending: " + x1);
			out.writeObject(x1);
			
			SingletonExample x2 = (SingletonExample)in.readObject();
			System.out.println("Received back: " + x2);	
			
			//test to see if x1 is the same as x2
			if (x1 == x2) {
				System.out.println("Comparison: True");
			}
			System.out.println("Hash code for x1: " + x1.hashCode());
			System.out.println("Hash code for x2: " + x2.hashCode());
					
		} catch(UnknownHostException e) {
			e.printStackTrace();
		} catch(IOException e) {
			e.printStackTrace();
		} catch(ClassNotFoundException e) {
			e.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
