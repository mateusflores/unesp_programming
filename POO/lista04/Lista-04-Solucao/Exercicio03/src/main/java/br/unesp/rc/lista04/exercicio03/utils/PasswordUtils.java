package br.unesp.rc.lista04.exercicio03.utils;

/**
 *
 * @author frank
 */
public class PasswordUtils {

    private PasswordUtils() {
    }

    private static String m1(String s) {
        String str = "";

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            int ascii = (int) c;
            ascii += 1;
            c = (char) ascii;
            str += String.valueOf(c);
        }
        return str;
    }

    private static String m2(String s) {
        String str = "";

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            int ascii = (int) c;
            ascii += 2;
            c = (char) ascii;
            str += String.valueOf(c);
        }
        return str;
    }

    private static String m3(String s) {
        String str = "";

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            int ascii = (int) c;
            ascii += 3;
            c = (char) ascii;
            str += String.valueOf(c);
        }
        return str;
    }

    private static String m4(String s) {
        String str = "";

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            int ascii = (int) c;
            ascii -= 1;
            c = (char) ascii;
            str += String.valueOf(c);
        }
        return str;
    }

    private static String m5(String s) {
        String str = "";

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            int ascii = (int) c;
            ascii -= 2;
            c = (char) ascii;
            str += String.valueOf(c);
        }
        return str;
    }

    private static String m6(String s) {
        String str = "";

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            int ascii = (int) c;
            ascii -= 3;
            c = (char) ascii;
            str += String.valueOf(c);
        }
        return str;
    }

    /**
     * password é a String a ser codificada codec é uma flag que indica se o
     * algoritmo de methodName é utilizado para codificar ou decodificar a
     * senha.
     */
    public static String codec(String password, int codec) {
        String s;
        String token = "xuhwmopiakzpgn";        

        if (codec == 1) {
            // codifica a string
            password += token;

            s = m1(password);

            s = m2(s);

            s = m3(s);
        } else {
            // reconstitui a string
            s = m6(password);

            s = m5(s);

            s = m4(s);

            s = s.substring(0, (s.length() - token.length()));
        }

        return s;
    }

}
