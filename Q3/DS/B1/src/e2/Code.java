package e2;

/**
 * @author j.gonzalezf
 * @author adriano.miranda
 */

public class Code {

        public static boolean isKeypadValid(char[][] keypad) {

                char[] abc = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

                if (keypad == null || keypad.length == 0) return false;
                else {
                        //Determinate if keypad is null
                        for (int i = 0; i < keypad.length; i++) {
                                if (keypad[i] == null) return false;
                        }
                }

                //Determinate if the keypad is a rectangle
                int c = 1;

                for (char[] chars : keypad) {
                        if (keypad[0].length == chars.length) c++;
                }
                c--;

                if (keypad.length != c) return false;

                //Determinate if the keypad follow the sequence

                int contador_abc = 0;


                if (keypad[0][0] == abc[contador_abc]) {
                        contador_abc++;

                        //Element case
                        if (keypad.length == 1 && keypad[0].length == 1) return true;

                        //Lineal case
                        if (keypad.length > 1 && keypad[0].length == 1) {
                                for (int i = 0; i < keypad[0].length; i++) {
                                        for (int j = 0; j < keypad.length; j++) {
                                                if (keypad[j][i] == abc[contador_abc]) contador_abc++;
                                        }
                                }
                        }
                        if (keypad.length == 1) {
                                for (int i = 0; i < keypad.length; i++) {
                                        for (int j = 0; j < keypad[i].length; j++) {
                                                if (keypad[i][j] == abc[contador_abc]) contador_abc++;
                                        }
                                }
                        }
                }

                //Matriz case
                if (keypad.length > 1 && keypad[0].length > 1) {
                        if (keypad[0][1] == keypad[1][0]) return false;

                        if (keypad[0][1] == abc[contador_abc]) {
                                //Evaluacion horizontal
                                for (int i = 0; i < keypad.length; i++) {
                                        for (int j = 0; j < keypad[i].length; j++) {
                                                if (keypad[i][j] == abc[contador_abc]) contador_abc++;
                                        }
                                }
                        }
                        if (keypad[1][0] == abc[contador_abc]) {
                                //Evaluacion vertical
                                for (int i = 0; i < keypad[0].length; i++) {
                                        for (int j = 0; j < keypad.length; j++) {
                                                if (keypad[j][i] == abc[contador_abc]) contador_abc++;
                                        }
                                }
                        }
                }
                return contador_abc == keypad.length * keypad[0].length;
        }

        public static boolean areMovementsValid(String[] movements) {

                char[] moves = {'U', 'D', 'L', 'R'};
                int m = 0;

                if (movements == null) return false;
                else {
                        for (int i = 0; i < movements.length; i++) {
                                if (movements[i] != null) {
                                        for (int j = 0; j < movements[i].length(); j++) {
                                                for (int k = 0; k < 4; k++) {
                                                        if (movements[i].charAt(j) == moves[k]) m++;
                                                }
                                        }
                                        if (m != movements[i].length()) return false;
                                        m = 0;
                                } else return false;
                        }
                        return true;
                }
        }

        public static String obtainCode(char[][] keypad, String[] movements) {

                int x = 0;
                int y = 0;
                char number;
                StringBuilder codec = new StringBuilder();

                if (isKeypadValid(keypad)) {
                        for (int i = 0; i < movements.length; i++) {
                                for (int j = 0; j < movements[i].length(); j++) {


                                        if (movements[i].charAt(j) == 'R') {
                                                if (x < keypad[0].length - 1) x++;
                                        }
                                        if (movements[i].charAt(j) == 'U') {
                                                if (y > 0) y--;
                                        }
                                        if (movements[i].charAt(j) == 'L') {
                                                if (x > 0) x--;
                                        }
                                        if (movements[i].charAt(j) == 'D') {
                                                if (y < keypad.length - 1) y++;
                                        }
                                }
                                number = keypad[y][x];
                                codec.append(number);
                        }
                        return codec.toString();
                } else throw new IllegalArgumentException();
        }

        /*
        public static void main(String[] args) {

                char [][] keypad = {{'1', '2', '3', '4', '5'}};
                String[] wrong = {"DUU", "DD"};
                String codigo;

                boolean test1, test2;

                test1 = isKeypadValid(keypad);
                if (test1) System.out.println("true");
                else System.out.println("false");

                test2 = areMovementsValid(wrong);
                if (test2) System.out.println("true");
                else System.out.println("false");

                codigo = ""+obtainCode(keypad,wrong);
                System.out.println(codigo);

        }
         */
}
