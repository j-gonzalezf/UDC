package e1;

public abstract class Personaje {
    private int salud, armadura;
    private final String nombre;
    Dado dado;

    //Constructor
    public Personaje(String nombre, int salud, int armadura, Dado dado) {
        this.nombre = nombre;
        this.salud = salud;
        this.armadura = armadura;
        this.dado = dado;
    }

    //Setters y Getters

    public void setSalud(int salud) {
        this.salud = salud;
    }

    public void setArmadura(int armadura) {
        this.armadura = armadura;
    }

    public int getSalud() { return this.salud; }

    public int getArmadura() { return this.armadura; }

    public String getNombre() {
        return this.nombre;
    }
}
