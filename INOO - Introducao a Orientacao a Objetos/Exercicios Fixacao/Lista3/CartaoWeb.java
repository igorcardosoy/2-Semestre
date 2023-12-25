package Cards;

public abstract class CartaoWeb{

    private String addressee;
    private String sender;

        public CartaoWeb(String addressee, String sender){
            this.addressee = addressee;
            this.sender = sender;
        }

        public abstract String printMessage();

        public abstract String getMessage();
}
