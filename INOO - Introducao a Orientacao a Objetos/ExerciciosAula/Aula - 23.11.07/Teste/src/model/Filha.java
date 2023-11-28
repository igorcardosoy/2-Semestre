package model;

public class Filha extends Pai{
  public String method() {
    return "Method - Filha";
  }

  public void print() {
    System.out.println(method());
  }
}
