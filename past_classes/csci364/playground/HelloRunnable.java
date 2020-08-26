public class HelloRunnable implements Runnable {

	private int val;
	
	public HelloRunnable(int val) {
	this.val = val;
	}

	public void run() {
		String name = Thread.currentThread().getName();
		System.out.println("Hello from thread " + name +
			". My val is " + val);
	}

	public static void main(String[] args) {
		for (int i = 0; i < 5; i++) {
			Runnable runnable = new HelloRunnable(i);
			Thread thread = new Thread(runnable);
			thread.start();
		}
	}
}
