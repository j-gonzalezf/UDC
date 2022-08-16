package e2;

import java.util.ArrayList;
import java.util.List;

public class Worker extends TeamComponent {

    //Atributos
    //Name, hora y coste/hora
    private float hours;
    private float cost;

    //Constructor
    public Worker(String name, float hours, float cost) {
        super(name);
        this.hours = hours;
        this.cost = cost;
    }

    //Getters y Setters
    public float getHours() { return hours; }

    public float getCost() { return cost; }

    @Override
    public float hours() {
        return this.hours;
    }

    @Override
    public float cost() {
        return this.cost * this.hours;
    }

    @Override
    public void print() {
        System.out.println("\tWorker " + this.getName() + ": " + this.hours() + " hours , " + this.cost() + " €\n");
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
        return null;
    }
}
