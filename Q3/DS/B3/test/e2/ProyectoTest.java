package e2;

import org.junit.Test;

public class ProyectoTest {

    //Proyect DS = new Proyect();

    Worker edu = new Worker("Edu", 20,25);
    Worker david = new Worker("David", 10,18);
    Worker juan = new Worker("Juan", 60,15);
    Worker bea = new Worker("Bea", 50,20);
    Worker laura = new Worker("Laura", 40,12);

    Team teaching = new Team("Teaching");
    Team theory = new Team("Theory");
    Team practicum = new Team("Practicum");

    @Test
    public void Proyecto(){
        teaching.insertar(edu);
        theory.insertar(david);
        practicum.insertar(juan);
        practicum.insertar(bea);
        practicum.insertar(laura);

    }
}
