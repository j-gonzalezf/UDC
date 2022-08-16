package e1;

public abstract class Bestia extends Personaje {

    public Bestia(String nombre, int salud, int armadura, Dado dado) {
        super(nombre, salud, armadura, dado);
    }

    public int ataque_Bestia(Heroe heroe) {
        return this.dado.daño();
    }
}
