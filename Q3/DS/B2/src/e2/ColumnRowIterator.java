package e2;

import java.util.Iterator;

public class ColumnRowIterator implements Iterator<Integer> {

    private int x = 0;
    private int y = 0;
    private final int[][] matriz;

    public ColumnRowIterator(int[][] matriz){
        this.matriz = matriz;
    }

    public boolean hasNext() {
        if (y > matriz[0].length - 1) return false;
        else {
            if (y == matriz[0].length - 1) return x != matriz.length;
            else return true;
        }
    }

    public Integer next(){
        if(hasNext()) {
            if (x < matriz.length) return matriz[x++][y];
            else {
                x=0;
                return matriz[x++][++y];
            }
        }
        else throw new UnsupportedOperationException("Error: elemento no encontrado");
    }

    public void remove() { throw new UnsupportedOperationException(); }
}
