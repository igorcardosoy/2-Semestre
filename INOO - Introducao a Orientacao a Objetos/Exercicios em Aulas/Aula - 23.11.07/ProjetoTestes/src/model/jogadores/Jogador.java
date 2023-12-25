package model.jogadores;

import model.coisas.Coisa;
import model.coisas.Papel;
import model.coisas.Pedra;
import model.coisas.Tesoura;

public abstract class Jogador {

    public static final int PEDRA = 1;
    public static final int PAPEL = 2;
    public static final int TESOURA = 3;
    protected Coisa mCoisa;
    protected int pontos;


    public Jogador(){
        this.pontos = 0;
    }

    public Coisa getCoisa() {
        return mCoisa;
    }

    public int getPontos() {
        return this.pontos;
    }

    public abstract String getNome();

    public void setCoisa(int nCoisa) {
        defineCoisa(nCoisa);
    }

    public void pontuar(){
        this.pontos+=1;
    }

    private void defineCoisa(int coisa) {
        switch (coisa) {
            case PEDRA:
                this.mCoisa = new Pedra();
                break;

            case PAPEL:
                this.mCoisa = new Papel();
                break;

            case TESOURA:
                this.mCoisa = new Tesoura();
                break;

            default:
                this.mCoisa = null;
                break;
        }
    }

}
