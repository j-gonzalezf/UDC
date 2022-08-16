package e4;

/**
 * @author j.gonzalezf
 * @author adriano.miranda
 */

public class TrafficJunction {

        public Semaforo NORTH;
        public Semaforo SOUTH;
        public Semaforo EAST;
        public Semaforo WEST;

        public TrafficJunction() {
                NORTH = new Semaforo("NORTH", Semaforo.cycle.GREEN);
                SOUTH = new Semaforo("SOUTH", Semaforo.cycle.RED);
                EAST = new Semaforo("EAST", Semaforo.cycle.RED);
                WEST = new Semaforo("WEST", Semaforo.cycle.RED);
        }

        public void timesGoesBy() {

                if (NORTH.color == Semaforo.cycle.GREEN || NORTH.color == Semaforo.cycle.AMBER_OFF) {
                        NORTH.color_change();
                        SOUTH.color_change();
                } else {
                        if (SOUTH.color == Semaforo.cycle.GREEN || SOUTH.color == Semaforo.cycle.AMBER_OFF) {
                                SOUTH.color_change();
                                EAST.color_change();

                        } else {
                                if (EAST.color == Semaforo.cycle.GREEN || EAST.color == Semaforo.cycle.AMBER_OFF) {
                                        EAST.color_change();
                                        WEST.color_change();

                                } else {
                                        if (WEST.color == Semaforo.cycle.GREEN || WEST.color == Semaforo.cycle.AMBER_OFF) {
                                                WEST.color_change();
                                                NORTH.color_change();

                                        }
                                }
                        }
                }
        }

        public void amberJunction(boolean active) {

                if (active) {
                        NORTH.amber();
                        SOUTH.amber();
                        EAST.amber();
                        WEST.amber();
                } else {
                        NORTH.color = Semaforo.cycle.GREEN;
                        SOUTH.color = Semaforo.cycle.RED;
                        EAST.color = Semaforo.cycle.RED;
                        WEST.color = Semaforo.cycle.RED;
                }
        }

        @Override
        public String toString() {
                return "[NORTH: " + NORTH.print() + NORTH.counter() +
                        "][SOUTH: " + SOUTH.print() + SOUTH.counter() +
                        "][EAST: " + EAST.print() + EAST.counter() +
                        "][WEST: " + WEST.print() + WEST.counter() + "]";
        }
}
