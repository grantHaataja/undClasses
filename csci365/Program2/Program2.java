import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;

public class Program2 {
	public static void main(String[] args) throws IOException {
		String fileName = args[0];
		
		try {
			File f = new File(fileName);     
			System.out.println("File name: " + f.getName());
			System.out.println("Is writeable: " + f.canWrite());
			System.out.println("Is readable: " + f.canRead());
			System.out.println("Is a directory: " + f.isDirectory());
			System.out.println("File size in bytes: " + f.length());
		} catch (FileNotFoundException e) {
			System.err.println(e);
		}
	
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		

	}
}
