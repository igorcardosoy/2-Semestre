package model;

import model.Animais.Animal;
import model.Animais.Cachorro;
import model.Animais.Gato;

import java.util.Scanner;

public class Proprietario {
    private String nome;
    private String endereco;
    private String telefone;
    private String cpf;

    private Animal animal;

    public Proprietario(String nome, String endereco, String telefone, String cpf, String animal) {
        this.nome = nome;
        this.endereco = endereco;
        this.telefone = telefone;
        this.cpf = cpf;

        Scanner scanner = new Scanner(System.in);

        if (animal.equals("Cachorro"))
        {
            String codigo;
            String nome_dog;
            String raca;
            int idade;

            System.out.println("Digite o codigo do Cachorro: ");
            codigo = scanner.nextLine();

            System.out.println("Digite o nome do Cachorro: ");
            nome_dog = scanner.nextLine();

            System.out.println("Digite a idade de (" + nome_dog + ")");
            idade = scanner.nextInt();

            System.out.println("Digite a raca de (" + nome_dog + ")");
            raca = scanner.nextLine();

            this.animal = new Cachorro(codigo, nome_dog, raca, idade);
        } else if (animal.equals("Gato")) {
            String codigo;
            String nome_cat;
            String tipoPelo;

            System.out.println("Digite o codigo do Gato: ");
            codigo = scanner.nextLine();

            System.out.println("Digite o nome do Gato: ");
            nome_cat = scanner.nextLine();

            System.out.println("Digite o tipo de Pelo do gato: ");
            tipoPelo = scanner.nextLine();

            this.animal = new Gato(codigo, nome_cat, tipoPelo);
        }
    }

    @Override
    public String toString() {
        return "Proprietario: " +
                "nome ='" + nome + '\'' +
                ", endereco ='" + endereco + '\'' +
                ", telefone ='" + telefone + '\'' +
                ", cpf ='" + cpf + '\'' +
                ", animal =" + animal.toString();
    }
}
