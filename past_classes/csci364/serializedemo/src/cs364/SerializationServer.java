/**
 * 
 */
package cs364;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * @author david
 *
 */
public class SerializationServer {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		if (args.length != 1) {
			System.err.println("java SerializationServer <port number>");
			System.exit(1);
		}
		
		int portNumber = Integer.parseInt(args[0]);
		
		try {
			ServerSocket serverSocket = new ServerSocket(portNumber);
			String msg = "The server is listening at ";
			msg += serverSocket.getInetAddress() + " on port " + portNumber;
			System.out.println(msg);
			
			Socket socket = serverSocket.accept();
			ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
			ObjectInputStream in = new ObjectInputStream(socket.getInputStream());
			
			CustomerInformation ciIn = (CustomerInformation)in.readObject();
			System.out.println("Received customer information: " + ciIn);
			
			ciIn.id = ciIn.id * 2;
			ciIn.name = ciIn.name.toUpperCase();
			
			out.writeObject(ciIn);
			
			SingletonExample se1 = (SingletonExample)in.readObject();
			System.out.println("inside server after readObject");
			out.writeObject(se1);
			System.out.println("inside server after writeObject");
		} catch(IOException e) {
			e.printStackTrace();
		} catch(ClassNotFoundException e) {
			e.printStackTrace();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}

}
