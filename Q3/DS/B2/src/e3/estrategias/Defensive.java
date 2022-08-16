package e3.estrategias;

import e3.Behavior;
import e3.Gunslinger;
import e3.GunslingerAction;

public class Defensive implements Behavior {

    @Override
    public GunslingerAction action(Gunslinger g) {
        if(g.getRivalActions().size() == 0) return GunslingerAction.RELOAD;
        return GunslingerAction.PROTECT;
    }
}
