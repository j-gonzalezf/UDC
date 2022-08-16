package e2;

import java.util.List;
import java.util.ArrayList;

public class Team extends TeamComponent {

    //Atributos
    //Name y suma hora y coste/hora trabajadores
    private List<TeamComponent> elements = new ArrayList<>();

    //Constructor
    public Team(String name) { super(name); }

    //Metodos
    public void insertar(TeamComponent t){
        elements.add(t);
    }
    public void eliminar(TeamComponent t){
        elements.remove(t);
    }

    public TeamComponent getElement(int e){
        return elements.get(e);
    }

    @Override
    public float hours() {
        float sumah = 0;
        for(TeamComponent t : elements)
            sumah += t.hours();
        return sumah;
    }

    @Override
    public float cost() {
        float sumac = 0;
        for(TeamComponent t : elements)
            sumac += t.cost();
        return sumac;
    }

    @Override
    public void print() {
        System.out.println("\tTeam " + this.getName() + ": " + this.hours() + " hours , " + this.cost() + " €\n");

        for(TeamComponent tc : elements){
            tc.print();
        }
    }

    @Override
    public List<String> coworkers() {

        List<String> elem = new ArrayList<>();
        // esto se crea en TeamComponent y en insertar se añaden y aqui se retorna??

        //una funcion en teamcomponent o en proyect que recoja todos los trabajadores de un proyecto y aqui se retorne?

        for(TeamComponent tc : elements) {
            if (tc.getClass().toString().equals("Worker")) elem.add(tc.getName());
        }
        return elem;
    }
}
