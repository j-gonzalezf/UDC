package e1;

import java.util.Random;

public class DadoTrucado extends Dado {
    public int semilla;

    public DadoTrucado(int tam, int semilla) {  //Redefinimos dado para crear una secuencia de enteros con semilla
        super(tam);
        this.rnd = new Random(semilla);
        rnd.setSeed(this.semilla);
    }

    //Metodo que te devuelve un entero daño siguiendo la secuencia

    public int daño() {
        return rnd.nextInt(this.tam);
    }
}
