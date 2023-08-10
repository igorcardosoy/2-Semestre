import java.util.Scanner;

public class Exer8 {
    public static void main(String[] args) {
        int size = 0;
        int divisores;
        Scanner input = new Scanner(System.in);

        while (size <= 0) {
            System.out.printf("\nDigite um numero (>0): ");
            size = input.nextInt();
        }

        for (int index = 1; index < size; index++) {

            divisores = 0;

            for (int count = 1; divisores != 3 && count <= index; count++) {
                if((index % count) == 0) 
                {
                    divisores += 1;
                }
            }

            if (divisores != 3) {
                System.out.printf("É primo: %d\n", index);
            }
        }

        input.close();
    }
}
