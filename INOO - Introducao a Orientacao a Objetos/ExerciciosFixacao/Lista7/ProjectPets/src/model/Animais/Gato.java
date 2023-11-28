package model.Animais;

public class Gato extends Animal{
    private String nome;
    private String tipoPelo;

    public Gato(String codigo ,String nome, String tipoPelo) {
        super(codigo);
        this.nome = nome;
        this.tipoPelo = tipoPelo;
    }

    @Override
    public String toString() {
        return "Gato{" + super.toString() +
                "nome='" + nome + '\'' +
                ", tipoPelo='" + tipoPelo + '\'' +
                '}';
    }
}
