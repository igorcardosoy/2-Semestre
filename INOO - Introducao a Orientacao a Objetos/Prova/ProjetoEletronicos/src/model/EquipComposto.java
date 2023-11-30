package model;

import java.util.ArrayList;
import java.util.List;

public class EquipComposto extends EquipamentoEletronico{

    List<EquipamentoEletronico> composicao;

    public EquipComposto(String descricao) {
        setDescricao(descricao);
        composicao = new ArrayList<>(5);
    }

    public void inserirParte(EquipamentoEletronico equip){
        composicao.add(equip);
    }

    @Override
    public double getPreco() {
        double precoTotal = 0;

      for (EquipamentoEletronico equipamentoEletronico : composicao) {
        precoTotal += equipamentoEletronico.getPreco();
      }

        return precoTotal;
    }
}
