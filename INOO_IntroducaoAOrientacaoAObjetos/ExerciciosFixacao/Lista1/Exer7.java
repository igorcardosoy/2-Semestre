import java.util.Scanner;

public class Exer7 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        boolean stop = false;

        int helicopter, police, prisoner, direction;

        System.out.printf("\nDigite a posição do Helicoptero: ");
        helicopter = input.nextInt();

        System.out.printf("\nDigite a posição da Policia: ");
        police = input.nextInt();

        System.out.printf("\nDigite a posição do prisioneiro: ");
        prisoner = input.nextInt();

        System.out.printf("\nDigite a posição do direção(-1 / 1): ");
        direction = input.nextInt();

        if (direction == -1) {
            while (!stop) {

                if (prisoner == 0) {
                    prisoner = 15;
                }

                if (prisoner == police) {
                    stop = true;
                    System.out.printf("\nN\n");
                } else if (prisoner == helicopter) {
                    stop = true;
                    System.out.printf("\nS\n");
                }
                prisoner--;
            }
        }

        if (direction == 1) {
            while (!stop) {

                if (prisoner == 15) {
                    prisoner = 0;
                }

                if (prisoner == police) {
                    stop = true;
                    System.out.printf("\nN\n");
                } else if (prisoner == helicopter) {
                    stop = true;
                    System.out.printf("\nS\n");
                }
                prisoner++;
            }
        }
        input.close();
    }
}
