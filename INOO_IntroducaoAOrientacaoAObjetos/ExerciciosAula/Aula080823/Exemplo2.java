import java.util.Scanner;

public class Exemplo2 {
    
    public static void main(String[] args) {
        int ano;

        Scanner input = new Scanner(System.in);

        System.out.print("Digite o ano de nascimento: ");

        ano = input.nextInt();

        System.out.printf("Idade: %4d\n", 2023 - ano);

        input.close();
    }

}
