package br.unesp.rc.lista02.exercicio02;

import br.unesp.rc.lista02.exercicio02.utils.StringUtils;
import java.util.Map;

/**
 *
 * @author frank
 */
public class Demo {

    public static void main(String[] args) {
        /**
         * Fonte: https://en.wikipedia.org/wiki/Java_(programming_language)
         */
        String texto = "Java is a high-level, class-based, object-oriented "
                + "programming language that is designed to have as few "
                + "implementation dependencies as possible. It is a general-purpose"
                + " programming language intended to let programmers write once, "
                + "run anywhere (WORA), meaning that compiled Java code can run on "
                + "all platforms that support Java without the need to recompile. "
                + "Java applications are typically compiled to bytecode that can "
                + "run on any Java virtual machine (JVM) regardless of the underlying "
                + "computer architecture. The syntax of Java is similar to C and C++, "
                + "but has fewer low-level facilities than either of them. The Java "
                + "runtime provides dynamic capabilities (such as reflection and "
                + "runtime code modification) that are typically not available in "
                + "traditional compiled languages. As of 2019, Java was one of the most "
                + "popular programming languages in use according to GitHub, particularly "
                + "for client–server web applications, with a reported 9 million developers.";
        
        String[] words = StringUtils.string2Palavras(texto);
        
        StringUtils.limpaPontuacao(words);        
        StringUtils.limpaParenteses(words);
        
        Map<String, Integer> map = StringUtils.contaPalavras(words);
        StringUtils.imprimeMapa(map);
        
        System.out.println("----");
        System.out.println("Palavras de maior ocorrência:");
        StringUtils.top10(map);
    }
}
