//Grant Haataja
//In-Class Exercise

import java.net.*;
import java.io.*;
import javax.net.ssl.*;

public class SecureServer {
    public static void main(String[] args) throws IOException {
       if (args.length != 1) {
            System.err.println("Specify a port number.");
            System.exit(1);
        }
        
        int portNumber = Integer.parseInt(args[0]);
        
        SSLServerSocketFactory factory = 
        	(SSLServerSocketFactory)SSLServerSocketFactory.getDefault();
        
        try {
            SSLServerSocket serverSocket = 
            	(SSLServerSocket)factory.createServerSocket(portNumber);

            System.out.println("The server is listening at: " + 
                    serverSocket.getInetAddress() + " on port " + 
                    serverSocket.getLocalPort());

            SSLSocket clientSocket = (SSLSocket)serverSocket.accept();  
               
            PrintWriter out =
                new PrintWriter(clientSocket.getOutputStream(), true);                   
            BufferedReader in = new BufferedReader(
                new InputStreamReader(clientSocket.getInputStream()));

            String inputLine;
            while ((inputLine = in.readLine()) != null) {
                System.out.println("I received: " + inputLine);

                out.println(inputLine.toUpperCase());
            }
        } catch (IOException e) {
            System.out.println("Exception caught when trying to listen on port "
                + portNumber + " or listening for a connection");
            System.out.println(e.getMessage());
        }
    }
}
