package e1;

import java.util.ArrayList;

public class Juego {

    //Atributos
    ArrayList<Heroe> herolist;
    ArrayList<Bestia> beastlist;

    //Constructor
    public Juego(ArrayList<Heroe> HL, ArrayList<Bestia> BL){
        this.herolist = HL;
        this.beastlist = BL;
    }

    //Metodos
    public String Fight(Heroe hero, Bestia beast) {     //Metodo en el que luchan dos personajes

        if (hero.ataque_Heroe(beast) >= beast.getArmadura()) {        //Atacan heroes
            beast.setSalud(beast.getSalud() - (hero.ataque_Heroe(beast) - beast.getArmadura()));
        }

        if (beast.getSalud() > 0 && hero.getSalud() > 0) {       //Si la bestia sigue viva ataca

            if (beast instanceof Orco) {                             //Si la bestia es un orco
                hero.setArmadura((int) (hero.getArmadura() * 0.9));  //armadura heroe disminuye 10%
            }

            if (beast.ataque_Bestia(hero) >= hero.getArmadura()) {      //Atacan bestias
                hero.setSalud(hero.getSalud() - (beast.ataque_Bestia(hero) - hero.getArmadura()));
            }

            if (beast instanceof Orco) {
                hero.setArmadura((int) (hero.getArmadura() / 0.9));
            }

        }
        if(hero.getSalud()<0) hero.setSalud(0);
        if(beast.getSalud()<0) beast.setSalud(0);
        return "Fight between " + hero.getNombre() + " (Salud = " + hero.getSalud() +
                ") and " + beast.getNombre() + " (Salud = " + beast.getSalud() + ")\n";   //Retornar valores
    }

    public String Death(Personaje p) {      //Metodo para devolver string del tipo de personaje que es p
        if (p instanceof Elfo) return "Elfo ";
        else {
            if (p instanceof Hobbit) return "Hobbit ";
            else {
                if (p instanceof Humano) return "Human ";
                else {
                    if (p instanceof Orco) return "Orco ";
                    else {
                        if (p instanceof Trasgo) return "Trasgo ";
                        else return "";
                    }
                }
            }
        }
    }

    public String Batalla() {       //Metodo en el que se define la batalla
        int turno = 1;
        StringBuilder battle = new StringBuilder();

        //Bucle que se ejecuta mientras ambas listas tengan algun elemento
        while (herolist.size() != 0 && beastlist.size() != 0) {
            battle.append("Turno ").append(turno).append(":\n");

            //Bucle para definir el numero de fight que hay en un turno
            for (int i = 0; i < Math.min(herolist.size(), beastlist.size()); i++) {

                battle.append(Fight(herolist.get(i), beastlist.get(i)));

                    if (herolist.get(i).getSalud() == 0) {  //Si el heroe muere se elimina de la lista
                        battle.append(Death(herolist.get(i))).append(herolist.get(i).getNombre()).append(" dies!\n");
                        herolist.remove(i);
                    }
                    if (beastlist.get(i).getSalud() == 0) { //Si la bestia muere se elimina de la lista
                        battle.append(Death(beastlist.get(i))).append(beastlist.get(i).getNombre()).append(" dies!\n");
                        beastlist.remove(i);
                    }
                }
            turno++;
        }

        if (herolist.size() > 0) battle.append("HEROES WIN!");
        else battle.append("BESTIAS WIN!");
        return battle.toString();
    }

    public static void main(String[] args) {
        Dado dadoheroes = new DadoTrucado(100, 0);
        Dado dadobestias = new DadoTrucado(90, 0);

        Heroe Legolas = new Elfo("Legolas", 150, 50, dadoheroes);
        Heroe Frodo = new Hobbit("Frodo", 50, 50, dadoheroes);
        Heroe Gandalf = new Humano("Gandalf", 50, 50, dadoheroes);
        Bestia Rey_trasgo = new Trasgo("Rey Trasgo", 190, 50, dadobestias);
        Bestia Mauhur = new Orco("Mauhur", 290, 50, dadobestias);

        ArrayList<Heroe> herolist = new ArrayList<>();
        ArrayList<Bestia> beastlist = new ArrayList<>();

        herolist.add(Legolas);
        herolist.add(Gandalf);
        herolist.add(Frodo);
        beastlist.add(Rey_trasgo);
        beastlist.add(Mauhur);

        Juego game = new Juego(herolist, beastlist);
        System.out.println(game.Batalla());
    }
}
