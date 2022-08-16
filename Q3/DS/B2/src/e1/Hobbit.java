package e1;

public class Hobbit extends Heroe {     //Raza Hobbit forma parte de los Heroes

    public Hobbit(String nombre, int salud, int armadura, Dado dado) {
        super(nombre, salud, armadura, dado);
    }

    public int ataque_Heroe(Bestia bestia) {
        if(bestia instanceof Trasgo) return Math.max(this.dado.daño(), this.dado.daño())-5;
        else return Math.max(this.dado.daño(), this.dado.daño());
    }
}