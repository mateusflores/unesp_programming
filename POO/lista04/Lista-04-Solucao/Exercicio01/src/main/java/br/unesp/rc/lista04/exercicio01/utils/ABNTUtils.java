package br.unesp.rc.lista04.exercicio01.utils;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;

/**
 *
 * @author frank
 */
public class ABNTUtils {

    private ABNTUtils() {
    }

    public static String nameToAbnt(String nomeCompleto) {
        String[] palavrasRemover = {"da"};
        String[] nomes = nomeCompleto.split(" ");

        List<String> listaNomes = new ArrayList<>(Arrays.asList(nomes));
        List<String> listaRemover = new ArrayList<>(Arrays.asList(palavrasRemover));

        removeWords(listaNomes, listaRemover);        

        int size = listaNomes.size();

        StringBuilder sb = new StringBuilder();
        sb.append(listaNomes.get(size - 1).toUpperCase()).append(", ");

        for (int i = 0; i < size - 1; i++) {
            char letra = listaNomes.get(i).charAt(0);
            sb.append(Character.toString(letra).toUpperCase()).append(". ");
        }

        return sb.toString();
    }

    private static void removeWords(
            Collection<String> collectionOrigem, 
            Collection<String> collectionRemover) {

        Iterator<String> iterator = collectionOrigem.iterator();

        while (iterator.hasNext()) {
            if (collectionRemover.contains(iterator.next())) {
                iterator.remove();
            }
        }
    }
}
