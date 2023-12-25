package model;

public class Polpa {
    double valor;
    String sabor;

    public Polpa(String sabor, double valor) {
        this.valor = valor;
        this.sabor = sabor;
    }

    public String getSabor() {
        return sabor;
    }
}