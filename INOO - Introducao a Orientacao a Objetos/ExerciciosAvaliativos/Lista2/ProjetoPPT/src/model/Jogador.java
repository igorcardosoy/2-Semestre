package src.model;
import java.util.Random;


public class Jogador {
    private boolean isComputer;
    private Coisa choose;

    public Jogador(boolean isComputer) {
        this.isComputer = isComputer;
        if (isComputer) {
            randomNum();
        }
    }

    public Jogador() {
        this.isComputer = false;
    }

    private void randomNum() {
        Random gerador = new Random();

        if (isComputer) {
            choice(gerador.nextInt(3));
        }
    }

    public void choice(int choice) {
        switch (choice) {
            case 0:
                choose = new Pedra();
                break;
            case 1:
                choose = new Papel();
                break;
            case 2:
                choose = new Tesoura();
                break;
            default:
                break;
        }
    }

    public Coisa getChosen() {
        return choose;
    }
}
