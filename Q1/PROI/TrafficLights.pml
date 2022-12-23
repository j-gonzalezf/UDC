// Jorge González Fernández
// Grupo 1.1

mtype={red,orange,green}
mtype light0=red; // luz de los semáforos en dirección horizontal
mtype light1=red; // luz de los semáforos en dirección vertical

// Ponemos active[2] porque hay 2 carriles por cada dirección, por tanto 2 semáforos
active[2] proctype P0() { // P0 = semáforos en dirección horizontal
    do
        :: atomic { if
        :: light0 == red ->
            light1 == red;
            light0 = green;
        :: light0 == green -> light0 = orange
        :: light0 == orange -> light0 = red
        fi;
        printf("P0 light in %e\n", light0);
        }
    od
}

active[2] proctype P1() { // P1 = semáforos en dirección vertical
    do
        :: atomic { if
        :: light1 == red -> 
            light0 == red;
            light1 = green;
        :: light1 == green -> light1 = orange
        :: light1 == orange -> light1 = red
        fi;
        printf("P1 light in %e\n", light1);
        }
    od
}
