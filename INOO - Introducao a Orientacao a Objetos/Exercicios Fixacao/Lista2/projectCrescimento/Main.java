public class Main {
    public static void main(String[] args) {
        Cidade city2;
        Cidade city1;
        boolean arqMenor = true;
        int anos = 2023;

        city2 = new Cidade("Marília", 230000, 2);
        city1 = new Cidade("Araraquara", 210000, 3);

        while (arqMenor) {

            System.out.println("Ano "+anos+": ");

            System.out.println("População de "+city2.getNome()+": "+city2.getPopulacao());
            city2.Crescer();

            System.out.println("População de "+city1.getNome()+": "+city1.getPopulacao());
            city1.Crescer();

            anos++;

            System.out.printf("\n\n");

            if (city1.getPopulacao() > city2.getPopulacao()) {
                arqMenor = false;

                System.out.println("População de "+city2.getNome()+": "+city2.getPopulacao());
                System.out.println("População de "+city1.getNome()+": "+city1.getPopulacao());
                System.out.println(city1.getNome()+" estara maior que "+city2.getNome()+" no ano de "+anos+"!");
            }
        }
    }
}
