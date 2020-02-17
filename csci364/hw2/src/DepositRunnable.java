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
	public DepositRunnable(Account account, int num, int balance) 
	{
		myAcc = account;
		name = "Deposit Thread " + num;
		limit = balance * 2;
	}
	
	//run method
	public void run() 
	{
		//find max value the account can get to
		System.out.println("Running Deposit thread...");
		while(true) {
			int amount = ThreadLocalRandom.current().nextInt(1, 100);
		
			//check to see if balance is okay
			if ((myAcc.getAccountBalance() + amount) < limit) {
				myAcc.setAccountBalance(myAcc.getAccountBalance() + amount);
				totalDeposited += amount;
				numDeposits++;
			}
			else {
				numWaits++;
			}
			
			//check to see if thread has been interrupted
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				break;
			}	
		}
		printInfo();
	}
	private synchronized void printInfo()
	{
		//print thread info after being interrupted
		System.out.println("I am " + name + ".\n" + "I deposited $" +totalDeposited + 
			 ".\n" + "I made " + numDeposits + " deposits.\n" + "I had to wait " +
			 numWaits + " times on account condition.\n");		
	}
}