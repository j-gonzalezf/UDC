package e1;

public enum State {
    ON("Calefacción encendida"),
    OFF("Calefacción apagada");

     private final String calefa;

    State(String calefa){
        this.calefa = calefa;
    }

    public String getCalefa(){
        return calefa;
    }
}
