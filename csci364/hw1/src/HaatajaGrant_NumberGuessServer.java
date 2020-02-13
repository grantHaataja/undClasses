//CSCI364 Assignment 1 Server
//Grant Haataja

import java.util.Random;
import java.net.ServerSocket;
import java.net.Socket;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class HaatajaGrant_NumberGuessServer {
	public static void main(String[] args) {
		//verify user-entered arguments
		if ((args.length != 2) || Integer.parseInt(args[0]) <= 0 || 
			Integer.parseInt(args[1]) <= 0) {
			System.err.println("Usage: java HaatajaGrant_NumberGuessServer" + 
				" <port number> <maximum value>");
			System.exit(0);
		}
		//declare the port number
		int portNumber = Integer.parseInt(args[0]);
		
		//select random target integer
		Random randy = new Random();
		int target = randy.nextInt(Integer.parseInt(args[1]));
		
		//server outer loop
		while (true) {
		
			try {
				//make new serverSocket object
				ServerSocket serverSocket = new ServerSocket(portNumber);
			
				System.out.println("NumberGuessServer is listening at: " + 
					serverSocket.getInetAddress() + " on port " + 
					serverSocket.getLocalPort());
			
				//wait for client	
				Socket clientSocket = serverSocket.accept();
			
				//set up PrintWriter stuff
				PrintWriter out = 
					new PrintWriter(clientSocket.getOutputStream(), true);
				BufferedReader in = new BufferedReader(
					new InputStreamReader(clientSocket.getInputStream()));
			
				//send welcome message
				out.println("Welcome to the High-Low Guessing Game.\n");
				out.println("Enter an integer greater than 0 and less than " + 
					Integer.parseInt(args[1]) + ".\n");
			
				//after receiving response from client, check against target
				String input;
				int guesses = 0;
				while ((input = in.readLine()) != null) {
					System.out.println("Server received: " + input);
					int number = -1;
					try {
						number = Integer.parseInt(input);
					} catch (Exception e) {
						System.err.println("Invalid input: Enter an integer.");
					}
					//do the checking
					if (number < target) {
						out.println("Guess higher.");
						guesses++;
					}
					else if (number > target) {
						out.println("Guess lower.");
						guesses++;
					}
					else {
						guesses++;
						out.println("You are correct! It took you " + guesses +
							" guesses.");
						serverSocket.close();
						clientSocket.close();
						break;
					}
				}
							
			} catch (IOException e) {
				System.err.println("Oops");
			}
		}
	}
}
