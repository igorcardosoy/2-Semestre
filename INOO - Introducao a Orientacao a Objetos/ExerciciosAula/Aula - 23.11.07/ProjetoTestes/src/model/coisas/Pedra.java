package model.coisas;

public class Pedra extends Coisa{
    @Override
    public ResultadoBatalha batalha(Coisa desafiante) {
        ResultadoBatalha result = ResultadoBatalha.DERROTA;

        if (desafiante instanceof Pedra){
            result = ResultadoBatalha.EMPATE;
        } else if (desafiante instanceof Tesoura) {
            result = ResultadoBatalha.VITORIA;
        }

        return result;
    }
}
