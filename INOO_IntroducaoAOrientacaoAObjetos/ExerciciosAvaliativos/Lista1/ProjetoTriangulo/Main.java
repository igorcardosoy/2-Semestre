import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner input;
        Triangulo triangulo;

        int a, b, c;

        input = new Scanner(System.in);

        for(int index = 0; index != 5; index++)
        {
            a = input.nextInt();
            b = input.nextInt();
            c = input.nextInt();

            triangulo = new Triangulo(a, b, c);

            if (triangulo.isEquilatero()){
                System.out.println("Equilatero");
            }else if (triangulo.isIsoceles()){
                System.out.println("Isoceles");
            }else if (triangulo.isEscaleno()){
                System.out.println("Escaleno");
            }else{
                System.out.println("Não é triangulo");
            }

        }

        input.close();

    }
}