package e2;

import java.util.Iterator;

public class RowColumnIterator implements Iterator<Integer> {

    private int x = 0;
    private int y = 0;
    private final int[][] matriz;

    public RowColumnIterator(int[][] matriz){
        this.matriz = matriz;
    }

    public boolean hasNext() {
        if (x > matriz.length - 1) return false;
        else {
            if (x == matriz.length - 1) return y != matriz[0].length;
            else return true;
        }
    }

    public Integer next() {
        if (hasNext()) {
            if (y < matriz[x].length) return matriz[x][y++];
            else {
                y=0;
                return matriz[++x][y++];
            }
        }
        else throw new UnsupportedOperationException("Error: elemento no encontrado");
    }

    public void remove() { throw new UnsupportedOperationException(); }
}
