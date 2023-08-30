public class Triangulo {
    private int a, b, c;

    public Triangulo(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    private boolean isTriangulo()
    {
        return (a + b > c && b + c > a && a + c > b);
    }

    public boolean isEquilatero()
    {
        if(isTriangulo())
        {
            return (a == b && a == c);
        }
    }

    public boolean isEscaleno()
    {
        if(isTriangulo())
        {
            return (a != b && b != c && a != c);
        }
    }

    public boolean isIsoceles()
    {
        if(isTriangulo() && a == b){
            return true;
        }
        if(isTriangulo() && b == c){
            return true;
        }
        if(isTriangulo() && c == a){
            return true;
        }

        return false;
    }
}