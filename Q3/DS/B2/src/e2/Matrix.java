package e2;

import java.util.Iterator;

public class Matrix implements Iterable<Integer>{

    //Atributos

    private final int[][] array;
    enum Iterators{FXC,CXF}
    Iterators i;

    //Métodos

    public static boolean Valid_matrix(int[][] m) { //Determina si la matriz es rectangular

        int c = 1;

        for (int[] ints : m) {
            if (m[0].length == ints.length) c++;
        }
        c--;

        return m.length == c;
    }

    //Metodos.operaciones
    public int ReadRow(){
        return this.array.length;
    }

    public int ReadColumns(){
        return this.array[0].length;
    }

    public int ChangeValue(int fila, int columna, int valor){
      if(fila <= array.length && columna <= array[0].length){
          array[fila-1][columna-1] = valor;
          return array[fila-1][columna-1];
      }
      else throw new UnsupportedOperationException();
    }

    public int[][] ArrayBi(){
        return this.array;
    }

    public int[] ArrayUniFila(int fila){
        if(fila<=array.length) return array[fila-1];
        else throw new UnsupportedOperationException();
    }

    public int[] ArrayUniColumna(int columna){
        if(columna <= array[0].length){
            int[] array2 = new int[array.length];
            for(int i=0; i<array.length; i++){
                array2[i] = array[i][columna-1];
            }
            return array2;
         }
        else throw new UnsupportedOperationException();
    }

    public String SMatriz(){
        StringBuilder str = new StringBuilder("[");

        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array[0].length; j++) {
                if(j!=0) str.append(" ");
                str.append(array[i][j]);
                if(j < array[0].length-1) str.append(",");
            }
            str.append("]\n");
            if(i < array.length-1) str.append("[");
        }
        return str.toString();
    }

    //Constructores

    Matrix (int num_x, int num_y, Iterators it) {
        int[][] a = new int[num_x][num_y];
        for (int i = 0; i < num_x; i++) {
            for (int j = 0; j < num_y; j++) {
                a[i][j] = 0;
            }
        }
        this.array = a;
        this.i = it;
    }

    Matrix (int[][] array, Iterators i){
        if (Valid_matrix(array)) {
            this.array = array;
            this.i = i;
        }
        else throw new UnsupportedOperationException ();
    }

    @Override
    public Iterator<Integer> iterator() {
        if(this.i == Iterators.FXC) return new RowColumnIterator(array);
        else return new ColumnRowIterator(array);
    }
}