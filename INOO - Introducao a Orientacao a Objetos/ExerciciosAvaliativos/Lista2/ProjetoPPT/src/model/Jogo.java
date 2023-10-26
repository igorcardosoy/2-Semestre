package src.model;

public class Jogo {
    
    private Jogador jogador1;
    private Jogador jogador2;

    public Jogo(int opcaoEscolhida) {
        jogador1 = new Jogador(false);
        jogador1.choice(opcaoEscolhida);

        jogador2 = new Jogador(true);
    }

    public String confronto() {
        if(jogador1.getChosen().win(jogador2.getChosen ())) {
            return ("O Player 1 ganhou, o jogador.");
        } else if (jogador2.getChosen().win(jogador1.getChosen ())) {
            return ("O Player 2 ganhou, a máquina."); 
        } else {
            return ("O jogo deu empate, sem ganhador.");
        }
    }
}
