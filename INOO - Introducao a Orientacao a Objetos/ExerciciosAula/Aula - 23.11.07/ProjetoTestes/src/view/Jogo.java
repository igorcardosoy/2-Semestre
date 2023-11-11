package view;

import model.confronto.MelhorDe3;
import model.confronto.iConfronto;
import model.jogadores.Bot;
import model.jogadores.Humano;
import model.jogadores.Jogador;

import java.util.Scanner;

public class Jogo {

    public static final Scanner scanner = new Scanner(System.in);

    public static void start(){
        iConfronto confronto;
        Jogador jogador1 = null, jogador2 = null;
        int tipoJogador, tipoJogo;

        tipoJogador = lerTipoJogadores();
        tipoJogo = lerTipoJogo();

        switch (tipoJogador){
            case 1:
                jogador1 = new Humano(lerNomeJogador(), lerTipoCoisa());
                jogador2 = new Humano(lerNomeJogador(), lerTipoCoisa());
                break;
            case 2:
                jogador1 = new Humano(lerNomeJogador(), lerTipoCoisa());
                jogador2 = new Bot();
                break;
            case 3:
                jogador1 = new Bot();
                jogador2 = new Bot();
                break;
            default:
                break;
        }

        switch (tipoJogo){
            case 1:
                confronto = new model.confronto.Unico(jogador1, jogador2);
                break;
            case 2:
                int c1 = 0, c2 = 0;

                confronto = new model.confronto.MelhorDe3(jogador1, jogador2);
                MelhorDe3 md3 = (MelhorDe3) confronto;
                System.out.println(md3.getParcial());

                while (confronto.getVencedor() == null){

                    if (jogador1 instanceof Humano)
                    {
                        assert jogador1 != null;
                        System.out.println("Jogada do " + jogador1.getNome());
                        c1 = lerTipoCoisa();
                    } else {
                        System.out.println("Jogada do " + jogador2.getNome());
                    }

                    md3.novaBatalha(c1, c2);
                    System.out.println(md3.getParcial());
                }

                Jogador vencedor = confronto.getVencedor();
                System.out.println("O vencedor é: ");
                if (vencedor != null){
                    System.out.println("Nome: " + vencedor.getNome());
                    System.out.println("Pontos: " + vencedor.getPontos());
                } else {
                    System.out.println("Empate");
                }
                break;
            default:
                break;
        }

    }

    private static int lerTipoJogadores(){
        int opcao;

        do {
            System.out.println("Escolha o tipo de jogadores:");
            System.out.println("1 - Humano vs Humano");
            System.out.println("2 - Humano vs Computador");
            System.out.println("3 - Computador vs Computador");
            System.out.println("Opção: ");
            opcao = scanner.nextInt();
        } while (opcao < 1 || opcao > 3);

        return opcao;
    }

    private static int lerTipoJogo(){
        int opcao;

        do {
            System.out.println("Escolha o tipo de jogo:");
            System.out.println("1 - Único");
            System.out.println("2 - Melhor de 3");
            System.out.println("Opção: ");
            opcao = scanner.nextInt();
        } while (opcao < 1 || opcao > 2);

        return opcao;
    }

    private static int lerTipoCoisa(){
        int opcao;

        do {
            System.out.println("Escolha a sua jogada:");
            System.out.println("1 - Pedra");
            System.out.println("2 - Papel");
            System.out.println("3 - Tesoura");
            System.out.println("Opção: ");
            opcao = scanner.nextInt();
        } while (opcao < 1 || opcao > 3);

        return opcao;
    }

    private static String lerNomeJogador(){
        String nome;

        do {
            System.out.println("Digite o nome do jogador: ");
            nome = scanner.nextLine();
        } while (nome.isEmpty());

        return nome;
    }
}
