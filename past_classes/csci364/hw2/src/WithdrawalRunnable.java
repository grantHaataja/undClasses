//CSCI 364 Assignment II Withdrawal Runnable
//Grant Haataja

import java.lang.Runnable;
import java.lang.Thread;
import java.lang.InterruptedException;
import java.util.concurrent.ThreadLocalRandom;

public class WithdrawalRunnable implements Runnable 
{
	private Account myAcc;
	private int totalWithdrawn = 0;
	private int numWithdrawals = 0;
	private int numWaits = 0;
	private String name;
	
	//constructor
	public WithdrawalRunnable(Account account, int num) 
	{
		myAcc = account;
		name = "Withdrawal Thread " + num;
	}
	
	//run method
	public void run() 
	{
		System.out.println("Running Withdrawal thread...");
		while(true) {
			int amount = ThreadLocalRandom.current().nextInt(1, 100);
		
			//check to see if balance is okay
			if ((myAcc.getAccountBalance() - amount) > 0) {
				myAcc.updateBalance(-amount);
				totalWithdrawn += amount;
				numWithdrawals++;
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
		System.out.println("I am " + name + ".\n" + "I withdrew $" + totalWithdrawn + 
			".\n" + "I made " + numWithdrawals + " withdrawals.\n" + "I had to wait " + 
			numWaits + " times on account condition.\n");
	}
}
