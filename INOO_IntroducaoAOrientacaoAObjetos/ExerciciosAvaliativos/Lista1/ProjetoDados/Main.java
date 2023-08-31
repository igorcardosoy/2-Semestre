
public class Main {
    public static void main(String[] args){
        Dado dado;

        dado = new Dado();

        int numDado;

        for(int index = 0; index < 3; index++){
                numDado = dado.jogarDado();
                numDado += dado.jogarDado();
                System.out.println("A soma do lance ["+ (index+1) +"] é :"+numDado);
        }

    }
}
