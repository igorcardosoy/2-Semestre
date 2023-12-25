package model.confronto;

import model.jogadores.Jogador;

public class MelhorDe3 implements iConfronto{
    private Jogador jogador1;
    private Jogador jogador2;
    private int qtdJogos;

    public MelhorDe3(Jogador jogador1, Jogador jogador2) {
        this.jogador1 = jogador1;
        this.jogador2 = jogador2;
        batalhar();
    }

    @Override
    public Jogador getVencedor() {
        Jogador result = null;

        if (jogador1.getPontos() == 2) {
            result = jogador1;
        } else if (jogador2.getPontos() == 2) {
            result = jogador2;
        }

        return result;
    }

    public String getParcial(){
        return jogador1.getNome() + " " + jogador1.getPontos() + " vs " + jogador2.getNome() + " " + jogador2.getPontos();
    }

    public void novaBatalha(int coisaJogador1, int coisaJogador2){
        jogador1.setCoisa(coisaJogador1);
        jogador2.setCoisa(coisaJogador2);
        batalhar();
    }

    private void batalhar() {

        switch (jogador1.getCoisa().batalha(jogador2.getCoisa())){
            case VITORIA:
                jogador1.pontuar();
                break;
            case DERROTA:
                jogador2.pontuar();
                break;
            default:
                break;
        }
    }
}
