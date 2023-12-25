package model.jogadores;

import java.util.Random;

public class Bot extends Jogador{

        public Bot() {
            super();
            Random random = new Random();
            setCoisa(random.nextInt(3)+1);
        }

        @Override
        public String getNome() {
            return "Bot" + toString();
        }

        @Override
        public void setCoisa(int nCoisa) {
            Random random = new Random();
            nCoisa = random.nextInt(3)+1;
            super.setCoisa(nCoisa);
        }
}
