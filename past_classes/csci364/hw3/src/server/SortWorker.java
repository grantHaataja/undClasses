/**
 * SortWorker.java
 */
package server;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import api.Worker;

/**
 * @author david
 *
 */
class SortWorker<T extends Comparable<? super T>> extends Worker {
	//private static final long serialVersionUID = -4051898108461870504L;
	private List<T> list = new ArrayList<T>();
	
	/**
	 * @param id 
	 * @param arr an array of items to be sorted 
	 */
	@SafeVarargs
	SortWorker(int id, T ...arr) {
		super(id, "SortWorker");
		list.addAll(Arrays.asList(arr));
	}

	/* (non-Javadoc)
	 * @see hw3.Worker#doWork()
	 */
	@Override
	public void doWork() {
		Collections.sort(list);
	}
		
	/**
	 * 
	 * @return 
	 */
	public List<T> getResult() {
		return list;
	}
}