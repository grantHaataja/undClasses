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
            while((fileLine = br.readLine()) != null)
                System.out.println(fileLine);
		} catch (IOException e) {
			System.err.println(e);
		}
		

	}
}
