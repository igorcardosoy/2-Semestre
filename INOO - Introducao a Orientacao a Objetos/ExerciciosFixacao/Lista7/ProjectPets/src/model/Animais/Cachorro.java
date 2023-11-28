package model.Animais;

public class Cachorro extends Animal{
    private String nome;
    private String raca;
    private int idade;

    public Cachorro(String codigo, String nome, String raca, int idade) {
        super(codigo);
        this.nome = nome;
        this.raca = raca;
        this.idade = idade;
    }

    @Override
    public String toString() {
        return "Cachorro{" + super.toString() +
                "nome='" + nome + '\'' +
                ", raca='" + raca + '\'' +
                ", idade=" + idade +
                '}';
    }
}
