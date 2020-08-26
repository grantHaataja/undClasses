/**
 * FractionReducer.java
 */
package server;

import java.lang.Math;
import api.Worker;

/**
 * @author grant haataja
 *
 */
class FractionReducer extends Worker {
	private int top = 0;
	private int bottom = 0;
	private int gcf = 0;
	
	/**
	 * @param id 
	 * @param num the numerator
	 * @param denom the denominator
	 */
	FractionReducer(int id, int num, int denom) 
	{
		super(id, "FractionReducer");
		this.top = num;
		this.bottom = denom;
	}

	/* (non-Javadoc)
	 * @see hw3.Worker#doWork()
	 */
	@Override
	public void doWork() 
	{
		for (int factor = 1; factor < (top+bottom); factor++) {
			if ((top % factor == 0) && (bottom % factor == 0)) {
				gcf = factor;
			}
		}
	}

	public int getNumerator() 
	{
		return top / gcf;
	}
	public int getDenominator()
	{
		return bottom / gcf;
	}
	
	/**
	 * 
	 * @return 
	 */
	public String getResult()
	{
		int top = getNumerator();
		int bottom = getDenominator();
		
		return  top + " / " + bottom;
	}
}