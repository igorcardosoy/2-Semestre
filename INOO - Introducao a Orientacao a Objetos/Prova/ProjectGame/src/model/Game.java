package model;

public class Game {
    Dado dado;

    public Game() {
        dado = new Dado(6);
    }

    public boolean partida(){

        int countWins = 0;
        boolean win = false;

        for (int i = 0; i < 3; i++){
            if (jogar()){
                countWins++;
            }
        }

        if (countWins >= 2){
            win= true;
        }

        return win;
    }

    private boolean jogar(){

        boolean win = false;

        int soma;

        soma = dado.jogarDado();
        soma += dado.jogarDado();

        if (soma == 7 || soma == 11){
            win = true;
        }

        return win;
    }
}
