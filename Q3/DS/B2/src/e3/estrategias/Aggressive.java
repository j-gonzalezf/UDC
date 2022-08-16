package e3.estrategias;

import e3.Behavior;
import e3.Gunslinger;
import e3.GunslingerAction;

public class Aggressive implements Behavior {

    @Override
    public GunslingerAction action(Gunslinger g) {
        if(g.getRivalActions().size() == 0) return GunslingerAction.RELOAD;
        if(g.mybalas == 0) return GunslingerAction.RELOAD;
        else return GunslingerAction.SHOOT;
    }
}