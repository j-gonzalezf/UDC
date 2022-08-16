package e1;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class JuegoTest {

    Dado dadoheroes = new DadoTrucado(100, 0);
    Dado dadobestias = new DadoTrucado(90, 0);

    Heroe Legolas = new Elfo("Legolas", 150, 50, dadoheroes);
    Heroe Frodo = new Hobbit("Frodo", 50, 50, dadoheroes);
    Heroe Gandalf = new Humano("Gandalf", 50, 50, dadoheroes);
    Bestia Rey_trasgo = new Trasgo("Rey Trasgo", 190, 50, dadobestias);
    Bestia Mauhur = new Orco("Mauhur", 290, 50, dadobestias);

    @Test
    void Bestia(){
        assertEquals(5, Mauhur.ataque_Bestia(Legolas));
    }

    @Test
    void Heroe(){
        assertEquals(82, Legolas.ataque_Heroe(Mauhur));
    }

    @Test
    void Personaje(){
        assertEquals("Legolas", Legolas.getNombre());
        Legolas.setSalud(20);
        Legolas.setArmadura(5);
        assertEquals(20, Legolas.getSalud());
        assertEquals(5, Legolas.getArmadura());
    }

    @Test
    void Juego() {

        ArrayList<Heroe> herolist = new ArrayList<>();
        ArrayList<Bestia> beastlist = new ArrayList<>();

        herolist.add(Legolas);
        herolist.add(Gandalf);
        herolist.add(Frodo);
        beastlist.add(Rey_trasgo);
        beastlist.add(Mauhur);

        Juego game = new Juego(herolist, beastlist);

        assertEquals("Elfo ", game.Death(Legolas));
        assertEquals("Hobbit ", game.Death(Frodo));
        assertEquals("Human ", game.Death(Gandalf));
        assertEquals("Orco ", game.Death(Mauhur));
        assertEquals("Trasgo ", game.Death(Rey_trasgo));


        assertEquals("Fight between Legolas (Salud = 150) and Mauhur (Salud = 237)\n", game.Fight(Legolas, Mauhur));
        assertEquals("Fight between Legolas (Salud = 150) and Mauhur (Salud = 195)\n", game.Fight(Legolas, Mauhur));
        assertEquals("Fight between Legolas (Salud = 109) and Mauhur (Salud = 138)\n", game.Fight(Legolas, Mauhur));

        //En la batalla hay un error que no se porque a veces me suma vida a los heroes
        assertEquals("Turno 1:\n" +
                "Fight between Legolas (Salud = 109) and Rey Trasgo (Salud = 156)\n" +
                "Fight between Gandalf (Salud = 50) and Mauhur (Salud = 138)\n" +
                "Turno 2:\n" +
                "Fight between Legolas (Salud = 144) and Rey Trasgo (Salud = 129)\n" +
                "Fight between Gandalf (Salud = 79) and Mauhur (Salud = 104)\n" +
                "Turno 3:\n" +
                "Fight between Legolas (Salud = 144) and Rey Trasgo (Salud = 84)\n" +
                "Fight between Gandalf (Salud = 79) and Mauhur (Salud = 120)\n" +
                "Turno 4:\n" +
                "Fight between Legolas (Salud = 144) and Rey Trasgo (Salud = 45)\n" +
                "Fight between Gandalf (Salud = 79) and Mauhur (Salud = 84)\n" +
                "Turno 5:\n" +
                "Fight between Legolas (Salud = 144) and Rey Trasgo (Salud = 41)\n" +
                "Fight between Gandalf (Salud = 79) and Mauhur (Salud = 84)\n" +
                "Turno 6:\n" +
                "Fight between Legolas (Salud = 144) and Rey Trasgo (Salud = 38)\n" +
                "Fight between Gandalf (Salud = 90) and Mauhur (Salud = 70)\n" +
                "Turno 7:\n" +
                "Fight between Legolas (Salud = 144) and Rey Trasgo (Salud = 0)\n" +
                "Trasgo Rey Trasgo dies!\n" +
                "Turno 8:\n" +
                "Fight between Legolas (Salud = 188) and Mauhur (Salud = 70)\n" +
                "Turno 9:\n" +
                "Fight between Legolas (Salud = 146) and Mauhur (Salud = 44)\n" +
                "Turno 10:\n" +
                "Fight between Legolas (Salud = 140) and Mauhur (Salud = 34)\n" +
                "Turno 11:\n" +
                "Fight between Legolas (Salud = 172) and Mauhur (Salud = 4)\n" +
                "Turno 12:\n" +
                "Fight between Legolas (Salud = 194) and Mauhur (Salud = 22)\n" +
                "Turno 13:\n" +
                "Fight between Legolas (Salud = 190) and Mauhur (Salud = 22)\n" +
                "Turno 14:\n" +
                "Fight between Legolas (Salud = 184) and Mauhur (Salud = 22)\n" +
                "Turno 15:\n" +
                "Fight between Legolas (Salud = 184) and Mauhur (Salud = 0)\n" +
                "Orco Mauhur dies!\n" +
                "HEROES WIN!", game.Batalla());
    }
}
