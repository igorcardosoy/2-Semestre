public class Cidade {
    private String nome;
    private int populacao;
    private float taxaDeCrescimento;
    

    public Cidade(String nome, int populacao, int taxaDeCrescimento) {
        this.nome = nome;
        this.populacao = populacao;
        this.taxaDeCrescimento = taxaDeCrescimento;
    }

    public void Crescer() {
        CresPopulacional();
    }

    private void CresPopulacional() {
        this.populacao = (int) (this.populacao * ((this.taxaDeCrescimento / 100)+1));
    }

    public String getNome() {
        return nome;
    }

    public int getPopulacao() {
        return populacao;
    }
    
}
