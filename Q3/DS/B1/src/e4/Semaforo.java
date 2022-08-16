package e4;

import java.util.EnumSet;

public class Semaforo {

    //Atributos
    String location;
    int time;
    cycle color;

    //Constructor
    public Semaforo(String location, cycle color) {
        this.location = location;
        this.color = color;
        this.time = 0;
    }

    enum cycle {
        GREEN("GREEN"), RED("RED"), AMBER_OFF("AMBER OFF"), AMBER_ON("AMBER ON");

        public String color;

        cycle(String color) {
            this.color = color;
        }
    }

    //Cambio de colores en el semaforo y tiempo
    public void color_change() {

        if (this.color == cycle.GREEN) {
            if (this.time < 15) this.time++;
            else {
                this.color = cycle.AMBER_OFF;
                this.time = 0;
            }
        } else {
            if (this.color == cycle.AMBER_OFF) {
                if (time < 5) time++;
                else {
                    this.color = cycle.RED;
                    time = 0;
                }
            } else {

                if (this.color == cycle.RED) {
                    if (time <= 20) time++;
                    else {
                        this.color = cycle.GREEN;
                        time = 0;
                    }
                }
            }
        }
    }

    //String del tiempo de los colores verde y ambar
    public String counter() {
        String times = " " + this.time;
        if (this.color == cycle.GREEN || this.color == cycle.AMBER_OFF) return times;
        else return "";
    }

    //Activar semaforos a ambar intermitente
    public void amber() {
        this.color = cycle.AMBER_ON;
    }

    //String para imprimir color
    public String print() {
        String c = "" + this.color;
        if (this.color == cycle.AMBER_OFF) return "AMBER OFF";
        else {
            if (this.color == cycle.AMBER_ON) return "AMBER ON";
            else return c;
        }
    }
}
