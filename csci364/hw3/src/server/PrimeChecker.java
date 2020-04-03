/**
 * PrimeChecker.java
 */
package server;

import java.lang.Math;
import api.Worker;

/**
 * @author grant haataja
 *
 */
class PrimeChecker extends Worker {
	private int number = 0;
	private boolean isPrime;
	
	/**
	 * @param id 
	 * @param num an integer to test 
	 */
	PrimeChecker(int id, int num) 
	{
		super(id, "PrimeChecker");
		this.number = num;
	}

	/* (non-Javadoc)
	 * @see hw3.Worker#doWork()
	 */
	@Override
	public void doWork() 
	{
		if (number == 0 || number == 1) {
			isPrime = false;
		}
		else {
			for (int i = 2; i < number; i++) {
				if (number % i == 0) {
					isPrime = false;
					break;
				}
				else {
					isPrime = true;
				}
			}
		}
	}
		
	/**
	 * 
	 * @return 
	 */
	public String getResult() 
	{
		if (isPrime)
			return number + " is prime.";
		else
			return number + " is not prime.";
	}
}