import java.util.Scanner;

public class Exer3 {
    public static void main(String[] args) {
        double soma = 0, media;
        Scanner input = new Scanner(System.in);
        
        for(int i = 0; i < 10; i++)
        {
            soma += input.nextDouble();
        }

        media = soma / 10;
        
        System.out.printf("Média: %.2lf\n", media);

        input.close();
    }
}
