package e1;

public class Termostato {

    //Atributos
    private ModoTermostato modo;
    private State state; //Calefaccion encendida o apagada
    private float temperature;
    private int tiempo;
    private float temperatura_consigna;
    private int temporizador;
    private StringBuilder log = new StringBuilder();

    //Getters y Setters
    public State getState() {
        return state;
    }

    public float getTemperature() {
        return temperature;
    }

    public int getTiempo() {
        return tiempo;
    }

    public float getTemperatura_consigna() {
        return temperatura_consigna;
    }

    public int getTemporizador() {
        return temporizador;
    }

    public StringBuilder getLog() {
        return log;
    }

    public void setState(State state) {
        this.state = state;
    }

    public void setTemperature(float temperature) {
        this.temperature = temperature;
    }

    public void setTiempo(int tiempo) {
        this.tiempo = tiempo;
    }

    public void setTemperatura_consigna(float temperatura_consigna) {
        this.temperatura_consigna = temperatura_consigna;
    }

    public void setTemporizador(int temporizador) {
        this.temporizador = temporizador;
    }

    public void setLog(StringBuilder log) {
        this.log = log;
    }

    //Constructor
    public Termostato(float temperature) {
        this.state = State.OFF;
        this.temperature = temperature;
        this.temperatura_consigna = 25;
        this.tiempo = 0;
        this.temporizador = 0;
        this.modo = new Off();
        this.log.append("\n").append(temperature).append(" Modo Off - Calefacción apagada.\n");
    }

    //Metodos
    public void action(){ modo.action(this); }
    public void newTemperature(float temperature){ modo.newTemperature(this, temperature); }
    public void screenInfo() { modo.screenInfo(this); }
    public String registro(){
        System.out.println("\nEl termostato ha trabajado durante: "+this.getTiempo()+" minutos.\n");
        return log.toString();
        }

    //Si se seleciona Timer o Program, el tiempo del temporizador o la temperatura de consigna seran los estandar
    public void setModo(ModoTermostato modo) {
        //Si el termostato esta en modo Timer y quiere pasar a Program o viceversa salta un error
        if((this.modo.getClass().getSimpleName().equals("Timer") && modo.getClass().getSimpleName().equals("Program"))
                || (this.modo.getClass().getSimpleName().equals("Program")
                && modo.getClass().getSimpleName().equals("Timer"))) {
            throw new UnsupportedOperationException("Error: can't change mode\n");
        }
        else {
            if(this.modo.getClass().getSimpleName().equals("Timer")){
                log.append("Se desactiva el modo ").append(this.modo.getClass().getSimpleName()).append(".\n");
            }
            log.append("Se activa el modo ").append(modo.getClass().getSimpleName());

            this.modo = modo;

            if (modo.getClass().getSimpleName().equals("Timer")) {
                log.append(" ").append(temporizador).append(" minutos");
            }
            if (modo.getClass().getSimpleName().equals("Program")) {
                log.append(" a ").append(temperatura_consigna).append(" grados");
            }
            log.append(".\n");
        }
    }

    //Para modificar el tiempo del temporizador
    public void setModo(Timer modo, int tiempo_mode) {
        if((this.modo.getClass().getSimpleName().equals("Timer") && modo.getClass().getSimpleName().equals("Program"))
                || (this.modo.getClass().getSimpleName().equals("Program")
                && modo.getClass().getSimpleName().equals("Timer"))) {
            throw new UnsupportedOperationException("Error: can't change mode\n");
        }
        else {
            if(this.modo.getClass().getSimpleName().equals("Timer")){
                log.append("Se desactiva el modo ").append(this.modo.getClass().getSimpleName()).append(".\n");
            }
            log.append("Se activa el modo ").append(modo.getClass().getSimpleName());

            this.setTemporizador(tiempo_mode);
            this.modo = modo;

            if(modo.getClass().getSimpleName().equals("Timer")){
                log.append(" ").append(tiempo_mode).append(" minutos");
            }
            if(modo.getClass().getSimpleName().equals("Program")){
                log.append(" a ").append(temperatura_consigna).append(" grados");
            }
            log.append(".\n");
        }
    }

    //Para modificar la temperatura de consigna
    public void setModo(Program modo, float temperature_mode){
        if((this.modo.getClass().getSimpleName().equals("Timer") && modo.getClass().getSimpleName().equals("Program"))
                || (this.modo.getClass().getSimpleName().equals("Program")
                && modo.getClass().getSimpleName().equals("Timer"))) {
            throw new UnsupportedOperationException("Error: can't change mode\n");
        }
        else {
            if(this.modo.getClass().getSimpleName().equals("Timer")){
                log.append("Se desactiva el modo ").append(this.modo.getClass().getSimpleName()).append(".\n");
            }
            log.append("Se activa el modo ").append(modo.getClass().getSimpleName());

            this.setTemperatura_consigna(temperature_mode);
            this.modo = modo;

            if(modo.getClass().getSimpleName().equals("Timer")){
                log.append(" ").append(temporizador).append(" minutos");
            }
            if(modo.getClass().getSimpleName().equals("Program")){
                log.append(" a ").append(temperature_mode).append(" grados");
            }
            log.append(".\n");
        }
    }
}
