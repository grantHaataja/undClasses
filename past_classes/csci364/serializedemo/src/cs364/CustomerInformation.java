/**
 * 
 */
package cs364;

/**
 * @author david
 *
 */
public class CustomerInformation implements java.io.Serializable {
	String name;
	int id;
	
	/**
	 * 
	 */
	public CustomerInformation(String name, int id) {
		this.name = name;
		this.id = id;
	}

	public String toString() {
		return name + ":" + id;
	}
}
