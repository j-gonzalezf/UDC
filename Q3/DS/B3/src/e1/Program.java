package e1;

public class Program implements ModoTermostato {

    @Override
    public void action(Termostato t) {
        if (t.getTemperature() < t.getTemperatura_consigna()) t.setState(State.ON);
        else t.setState(State.OFF);
    }

    @Override
    public void newTemperature(Termostato t, float currentTemperature) {
        //permite registrar una nueva temperatura.

        t.setTemperature(currentTemperature);
        t.setTiempo(t.getTiempo() + 5);
        t.action();
        t.setLog(t.getLog().append(currentTemperature).append(" Modo Program ")
                .append("(a ").append(t.getTemperatura_consigna()).append(" grados) - ")
                .append(t.getState().getCalefa()).append(".\n"));

    }

    @Override
    public void screenInfo(Termostato t){
        //proporciona la información requerida para la pantalla del termostato.
        System.out.println(t.getTemperature()+" "+t.getState()+" P "+t.getTemperatura_consigna()+"\n");
    }
}
