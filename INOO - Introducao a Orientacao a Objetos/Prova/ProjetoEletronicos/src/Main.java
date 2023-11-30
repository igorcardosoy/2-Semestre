import model.EquipAtomico;
import model.EquipComposto;

public class Main {
    public static void main(String[] args) {

        // Testes...

        EquipAtomico equip1 = new EquipAtomico("Placa de video", 5);
        EquipAtomico equip2 = new EquipAtomico("Placa Mãe", 4.99f);
        EquipAtomico equip3 = new EquipAtomico("Mouse", 1.99f);
        EquipAtomico equip4 = new EquipAtomico("Monitor", 3.5f);

        EquipComposto equipComp = new EquipComposto("Computador");
        EquipComposto equipComp2 = new EquipComposto("Computador2");

        System.out.println("Preco "+ equip1.getDescricao() + " = " + equip1.getPreco());
        System.out.println("Preco "+ equip2.getDescricao() + " = " + equip2.getPreco());
        System.out.println("Preco "+ equip4.getDescricao() + " = " + equip4.getPreco());

        equipComp2.inserirParte(equip1);
        equipComp2.inserirParte(equip3);

        equipComp.inserirParte(equip1);
        equipComp.inserirParte(equip2);
        equipComp.inserirParte(equip3);
        equipComp.inserirParte(equip4);
        equipComp.inserirParte(equipComp2);

        double soma = equip1.getPreco() + equip2.getPreco() + equip3.getPreco() + equip4.getPreco();

        System.out.println("Soma dos preços: " + soma);
        System.out.println("Preco " + equipComp.getDescricao() + " = " + equipComp.getPreco());


    }
}