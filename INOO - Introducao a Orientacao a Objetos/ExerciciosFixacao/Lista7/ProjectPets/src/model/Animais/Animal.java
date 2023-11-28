package model.Animais;

public abstract class Animal {
    private String codigo;

    public Animal(String codigo) {
        this.codigo = codigo;
    }

    @Override
    public String toString() {
        return "codigo ='" + codigo + '\'';
    }
}
