//CSCI 364 Assignment II Account
//Grant Haataja

public class Account
{
	private int accountBalance;
	
	//constructor
	public Account(int initalBalance)
	{
		accountBalance = initalBalance;
	}
	
	//getter method
	public int getAccountBalance()
	{
		return accountBalance;
	}
	//setter method
	public synchronized void updateBalance(int change)
	{
		this.accountBalance += change;
	}
}
