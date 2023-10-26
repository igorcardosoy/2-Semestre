package src.model;

public class Pedra extends Coisa {

    @Override
    public boolean win(Coisa coisa) {
       return coisa instanceof Tesoura;
    }
    
}
