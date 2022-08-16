package e2;

import java.util.List;

public abstract class TeamComponent {

    //Atributo
    private String name;

    //Constructor
    public TeamComponent(String name) { this.name = name; }

    //Getters y Setters
    public String getName() { return name; }

    public void setName(String name) { this.name = name; }

    //Metodo
    public abstract float hours();
    public abstract float cost();
    public abstract void print();
    public abstract List<String> coworkers();
}
