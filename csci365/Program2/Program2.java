//Grant Haataja
//CSCI 365 Program2

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;

public class Program2 
{
	public static void main(String[] args) throws IOException 
	{
		if (args.length != 1) {
			System.out.println("Improper parameters. Usage: java Program2 [fileName]");
			System.exit(0);
		}
		String fileName = args[0];
		
		try {
			BufferedReader br = new BufferedReader(new FileReader(new File(fileName)));     
			String fileLine = null;
			//this is where we begin parsing the file content
            while((fileLine = br.readLine()) != null) {
				//check for comment lines
				if (fileLine.startsWith("#")) {
					continue;
				}
				//split the file line into individual tokens
				String[] splited = fileLine.split("\\s+");
				//now loop through the line to analyze tokens one at a time
				for (int i = 0; i < splited.length; i++) {
					//see if the token is an empty string
					if (splited[i].isEmpty()) {
						continue;
					}					
					//see if the token is a reserved word
					if (splited[i].matches("\\b(input|print|begin|end|if|else)\\b")) {
						System.out.println("<" + splited[i] + ">, " + splited[i]);
					}
					//see if token is the assign token
					else if (splited[i].equals("=")) {
						System.out.println("<assign>, " + splited[i]);
					}
					//see if token is a relational operator
					else if (splited[i].matches("([<>]=?|==|!=)")) {
						System.out.println("<rel_op>, " + splited[i]);
					}
					//see if token is a number
					else if (splited[i].matches("([+|-]?)(\\d+)(\\.\\d+)?")) {
						System.out.println("<number>, " + splited[i]);
					}
					//see if token is an id
					else if (splited[i].matches("([a-zA-Z])+([a-zA-Z0-9])*")) {
						System.out.println("<id>, " + splited[i]);
					}
					//otherwise print an error
					else {
						System.out.println("<error>, " + splited[i]);
						System.exit(0);
					}
				}
								
			}
		} catch (IOException e) {
			System.err.println(e);
		}
		

	}
}
