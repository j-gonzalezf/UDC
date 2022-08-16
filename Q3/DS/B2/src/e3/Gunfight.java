package e3;

import e3.estrategias.Aggressive;
import e3.estrategias.Defensive;
import e3.estrategias.Kamikaze;

public class Gunfight {

    public void duel(Gunslinger g1, Gunslinger g2) {

        int round = 1;

        do {
            System.out.println("Round " + round + "-------------------------");

            //IFs para gestionar las balas de los pistoleros
            if (g1.action() == GunslingerAction.RELOAD) g1.mybalas++;
            else {
                if (g1.action() == GunslingerAction.SHOOT) g1.mybalas--;
            }
            if (g2.action() == GunslingerAction.RELOAD) g2.mybalas++;
            else {
                if (g2.action() == GunslingerAction.SHOOT) g2.mybalas--;
            }

            System.out.println("Gunslinger 1: " + g1.action() + "\n" +
                                "Gunslinger 2: " + g2.action());

            //Ifs que determinen si g1 o g2 estan vivos o muertos dependiendo su accion...
            if((g1.action() == GunslingerAction.MACHINE_GUN && g2.action() == GunslingerAction.MACHINE_GUN)
                || (g1.action() == GunslingerAction.SHOOT && g2.action() == GunslingerAction.SHOOT)) {
                g1.estado = false;
                g2.estado = false;
            }
            else {
                if (g1.action() == GunslingerAction.MACHINE_GUN
                    || (g1.action() == GunslingerAction.SHOOT && g2.action() != GunslingerAction.PROTECT)) g2.estado = false;
                else if (g2.action() == GunslingerAction.MACHINE_GUN
                        || (g2.action() == GunslingerAction.SHOOT && g1.action() != GunslingerAction.PROTECT)) g1.estado = false;
            }

            if (g1.estado && g2.estado) {
                if(round != 50) System.out.println("The duel continues ...");
            }
            else {
                if(g1.estado || g2.estado) {
                    System.out.println("\nThe duel has ended");
                    if (g1.estado) System.out.println("\nWinner : GUNSLINGER1");
                    else System.out.println("\nWinner : GUNSLINGER2");
                }
            }
            round++;
            g1.rivalAction(g2.action());
            g2.rivalAction(g1.action());
        } while (g1.estado && g2.estado && round <= 50);

        if(g1.estado && g2.estado) System.out.println("\nThe duel has ended in a DRAW");
    }

    public static void main(String[] args) {
        Gunslinger g1 = new Gunslinger(true,0,null);
        Gunslinger g2 = new Gunslinger(true, 0, null);
        Gunslinger g3 = new Gunslinger(true,0,null);
        Gunfight duelo = new Gunfight();


        Defensive defensive = new Defensive();
        Kamikaze kamikaze = new Kamikaze();
        Aggressive aggressive = new Aggressive();

        g1.setBehavior(defensive);
        g2.setBehavior(kamikaze);
        g3.setBehavior(aggressive);

        duelo.duel(g3, g2);
    }
}
