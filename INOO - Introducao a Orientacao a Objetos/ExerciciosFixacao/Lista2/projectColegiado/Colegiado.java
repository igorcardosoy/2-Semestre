import java.util.Random;

public class Colegiado {
    private String nome;
    private String prontuario;
    private int votos;
    private Random randomProntuario;

    public Colegiado(String nome, String prontuario) {
        this.nome = nome;
        this.prontuario = prontuario;
        this.votos = 0;
    }

    public Colegiado(String nome) {
        randomProntuario = new Random();
        this.nome = nome;
        this.prontuario = "AQ"+(randomProntuario.nextInt(9999999)+1);
        this.votos = 0;
    }

    public void addVoto() {
        countVoto();
    }

    private void countVoto() {
        this.votos++;
    }

    public String getNome() {
        return nome;
    }

    public String getProntuario() {
        return prontuario;
    }

    public int getVotos() {
        return votos;
    }

    @Override
    public String toString() {
        return "Colegiado [nome=" + nome + ", prontuario=" + prontuario + ", votos=" + votos + "]";
    }

}
