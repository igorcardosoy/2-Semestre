public class Main {
  public int a;

  public Main(){
    this.a = 10;
  }

  public void print(){
    int a = 8;
    System.out.printf("%d%d", a, this.a);
    this.a++;
  }

  public static void main(String[] args) {
    new Main().print();
    new Main().print();
  }
}