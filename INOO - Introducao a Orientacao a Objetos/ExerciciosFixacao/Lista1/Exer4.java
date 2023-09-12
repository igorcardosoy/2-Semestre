import java.util.Scanner;

public class Exer4 {
    public static void main(String[] args) {
        int SIZE = 5;
        int maior = 0, menor = 0;
        int num;
        Scanner input = new Scanner(System.in);

        num = input.nextInt();

        maior = num;
        menor = num;

        for (int i = 0; i < (SIZE - 1); i++) {
            num = input.nextInt();

            if (num < menor) {
                menor = num;
            }

            if (num > maior) {
                maior = num;
            }

        }

        System.out.printf("O menor num é: %d\nO maior num é: %d", menor, maior);

        input.close();

    }
}
