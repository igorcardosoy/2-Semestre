package model.confronto;

import model.jogadores.Jogador;

public class Unico implements iConfronto{

    private Jogador jogador1;
    private Jogador jogador2;

    public Unico(Jogador jogador1, Jogador jogador2) {
        this.jogador1 = jogador1;
        this.jogador2 = jogador2;
    }



    @Override
    public Jogador getVencedor() {

        Jogador result = null;

        switch (jogador1.getCoisa().batalha(jogador2.getCoisa())){
            case VITORIA:
                result = jogador1;
                break;

            case DERROTA:
                result = jogador2;
                break;

            default:
                break;
        }

        return  result;
    }
}
