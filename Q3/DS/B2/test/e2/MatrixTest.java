package e2;

import org.junit.jupiter.api.Test;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

public class MatrixTest {

    public static Matrix matriz1 = new Matrix(new int[][]{{1}}, Matrix.Iterators.FXC);

    public static Matrix matriz2 = new Matrix(new int[][]{{1, 2}, {3, 4}}, Matrix.Iterators.FXC);

    public static Matrix matriz3 = new Matrix(new int[][]{{1, 2, 3, 4, 5}}, Matrix.Iterators.CXF);

    public static Matrix matriz4 = new Matrix(new int[][]{{1}, {2}, {3}}, Matrix.Iterators.CXF);

    @Test
    void Valid_matrix() {
        int[][] matri1 = {{1}};

        int[][] matri2 =
                {{1, 2},
                {3, 4}};

        int[][] matri3 = {{1, 2, 3, 4, 5}};

        int[][] matri4 =
                {{1},
                {2},
                {3}};

        int[][] notRectangle
                = {{1, 2, 3},
                {4, 5, 6, 7}};

        assertFalse(Matrix.Valid_matrix(notRectangle));

        assertTrue(Matrix.Valid_matrix(matri1));
        assertTrue(Matrix.Valid_matrix(matri2));
        assertTrue(Matrix.Valid_matrix(matri3));
        assertTrue(Matrix.Valid_matrix(matri4));
    }

    @Test
    void ReadRow() {
        assertEquals(1, matriz1.ReadRow());
        assertEquals(2, matriz2.ReadRow());
        assertEquals(1, matriz3.ReadRow());
        assertEquals(3, matriz4.ReadRow());
    }

    @Test
    void ReadColumns() {
        assertEquals(1, matriz1.ReadColumns());
        assertEquals(2, matriz2.ReadColumns());
        assertEquals(5, matriz3.ReadColumns());
        assertEquals(1, matriz4.ReadColumns());
    }

    @Test
    void ChangeValue() {
        assertEquals(2, matriz1.ChangeValue(1,1,2));

        assertThrows(UnsupportedOperationException.class,() -> matriz2.ChangeValue(3,2,4));
        assertThrows(UnsupportedOperationException.class,() -> matriz2.ChangeValue(2,3,4));
    }

    @Test
    void ArrayBi() {
        assertEquals("[[1, 2], [3, 4]]", Arrays.deepToString(matriz2.ArrayBi()));
    }

    @Test
    void ArrayUniFila() {
        assertEquals("[3, 4]", Arrays.toString(matriz2.ArrayUniFila(2)));

        assertThrows(UnsupportedOperationException.class,() -> matriz2.ArrayUniFila(3));
    }

    @Test
    void ArrayUniColumna() {
        assertEquals("[2, 4]", Arrays.toString(matriz2.ArrayUniColumna(2)));

        assertThrows(UnsupportedOperationException.class,() -> matriz2.ArrayUniColumna(3));
    }

    @Test
    void SMatriz() {
        assertEquals("[1, 2]\n[3, 4]\n", matriz2.SMatriz());
    }

    @Test
    void MatrixAddition() {
        Matrix matrizunoFXC = new Matrix(new int[][] {{1, 1}, {0, 0}}, Matrix.Iterators.FXC);
        Matrix matrizunoCXF = new Matrix(new int[][] {{1, 1}, {0, 0}}, Matrix.Iterators.CXF);

        MatrixAddition suma = new MatrixAddition();
        Matrix matrizsuma1 = suma.Suma(matriz2,matrizunoFXC);
        Matrix matrizsuma2 = suma.Suma(matriz2,matrizunoCXF);

        assertEquals("[2, 3]\n[3, 4]\n", matrizsuma1.SMatriz());
        assertEquals("[2, 2]\n[4, 4]\n", matrizsuma2.SMatriz());

        assertThrows(ArithmeticException.class,() -> suma.Suma(matriz2,matriz3));
        assertThrows(ArithmeticException.class,() -> suma.Suma(matriz2,matriz4));
    }
}
