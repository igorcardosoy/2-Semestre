package model.jogadores;

public class Humano extends Jogador{

    String nome;

    public Humano(String nome, int coisa) {
        super();
        this.nome = nome;
        setCoisa(coisa);
    }

    @Override
    public String getNome() {
        return this.nome;
    }

}
