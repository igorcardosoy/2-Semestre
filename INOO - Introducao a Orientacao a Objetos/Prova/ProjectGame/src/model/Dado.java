package model;

import java.util.Random;

public class Dado {
    private int faces;
    private Random random;

    public Dado(int faces) {
        this.random = new Random();
        this.faces = faces;
    }

    public int jogarDado(){
        return random.nextInt(1,faces+1);
    }
}
