package view;


import model.Proprietario;

public class Testes {

    public static void run(){
        Proprietario dono = new Proprietario("Igor", "Rua Maria, 328", "16 123456789", "475.178.834-23", "Gato");

        System.out.println(dono.toString());
    }
}
