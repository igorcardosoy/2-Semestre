
import javax.swing.JOptionPane;

public class Klaus extends CartaoWeb{
    String message;

    public Klaus(String addressee, String sender, String message) {
        super(addressee, sender);
        this.message = message;
    }

    @Override
    public String getMessage() {
        return message;
    }
    
    @Override
    public String printMessage() {
        
        return null;
    }
}
