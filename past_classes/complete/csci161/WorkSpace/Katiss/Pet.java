import java.util.Scanner;

public class Pet {
	
	//method to get input and calculate score for contestants
		public static int getScore(Scanner scn) {
			int score1 = scn.nextInt();
			int score2 = scn.nextInt();
			int score3 = scn.nextInt();
			int score4 = scn.nextInt();
			
			return (score1 + score2 + score3 + score4);
		
		}	
	
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		
		//declare variables for each of the 5 players
		int player1 = getScore(scn);
		int player2 = getScore(scn);
		int player3 = getScore(scn);
		int player4 = getScore(scn);
		int player5 = getScore(scn);
		int[] player = new int[] {player1, player2, player3, player4, player5};
		int winner =  player[0];
		int playerNum = 1;
		
		if (player1 == player2 && player2 == player3 && player3 == player4 && player4 == player5) {
			System.out.print("1 " + player1);
		}
		else {
			//compare player scores to find the winning player
			for (int i = 1; i < player.length; i++) {
				if (winner < player[i]) {
					winner = player[i];
					playerNum = i+1;
				}
			}
		
			//print output
			System.out.print(playerNum + " " + winner);
		}
	
	}
}
