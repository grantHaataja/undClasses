/**
 * SumReducer.java
 */
package server;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import api.Worker;

/**
 * @author Grant Haataja
 *
 */
class SumReducer extends Worker {
	private List<Double> list = new ArrayList<Double>();
	private double summ;

	/**
	 * @param id 
	 * @param arr an array of items to be summed 
	 */
	@SafeVarargs
	SumReducer(int id, Double ...arr) 
	{
		super(id, "SumReducer");
		list.addAll(Arrays.asList(arr));
	}
	
	/* (non-Javadoc)
	 * @see hw3.Worker#doWork()
	 */
	@Override
	public void doWork() 
	{
		for (int i = 0; i < list.size(); i++) {
			summ += list.get(i);
		}
	}
	
	/**
	 * 
	 * @return 
	 */
	public String getResult() 
	{
		return summ + "";
	}
}