//CSCI364 Assignment 1 Client
//Grant Haataja

import java.util.Random;
import java.net.ServerSocket;
import java.net.Socket;
import java.io.IOException;
import java.net.UnknownHostException;
import java.io.PrintWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class HaatajaGrant_NumberGuessClient {
	public static void main(String[] args) {
		//verify user-entered arguments
		if ((args.length != 2) || Integer.parseInt(args[1]) <= 0) {
			System.err.println("Usage: java HaatajaGrant_NumberGuessClient" + 
				" <host name> <port number>");
			System.exit(0);
		}
		
		String hostName = args[0];
		int portNumber = Integer.parseInt(args[1]);
		
		try {
			//make new Socket object and connect to the server
			Socket guessSocket = new Socket(hostName, portNumber);
			
			//set up PrintWriter stuff
			PrintWriter out = 
				new PrintWriter(guessSocket.getOutputStream(), true);
			BufferedReader in = new BufferedReader(
				new InputStreamReader(guessSocket.getInputStream()));
			BufferedReader stdIn = new BufferedReader(
				new InputStreamReader(System.in));
			
			//print welcome message
			System.out.println(in.readLine());
			System.out.println(in.readLine());
			System.out.println(in.readLine());
			System.out.println(in.readLine());
			
			String userInput;
			String temp;
			while ((userInput = stdIn.readLine()) != null) {
				out.println(userInput);
				temp = in.readLine();
				if (temp.contains("correct")) {
					System.out.println(temp);
					System.exit(0);
				}
				else {
					System.out.println(temp);
				}	
			}
			//catch exceptions because I can't catch a ball
		} catch (UnknownHostException e) {
			System.err.println("Couldn't find host " + hostName);
			System.exit(0);
		} catch (IOException e) {
			System.err.println("Input/Output failure for connection to " + 
				hostName);
			System.exit(0);
		} 
	
	}
}
