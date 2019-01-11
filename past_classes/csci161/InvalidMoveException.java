public class InvalidMoveException extends Exception {

	public InvalidMoveException() {
        super("Please input the move command again"); 
    }
    
    public InvalidMoveException(String stuff) {
        super(stuff); 
    }
}

