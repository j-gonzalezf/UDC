package e1;

import java.util.Random;

public class Dado {
    public int tam;
    public Random rnd = new Random();

    public Dado(int tam) {
        this.tam = tam + 1;
    }

    //Metodo que te devuelve un entero aleatorio daño

    public int daño() {
        return rnd.nextInt(this.tam);
    }
}

