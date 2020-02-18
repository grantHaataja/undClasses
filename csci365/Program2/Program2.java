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
		String[] reserved = new String[]{"input", "print", "begin", "end", "if", "else"};
		String[] relOp = new String[]{"<", ">", "<=", ">=", "==", "!="};
		
		try {
			BufferedReader br = new BufferedReader(new FileReader(new File(fileName)));     
			String fileLine = null;
			//this is where we begin parsing the file content
            while((fileLine = br.readLine()) != null) {
                //fileLine = br.readLine();
				if (fileLine.charAt(0) == '#') {
					continue;
				}
				//split the file line into individual tokens
				String[] splited = fileLine.split("\\s+");
				//now loop through the line to analyze tokens one at a time
				for (int i = 0; i < splited.length; i++) {
					//see if the token is a reserved word
					for (int j = 0; j < reserved.length; j++) {
						if (splited[i].equals(reserved[j])) {
							System.out.println("<" + reserved[j] + ">, " + reserved[j]);
						}
					}
					//see if token is the assign token
					if (splited[i].equals("=")) {
						System.out.println("<assign>, " + splited[i]);
					}
					//see if token is a relational operator
					for (int k = 0; k < relOp.length; k++) {
						if (splited[i].equals(relOp[k])) {
							System.out.println("<rel_op>, " + relOp[k]);
						}
					}
					//see if token is a number
					if (splited[i].matches("(\\d+)(\\.\\d+)?")) {
						System.out.println("<number>, " + splited[i]);
					}
				}
								
			}
		} catch (IOException e) {
			System.err.println(e);
		}
		

	}
}
