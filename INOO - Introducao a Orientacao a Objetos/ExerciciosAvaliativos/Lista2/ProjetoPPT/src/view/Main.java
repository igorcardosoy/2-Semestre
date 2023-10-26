import src.model.*;
import javax.swing.JOptionPane;

public class Main {

    public static void main(String[] args) {

        Jogo jogo;
        String answer;
        String title = "Pedra, papel e tesoura";
        Object options[] = { "Pedra", "Papel", "Tesoura" };
        int chosen;
        int keepGoing;

        do {
            answer = (String) JOptionPane.showInputDialog(null,
            "Escolha sua jogada: ",
            title,
            JOptionPane.QUESTION_MESSAGE,
            null,
            options,
            options[0]);

            if (answer == options[0]) {
                chosen = 0;
            } else if (answer == options[1]) {
                chosen = 1;
            } else {
                chosen = 2;
            }

            jogo = new Jogo(chosen);
            JOptionPane.showMessageDialog(null, jogo.confronto(), title, JOptionPane.INFORMATION_MESSAGE);

            keepGoing = JOptionPane.showConfirmDialog(null, "Deseja jogar novamente?", title, JOptionPane.YES_NO_OPTION);
        } while (keepGoing != 1);
    }
}
