package e1;

public class Manual implements ModoTermostato {

    @Override
    public void action(Termostato t) {
        t.setState(State.ON);
    }

    @Override
    public void newTemperature(Termostato t, float currentTemperature) {
        //permite registrar una nueva temperatura.

        t.setTemperature(currentTemperature);
        t.setTiempo(t.getTiempo() + 5);
        t.action();
        t.setLog(t.getLog().append(currentTemperature).append(" Modo Manual - ")
                .append(t.getState().getCalefa()).append(".\n"));
    }

    @Override
    public void screenInfo(Termostato t){
        //proporciona la información requerida para la pantalla del termostato.
        System.out.println(t.getTemperature()+" "+t.getState()+" M\n");
    }
}
