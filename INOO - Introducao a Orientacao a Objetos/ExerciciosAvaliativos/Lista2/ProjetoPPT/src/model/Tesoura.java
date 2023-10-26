package src.model;

public class Tesoura extends Coisa{
    @Override
    public boolean win(Coisa coisa) {
       return coisa instanceof Papel;
    }
}
