package model.coisas;

public class Tesoura extends Coisa{
    @Override
    public ResultadoBatalha batalha(Coisa desafiante) {
        ResultadoBatalha result = ResultadoBatalha.DERROTA;

        if (desafiante instanceof Tesoura){
            result = ResultadoBatalha.EMPATE;
        } else if (desafiante instanceof Papel) {
            result = ResultadoBatalha.VITORIA;
        }

        return result;
    }
}
