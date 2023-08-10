import java.util.Scanner;

public class Exer5 {
    public static void main(String[] args) {
        int size;
        int maior = 0;
        int count = 0;
        int num;
        Scanner input = new Scanner(System.in);

        
        System.out.printf("\nDigite a quantidade de numeros: ");
        size = input.nextInt();

        System.out.printf("\nDigite num: ");
        num = input.nextInt();

        maior = num;

        for (int i = 0; i < (size - 1); i++) {
            num = input.nextInt();

            if (num > maior) {
                maior = num;
                count++;
            }

        }

        System.out.printf("\nO maior num é: %d\nO numero maior foi trocado %d vezes!\n", maior, count);

        input.close();

    }
}
