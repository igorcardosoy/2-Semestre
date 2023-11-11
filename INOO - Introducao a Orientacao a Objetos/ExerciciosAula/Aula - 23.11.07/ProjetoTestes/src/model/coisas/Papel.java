package model.coisas;

public class Papel extends Coisa {

    @Override
    public ResultadoBatalha batalha(Coisa desafiante) {

        ResultadoBatalha result = ResultadoBatalha.DERROTA;

        if (desafiante instanceof Papel){
            result = ResultadoBatalha.EMPATE;
        } else if (desafiante instanceof Pedra) {
            result = ResultadoBatalha.VITORIA;
        }

        return result;
    }
}
