package e2;

import java.util.ArrayList;

public class MatrixAddition {

    Matrix Suma(Matrix matriz_a, Matrix matriz_b) {
        if (matriz_a.ReadRow() == matriz_b.ReadRow()) {
            if (matriz_a.ReadColumns() == matriz_b.ReadColumns()) {
                Matrix c = new Matrix(matriz_a.ReadRow(),matriz_b.ReadColumns(), Matrix.Iterators.FXC);

                ArrayList <Integer> array_a = new ArrayList<>();
                ArrayList <Integer> array_b = new ArrayList<>();

                for (int element : matriz_a) {
                    array_a.add(element);
                }
                for (int element : matriz_b) {
                    array_b.add(element);
                }

                int x=0;
                for (int i = 0; i < matriz_a.ReadRow(); i++) {
                    for (int j = 0; j < matriz_a.ReadColumns(); j++) {
                        c.ChangeValue(i+1,j+1,array_a.get(x) + array_b.get(x));
                        x++;
                    }
                }

                return c;
            } else throw new ArithmeticException();
        } else throw new ArithmeticException();
    }
}
