//CSCI364 Assignment II
//Grant Haataja
import java.lang.Runnable;
import java.lang.InterruptedException;

public class Driver
{
	public static void main(String[] args)
	{
		//verify user-entered arguments
		if ((args.length != 4) || Integer.parseInt(args[0]) < 1 || 
				Integer.parseInt(args[1]) < 1 || Integer.parseInt(args[2]) <= 0) {
			System.err.println("Usage: java -cp build Driver [number of deposit threads]"
				+ " [number of withdrawal threads] [inital account balance] " +
				"[milliseconds main thread must sleep before and after changing threads]");
			System.exit(0);
		}
		//define variables for command line arguments
		int depositThreads = Integer.parseInt(args[0]);
		int withdrawalThreads = Integer.parseInt(args[1]);
		int accountBalance = Integer.parseInt(args[2]);
		int sleepyTime = Integer.parseInt(args[3]);
		
		//create the account
		Account myAcc = new Account(accountBalance);
		
		//start the deposit threads
		Thread[] dThreads = new Thread[depositThreads];
		for (int i = 0; i < depositThreads; i++) {
			DepositRunnable dRun = new DepositRunnable(myAcc, i+1);
			dThreads[i] = new Thread(dRun);
			dThreads[i].start();
		}
		
		//start the withdrawal threads
		Thread[] wThreads = new Thread[withdrawalThreads];
		for (int i = 0; i < withdrawalThreads; i++) {
			WithdrawalRunnable wRun = new WithdrawalRunnable(myAcc, i+1);
			wThreads[i] = new Thread(wRun);
			wThreads[i].start();
		}
		System.out.println("Bedtime\n");
		//sleep for the appropriate time
		try {
			Thread.sleep(sleepyTime);
		} catch (InterruptedException e) {
			System.err.println("Main thread interrupted.\n");
			System.exit(0);
		}
		System.out.println("Now we've rested\n");
		
		//interrupt the deposit threads
		for (int i = 0; i < depositThreads; i++) {
			dThreads[i].interrupt();
		}
		
		//interrupt the withdrawal threads
		for (int i = 0; i < withdrawalThreads; i++) {
			wThreads[i].interrupt();
		}
		
		//print the final account balance
		System.out.println("Final account balance: $" + myAcc.getAccountBalance());
	}
}