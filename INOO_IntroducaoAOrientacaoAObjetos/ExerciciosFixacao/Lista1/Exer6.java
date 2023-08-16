import java.util.Scanner;

public class Exer6 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int size = 0, count = 1;

        while (size <= 0) {
            System.out.printf("\nDigite o tamanho da piramide (>0): ");
            size = input.nextInt();
        }

        for(int i = 1; i < size+1; i++)
        {
            for(int j = 0; j < i; j++)
            {
                System.out.printf("%d ", count);
                count++;
            }

             System.out.printf("\n");
        }


        input.close();
    }
}
