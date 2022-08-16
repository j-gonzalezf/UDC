package e1;

/**
 * @author j.gonzalezf
 * @author adriano.miranda
 */

public class StringUtilities {

    public static boolean isValidMix(String a, String b, String c) {

        int contador = 0;
        int contador_a = 0;
        int contador_b = 0;

        if (c.length() == a.length() + b.length()) {

            while (contador < c.length()) {

                if (contador_a < a.length() && contador_b < b.length()) {
                    if (c.charAt(contador) == a.charAt(contador_a)) {
                        contador_a++;
                    } else {
                        if (c.charAt(contador) == b.charAt(contador_b)) {
                            contador_b++;
                        }
                    }
                    contador++;
                } else {
                    if (contador_a == a.length() && contador_b != b.length()) {
                        if (c.charAt(contador) == b.charAt(contador_b)) contador_b++;
                    }
                    if (contador_b == b.length() && contador_a != a.length()) {
                        if (c.charAt(contador) == a.charAt(contador_a)) contador_a++;
                    }
                    contador++;
                }
            }
            return contador_a == a.length() && contador_b == b.length();
        } else return false;
    }

    public static String generateRandomValidMix(String a, String b) {

        int contador = 0;
        int contador_a = 0;
        int contador_b = 0;

        char[] x = new char[a.length()];
        char[] y = new char[b.length()];
        StringBuilder c = new StringBuilder();

        for (int i = 0; i < a.length(); i++) {
            x[i] = a.charAt(i);
        }
        for (int i = 0; i < b.length(); i++) {
            y[i] = b.charAt(i);
        }

        int log_total = a.length() + b.length();

        while (contador < log_total) {

            //Variable r aleatoria que permite escoger el caracter siguiente entre el String a y b
            int r = (int) (Math.random() * 2);

            if (r == 0 && contador_a < a.length()) {
                c.append(x[contador_a]);
                contador_a++;
                contador++;
            }
            if (r == 1 && contador_b < b.length()) {
                c.append(y[contador_b]);
                contador_b++;
                contador++;
            }
        }
        return c.toString();
    }

    /*
        public static void main(String[] args) {
            String a = "JameS";
            String b = "Gosling";
            String c = "JameGSslinog";
            String w = generateRandomValidMix(a,b);
            boolean kaka;

            kaka = isValidMix(a,b,c);

            System.out.println(w);

            if (kaka) System.out.println("true");
            else System.out.println("false");
        }
    */
}
