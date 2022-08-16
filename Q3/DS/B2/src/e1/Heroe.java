package e1;

public abstract class Heroe extends Personaje{

    public Heroe(String nombre, int salud, int armadura, Dado dado) {
        super(nombre, salud, armadura, dado);
    }

    public int ataque_Heroe(Bestia bestia) {
        return Math.max(this.dado.daño(), this.dado.daño());
    }
}
