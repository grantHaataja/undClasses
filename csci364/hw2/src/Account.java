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
	public void setAccountBalance(int newBalance)
	{
		this.accountBalance = newBalance;
	}
}