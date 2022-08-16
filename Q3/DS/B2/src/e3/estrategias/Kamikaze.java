package e3.estrategias;

import e3.Behavior;
import e3.Gunslinger;
import e3.GunslingerAction;

public class Kamikaze implements Behavior {

    @Override
    public GunslingerAction action(Gunslinger g) {
        if(g.mybalas<5) return GunslingerAction.RELOAD;
        else return GunslingerAction.MACHINE_GUN;
    }
}
