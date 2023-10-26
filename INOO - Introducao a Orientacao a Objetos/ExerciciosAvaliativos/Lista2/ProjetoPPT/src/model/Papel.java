package src.model;

public class Papel extends Coisa{

    @Override
    public boolean win(Coisa coisa) {
       return coisa instanceof Pedra;
    }
}
