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
		System.out.println("Running Withdrawal thread...\n");
		while(true) {
			int amount = ThreadLocalRandom.current().nextInt(1, 100);
		
			//check to see if balance is okay
			if ((myAcc.getAccountBalance() - amount) > 0) {
				myAcc.setAccountBalance(myAcc.getAccountBalance() - amount);
				totalWithdrawn += amount;
				numWithdrawals++;
			}
			else {
				System.out.println("Insufficient Account Balance.");
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
		System.out.println("I withdrew $" + totalWithdrawn + ".");
		System.out.println("I made " + numWithdrawals + " withdrawals.");
		System.out.println("I had to wait " + numWaits + " times on account condition.");	

	}
}