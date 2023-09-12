import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        boolean votacao = true;
        int votosNulos = 0;
        int votosBrancos = 0;

        int codigo;
        int sizeChar = 0;

        Colegiado candidatos[] = new Colegiado[3];
        Colegiado aux = new Colegiado("");
        Scanner input = new Scanner(System.in);

        candidatos[0] = new Colegiado("Igor Filipi Cardoso");
        candidatos[1] = new Colegiado("Caio Lopes");
        candidatos[2] = new Colegiado("Lucas Alcantara");

        // String nome;
        // for (int i = 0; i < candidatos.length; i++) {

        // System.out.printf("\nDigite o nome do candidato [" + (i + 1) + "]: ");
        // nome = input.nextLine();

        // candidatos[i] = new Colegiado(nome);
        // }

        candidatos[0].getNome();
        candidatos[0].getProntuario();

        while (votacao) {

            System.out.printf("\nDigite o código do candidato: ");
            codigo = input.nextInt();

            switch (codigo) {
                case 1:
                    candidatos[0].addVoto();
                    break;
                case 2:
                    candidatos[1].addVoto();
                    break;
                case 3:
                    candidatos[2].addVoto();
                    break;
                case 4:
                    votosNulos++;
                    break;
                case 5:
                    votosBrancos++;
                    break;
                case 0:
                    votacao = false;
                    break;
                default:
                    System.out.println("Código incorreto!!");
                    break;
            }
        }

        for (int i = 0; i < candidatos.length; i++) {
            for (int j = 0; j < candidatos.length; j++) {
                if (candidatos[i].getVotos() > candidatos[j].getVotos()) {
                    aux = candidatos[i];
                    candidatos[i] = candidatos[j];
                    candidatos[j] = aux;
                }
            }
        }

        sizeChar = candidatos[0].getNome().length();
        for (int i = 0; i < candidatos.length; i++) {
            if (candidatos[i].getNome().length() > sizeChar) {
                sizeChar = candidatos[i].getNome().length();
            }
        }

        for (int i = 0; i < candidatos.length; i++) {
            System.out.printf("\nNome: %-" + sizeChar + "." + sizeChar + "s | Votos: %d", candidatos[i].getNome(),
                    candidatos[i].getVotos());
        }

        System.out.printf("\n%-" + (sizeChar + 7) + "s", "----- Votos nulos");
        System.out.printf("| Votos: %d", votosNulos);

        System.out.printf("\n%-" + (sizeChar + 7) + "s", "----- Votos brancos");
        System.out.printf("| Votos: %d", votosBrancos);

        input.close();
    }
}
