//CSCI 364 Assignment II Deposit Runnable
//Grant Haataja

import java.lang.Runnable;
import java.lang.Thread;
import java.lang.InterruptedException;
import java.util.concurrent.ThreadLocalRandom;

public class DepositRunnable implements Runnable 
{
	private Account myAcc;
	private int limit;
	private int totalDeposited = 0;
	private int numDeposits = 0;
	private int numWaits = 0;
	private String name;
	
	//constructor
	public DepositRunnable(Account account, int num) 
	{
		myAcc = account;
		name = "Deposit Thread " + num;
	}
	
	//run method
	public void run() 
	{
		//find max value the account can get to
		limit = myAcc.getAccountBalance() * 2;
		System.out.println("Running Deposit thread...\n");
		while(true) {
			int amount = ThreadLocalRandom.current().nextInt(1, 100);
		
			//check to see if balance is okay
			if ((myAcc.getAccountBalance() + amount) < limit) {
				myAcc.setAccountBalance(myAcc.getAccountBalance() + amount);
				totalDeposited += amount;
				numDeposits++;
			}
			else {
				System.out.println("Amount would exceed account limit.");
			}
			
			//check to see if thread has been interrupted
			try {
				Thread.sleep(1000);
				//if (Thread.interrupted()) {
				//	break;
				//}
			} catch (InterruptedException e) {
				System.err.println(e);
				break;
			}
			
		}
		//print thread info after being interrupted
		System.out.println("I am " + name + ".");
		System.out.println("I deposited $" + totalDeposited + ".");
		System.out.println("I made " + numDeposits + " deposits.");
		System.out.println("I had to wait " + numWaits + " times on account condition.");	
	}
}