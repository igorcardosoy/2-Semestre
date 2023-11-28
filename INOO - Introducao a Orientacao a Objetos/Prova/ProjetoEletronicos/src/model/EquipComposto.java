package model;

import java.util.ArrayList;
import java.util.List;

public class EquipComposto extends EquipamentoEletronico{

    List<EquipamentoEletronico> composição;

    public EquipComposto(String descricao) {
        setDescricao(descricao);
        composição = new ArrayList<>(5);
    }

    public void inserirParte(EquipamentoEletronico equip){
        composição.add(equip);
    }

    @Override
    public double getPreco() {
        double precoTotal = 0;

        for (int i = 0; i < composição.size(); i++) {
            precoTotal += composição.get(i).getPreco();
        }

        return precoTotal;
    }
}
