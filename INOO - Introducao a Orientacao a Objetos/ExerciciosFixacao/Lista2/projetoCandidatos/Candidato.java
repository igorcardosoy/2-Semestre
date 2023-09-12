import java.util.Random;

public class Candidato {
    private int notaTeorica;
    private int notaPratica;
    private int notaEntrevista;
    private int notaFinal = 0;
    private String nome;
    

    public Candidato(int notaTeorica, int notaPratica, int notaEntrevista, String nome) {
        this.notaTeorica = notaTeorica;
        this.notaPratica = notaPratica;
        this.notaEntrevista = notaEntrevista;
        this.nome = nome;
    }

    public Candidato(String nome) {
        Random criarNotas = new Random();
        this.notaPratica = criarNotas.nextInt(101);
        this.notaEntrevista = criarNotas.nextInt(101);
        this.notaTeorica = criarNotas.nextInt(101);
        this.nome = nome;
    }

    public void calcMedia() {
        mediaPonderada();
    }

    private void mediaPonderada() {
        this.notaFinal = ((this.notaTeorica*3) + (this.notaPratica*4) + (this.notaEntrevista*3)) / 10;
    }

    public int getNotaFinal() {
        return notaFinal;
    }

    public String getNome() {
        return nome;
    }

    @Override
    public String toString() {
        return "Candidato [notaTeorica=" + notaTeorica + ", notaPratica=" + notaPratica + ", notaEntrevista="
                + notaEntrevista + ", notaFinal=" + notaFinal + ", nome=" + nome + "]";
    }

}
