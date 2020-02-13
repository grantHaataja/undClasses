public class Deadlock { 
	static class Friend { 
		private final String name; 
		public Friend(String name) { 
			this.name = name; 
		} 
		public String getName() { 
			return name; 
		} 
		public synchronized void bow(Friend bower) { 
			System.out.format("%s: %s has bowed to me!%n",name,bower.getName()); 
			bower.bowBack(this); 
		} 
		public synchronized void bowBack(Friend bower) { 
			System.out.format("%s: %s has bowed back to me!%n",
				this.name, bower.getName()); 
        } 
	}
		
	public static void main(String[] args) { 
		final Friend alphonse = new Friend("Alphonse"); 
		final Friend gaston = new Friend("Gaston"); 
		Runnable r1 = new Runnable() { 
			public void run() { 
			alphonse.bow(gaston); 
			} 
        };
        
		new Thread(r1).start(); 
		Runnable r2 = new Runnable() { 
			public void run() { 
			gaston.bow(alphonse); 
			} 
		};
		new Thread(r2).start(); 
	} 
}
