package e2;

public class Proyect {

    TeamComponent allTeams;

    public Proyect(TeamComponent allTeams){
        this.allTeams = allTeams;
    }

    public void printTeam() {
        allTeams.print();
    }

    public void coworkers(){
        //registra todos los trabajadores del proyecto y dps lo hereda a Team y Worker??*
    }
    /*
    Los cotrabajadores de un trabajador o equipo son todos los trabajadores que participan en el mismo proyecto.
     */
}
