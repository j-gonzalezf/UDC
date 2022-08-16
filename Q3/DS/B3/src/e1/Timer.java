package e1;

public class Timer implements ModoTermostato {

    @Override
    public void action(Termostato t) {
        if(t.getTemporizador() > 0){
            t.setState(State.ON);
        }
        else {
            t.setTemporizador(0);
            t.setModo(new Off());
            t.newTemperature(t.getTemperature());
        }
    }

    @Override
    public void newTemperature(Termostato t, float currentTemperature) {
        //permite registrar una nueva temperatura.

        t.setTemperature(currentTemperature);
        t.setTemporizador(t.getTemporizador() - 5);
        t.action();
        if(t.getTemporizador() > 0){
            t.setTiempo(t.getTiempo() + 5);
            t.setLog(t.getLog().append(t.getTemperature()).append(" Modo Timer ").append("(faltan ")
                    .append(t.getTemporizador()).append(" minutos) - ").append(t.getState().getCalefa()).append(".\n"));
        }
    }

    @Override
    public void screenInfo(Termostato t){
        //proporciona la información requerida para la pantalla del termostato.
        System.out.println(t.getTemperature()+" "+t.getState()+" T "+t.getTemporizador()+"\n");
    }
}
