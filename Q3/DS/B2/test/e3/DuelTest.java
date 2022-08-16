package e3;

import e3.estrategias.Aggressive;
import e3.estrategias.Defensive;
import e3.estrategias.Kamikaze;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class DuelTest {

    Aggressive aggressive = new Aggressive();
    Defensive defensive = new Defensive();
    Kamikaze kamikaze = new Kamikaze();

    Gunslinger g1 = new Gunslinger(true, 0, null);
    Gunslinger g2 = new Gunslinger(true, 0, null);
    Gunslinger g3 = new Gunslinger(true, 0, null);

    Gunfight duelo =new Gunfight();

    @Test
    void Gunslinger(){
        assertEquals(0, g1.getLoads());

        g1.setBehavior(aggressive);
        assertEquals(GunslingerAction.RELOAD, g1.action());

        g1.rivalAction(GunslingerAction.RELOAD);
        assertEquals("["+GunslingerAction.RELOAD.toString()+"]", g1.getRivalActions().toString());
        assertEquals(1, g1.getRivalLoads());
        g1.rivalAction(GunslingerAction.SHOOT);
        assertEquals(0, g1.getRivalLoads());

        g2.setBehavior(defensive);
        g3.setBehavior(kamikaze);
        duelo.duel(g1,g2);
        duelo.duel(g2,g3);
        duelo.duel(g1,g3);
    }
}
