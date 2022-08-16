package e1;

public class Elfo extends Heroe {       //Raza Elfo forma parte de los Heroes

    public Elfo(String nombre, int salud, int armadura, Dado dado) {
        super(nombre, salud, armadura, dado);
    }

    public int ataque_Heroe(Bestia bestia) {
        if(bestia instanceof Orco) return Math.max(this.dado.daño(), this.dado.daño())+10;
        else return Math.max(this.dado.daño(), this.dado.daño());
    }
}
