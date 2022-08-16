package e3;

import java.util.ArrayList;
import java.util.List;

public class Gunslinger {

    //Atributos
    public boolean estado; //si el pistolero esta vivo o muerto
    public int mybalas;
    public List<GunslingerAction> rivalactions = new ArrayList<GunslingerAction>();
    public Behavior behavior;

    //Constructor
    public Gunslinger(boolean estado, int mybalas, Behavior behavior) {
        this.estado = estado;
        this.mybalas = mybalas;
        this.behavior = behavior;
    }

    //Metodos
    public GunslingerAction action(){ return behavior.action(this); }

    public int getLoads(){ return this.mybalas; }

    public void rivalAction(GunslingerAction action){
        rivalactions.add(action);
    }

    public List<GunslingerAction> getRivalActions(){
        return this.rivalactions;
    }

    public int getRivalLoads() {
        int rivalbalas = 0;
        //a partir de la lista que vas creando de las acciones de el rival, calculas cuantas balas tiene
        for (int i = 0; i < getRivalActions().size(); i++) {
            if (getRivalActions().get(i) == GunslingerAction.RELOAD) rivalbalas++;
            else {
                if (getRivalActions().get(i) == GunslingerAction.SHOOT) rivalbalas--;

            }
        }
        return rivalbalas;
    }

    public void setBehavior(Behavior behavior){
        this.behavior = behavior;
    }
}
