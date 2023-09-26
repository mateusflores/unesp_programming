package br.unesp.rc.lista02.exercicio02.utils;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

/**
 *
 * @author frank
 */
public class StringUtils {

    private StringUtils() {
    }

    public static String[] string2Palavras(String text) {
        return text.split(" ");
    }

    public static void imprimePalavras(String[] words) {
        for (String word : words) {
            System.out.println(word);
        }
    }

    public static void imprimeMapa(Map<String, Integer> map) {
        for (String key : map.keySet()) {
            System.out.println("A palavra " + key + " ocorre " + map.get(key) + " vez(es) no texto!");
        }
    }

    public static void limpaPontuacao(String[] words) {
        int i = 0;
        String newWord = "";

        for (String word : words) {
            if (word.endsWith(",")) {
                newWord = word.replace(",", "");
            } else if (word.endsWith(".")) {
                newWord = word.replace(".", "");
            } else {
                newWord = word;
            }

            words[i] = newWord.trim();
            i++;
        }
    }

    public static void limpaParenteses(String[] words) {
        int i = 0;
        String newWord = "";

        for (String word : words) {
            if ((word.startsWith("(")) && (word.endsWith(")"))) {
                newWord = word.replace(")", "");
                newWord = newWord.replace("(", "");
            } else if (word.endsWith(")")) {
                newWord = word.replace(")", "");
            } else if (word.startsWith("(")) {
                newWord = word.replace("(", "");
            } else {
                newWord = word;
            }

            words[i] = newWord.trim();
            i++;
        }
    }

    public static Map<String, Integer> contaPalavras(String[] words) {
        Map<String, Integer> map = new LinkedHashMap<>();
        Set<String> palavrasSemRepeticoes = new LinkedHashSet<>();
        List<String> palavras = new ArrayList<>();

        palavras.addAll(Arrays.asList(words));
        Collections.sort(palavras);
        //System.out.println("SIZE: " + palavras.size());

        palavrasSemRepeticoes.addAll(palavras);
        //System.out.println("SIZE: " + palavrasSemRepeticoes.size());

        for (String palavra : palavrasSemRepeticoes) {
            int frequencia = Collections.frequency(palavras, palavra);
            //System.out.println("Frequencia: " + frequencia);
            map.put(palavra, frequencia);
        }

        return map;
    }

    public static void top10(Map<String, Integer> map) {
        Map<String, Integer> mapTemp = new HashMap<>(map);

        Map<String, Integer> sorted = mapTemp
                .entrySet()
                .stream()
                .sorted(Collections.reverseOrder(Map.Entry.comparingByValue()))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue, (e1, e2) -> e2, LinkedHashMap::new));

        Set<String> keys = sorted.keySet();
        Iterator<String> iterator = keys.iterator();

        int i = 0;
        while (iterator.hasNext()) {
            String key = iterator.next();
            System.out.println("A palavra " + key + " ocorre " + sorted.get(key) + " vez(es) no texto!");
            i++;
        }
    }

}
