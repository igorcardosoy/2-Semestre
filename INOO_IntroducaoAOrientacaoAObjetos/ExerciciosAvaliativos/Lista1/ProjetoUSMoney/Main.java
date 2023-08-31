import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        
        boolean stop = false;
        int teste;

        Scanner input = new Scanner(System.in);

        while(!stop){

            System.out.printf("\n\nDigite o dinheiro da conta [1] (Ex: 5 50): ");
            USMoney conta1 = new USMoney(input.nextInt(), input.nextInt());

            System.out.printf("\n----------------------------------------------\n");

            System.out.printf("\nDigite o dinheiro da conta [2] (Ex: 5 50): ");
            USMoney conta2 = new USMoney(input.nextInt(), input.nextInt());

            USMoney conta3 = conta1.plus(conta2);

            System.out.printf("\n----------------------------------------------\n");
            System.out.printf("\nSaldo da conta [3] = $ %d,%0,2d\n", conta3.getDollars(), conta3.getCents());
            System.out.printf("\n----------------------------------------------\n");

            System.out.printf("\nDeseja continuar os testes? (1/0): ");
            teste = input.nextInt();

            if (teste == 0) {
                stop = true;
            }
        }

        input.close();
    }
}
