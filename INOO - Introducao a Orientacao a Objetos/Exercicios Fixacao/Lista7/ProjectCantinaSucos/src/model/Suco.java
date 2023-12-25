package model;

public class Suco {
    Polpa polpa_1;
    Polpa polpa_2;
    int preco;

    public Suco(Polpa polpa_1, Polpa polpa_2) {
        this.polpa_1 = polpa_1;
        this.polpa_2 = polpa_2;
        this.preco = 0;

        calcularPreco();
    }

    private void calcularPreco() {
        double valor;
        valor = (int) (((polpa_1.valor / 3) * 2) + (polpa_2.valor / 3)) + 0.5;
        preco = (int) ((valor * 0.35) + 0.5);

        if (preco > 20){
            preco = 20;
        }
    }

    @Override
    public String toString() {

        return "Suco: " + polpa_1.sabor + " e " + polpa_2.sabor + " - R$" + preco;
    }

    public double getLucro() {

       return (preco - polpa_1.valor - polpa_2.valor);
    }

    public int getPreco() {
        return preco;
    }
}