public class Main {
    public static void main(String[] args) {
        Candidato candidato1;
        Candidato candidato2;
        Candidato candidato3;
        

        candidato1 = new Candidato("Igor Cardoso");
        candidato2 = new Candidato("Anderson Figueiredo");
        candidato3 = new Candidato("Matheus Costa");

        candidato1.calcMedia();
        candidato2.calcMedia();
        candidato3.calcMedia();

        System.out.println(candidato1.toString());
        System.out.println(candidato2.toString());
        System.out.println(candidato3.toString());

        candidato1.getNotaFinal();

        if (candidato1.getNotaFinal() > candidato2.getNotaFinal()) {
            if (candidato1.getNotaFinal() > candidato3.getNotaFinal()) {
                System.out.println("Nota: "+candidato1.getNotaFinal()+" | Nome: "+candidato1.getNome());
                if (candidato2.getNotaFinal() > candidato3.getNotaFinal()) {
                    System.out.println("Nota: "+candidato2.getNotaFinal()+" | Nome: "+candidato2.getNome());
                    System.out.println("Nota: "+candidato3.getNotaFinal()+" | Nome: "+candidato3.getNome());
                }
                else
                {
                    System.out.println("Nota: "+candidato3.getNotaFinal()+" | Nome: "+candidato3.getNome());
                    System.out.println("Nota: "+candidato2.getNotaFinal()+" | Nome: "+candidato2.getNome());
                }
            }
            else
            {
                System.out.println("Nota: "+candidato3.getNotaFinal()+" | Nome: "+candidato3.getNome());
                System.out.println("Nota: "+candidato1.getNotaFinal()+" | Nome: "+candidato1.getNome());
                System.out.println("Nota: "+candidato2.getNotaFinal()+" | Nome: "+candidato2.getNome());
            }
            
        }
        else if (candidato2.getNotaFinal() > candidato1.getNotaFinal()) {
            if (candidato2.getNotaFinal() > candidato3.getNotaFinal()) {
                    System.out.println("Nota: "+candidato2.getNotaFinal()+" | Nome: "+candidato2.getNome());
                    
                if (candidato1.getNotaFinal() > candidato3.getNotaFinal()) {
                    System.out.println("Nota: "+candidato1.getNotaFinal()+" | Nome: "+candidato1.getNome());
                    System.out.println("Nota: "+candidato3.getNotaFinal()+" | Nome: "+candidato3.getNome());
                }
                else
                {
                    System.out.println("Nota: "+candidato3.getNotaFinal()+" | Nome: "+candidato3.getNome());
                    System.out.println("Nota: "+candidato1.getNotaFinal()+" | Nome: "+candidato1.getNome());
                }
            }
            else
            {
                    System.out.println("Nota: "+candidato3.getNotaFinal()+" | Nome: "+candidato3.getNome());
                    System.out.println("Nota: "+candidato2.getNotaFinal()+" | Nome: "+candidato2.getNome());
                    System.out.println("Nota: "+candidato1.getNotaFinal()+" | Nome: "+candidato1.getNome());
            }
            
        }
        else if (candidato3.getNotaFinal() > candidato1.getNotaFinal()) {
            if (candidato3.getNotaFinal() > candidato2.getNotaFinal()) {
                System.out.println("Nota: "+candidato3.getNotaFinal()+" | Nome: "+candidato3.getNome());
                if (candidato1.getNotaFinal() > candidato2.getNotaFinal()) {
                    System.out.println("Nota: "+candidato1.getNotaFinal()+" | Nome: "+candidato1.getNome());
                    
                }
                else
                {
                    System.out.println("Nota: "+candidato2.getNotaFinal()+" | Nome: "+candidato2.getNome());
                    System.out.println("Nota: "+candidato1.getNotaFinal()+" | Nome: "+candidato1.getNome());
                }
            }
            else
            {
                System.out.println("Nota: "+candidato2.getNotaFinal()+" | Nome: "+candidato2.getNome());
                System.out.println("Nota: "+candidato3.getNotaFinal()+" | Nome: "+candidato3.getNome());
                System.out.println("Nota: "+candidato1.getNotaFinal()+" | Nome: "+candidato1.getNome());
            }
            
        }
    }
}