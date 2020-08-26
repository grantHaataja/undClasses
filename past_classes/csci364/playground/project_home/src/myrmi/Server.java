package myrmi;

import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class Server extends UnicastRemoteObject implements Hello {
	public Server() throws RemoteException {
}

@Override 
public String sayHello(String name) throws RemoteException {
	if (name == null) {
		name = "world";
	}
	return "Hello, " + name;
}

	public static void main(String[] args) {
		if (System.getSecurityManager() == null) {
			System.setSecurityManager(new SecurityManager());
		}
		
		try {
			Hello obj = new Server();
			Naming.rebind("Hello", obj);

			System.out.println("Server ready");
		} catch (Exception re) {
			re.printStackTrace();
		}
	}
}

