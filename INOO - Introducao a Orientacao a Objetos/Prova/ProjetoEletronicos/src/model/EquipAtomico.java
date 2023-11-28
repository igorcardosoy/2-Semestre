package model;

public class EquipAtomico extends EquipamentoEletronico{
    double preco;

    public EquipAtomico(String descricao, double preco) {
        setDescricao(descricao);
        this.preco = preco;
    }

    @Override
    public double getPreco() {
        return preco;
    }
}
