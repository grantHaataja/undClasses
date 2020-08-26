import java.util.*;

public class SevenWonders { 
    public static void main(String[] args) {
    Scanner scnr = new Scanner(System.in);
    
        //get input and declare variables
        String playerCards = scnr.nextLine();
        int numTablets = 0;
        int numCompasses = 0;
        int numGear = 0;
        int playerScore = 0;
    
        //loop to calculate number of cards
        for (int i = 0; i < playerCards.length(); ++i)  {
            if (playerCards.charAt(i) == 'T') {
                ++numTablets;
            }
            if (playerCards.charAt(i) == 'C') {
                ++numCompasses;
            }
            if (playerCards.charAt(i) == 'G') {
                ++numGear;
            }
        }   
        //declare counting variables to count combos
        int countT = numTablets;
        int countC = numCompasses;
        int countG = numGear;
        int numCombos = 0;
        
        //loop to calculate number of combos
        while (countT != 0 && countC != 0 && countG != 0) {
            --countT;
            --countC;
            --countG;
            ++numCombos;
        }
        //calculate and output player score
        playerScore = ((int)Math.pow(numTablets, 2) + (int)Math.pow(numCompasses, 2) + 
        (int)Math.pow(numGear, 2)) + numCombos * 7;
        System.out.print(playerScore); 
    }

}
