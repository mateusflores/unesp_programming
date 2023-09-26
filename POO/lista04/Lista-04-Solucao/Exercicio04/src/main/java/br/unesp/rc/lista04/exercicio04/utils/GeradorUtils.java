package br.unesp.rc.lista04.exercicio04.utils;

import br.unesp.rc.lista04.exercicio04.modelo.Atributo;
import br.unesp.rc.lista04.exercicio04.modelo.Classe;

/**
 *
 * @author frank
 */
public class GeradorUtils {

    public static String printaCodigo(Classe classe) {
        StringBuilder buffer = new StringBuilder();

        buffer.append("package ").append(classe.getPacote()).append(";").append("\n\n");
        buffer.append("public class ").append(classe.getNome()).append(" {").append("\n\n");

        for (Atributo a : classe.getListaAtributos()) {
            buffer.append("\t").append(a.getModificador()).append(" ").append(a.getTipo()).append(" ").append(a.getNome()).append(";").append('\n');
        }
        buffer.append('\n');
        buffer.append("\tpublic ").append(classe.getNome()).append("() {").append("\n\t}").append("\n\n");
        buffer.append("\tpublic ").append(classe.getNome()).append("(");

        int i = 0;
        for (Atributo a : classe.getListaAtributos()) {
            if (i < classe.getListaAtributos().size() - 1) {
                buffer.append(a.getTipo()).append(" ").append(a.getNome()).append(", ");
            } else {
                buffer.append(a.getTipo()).append(" ").append(a.getNome()).append(")");
            }
            i++;

        }

        buffer.append(" {\n");

        for (Atributo a : classe.getListaAtributos()) {
            buffer.append("\t\tthis.").append(a.getNome()).append(" = ").append(a.getNome()).append(";").append('\n');
        }

        buffer.append("\t}\n\n");

        //getter e setter
        for (Atributo a : classe.getListaAtributos()) {
            //getter
            buffer.append("\tpublic ").append(a.getTipo()).append(" get").append(capitalize(a.getNome())).append("() {").append('\n');
            buffer.append("\t\treturn ").append(a.getNome()).append(";\n\t}").append("\n\n");

            //setter
            buffer.append("\tpublic void set").append(capitalize(a.getNome())).append("(").append(a.getTipo()).append(" ").append(a.getNome()).append(") {").append('\n');
            buffer.append("\t\tthis.").append(a.getNome()).append(" = ").append(a.getNome()).append(";").append('\n').append("\t}");
            buffer.append("\n\n");
        }

        buffer.append('}');

        return buffer.toString();
    }

    private static String capitalize(String s) {
        StringBuilder buffer = new StringBuilder();

        String aux = s.substring(1);
        char ch = s.charAt(0);

        ch = Character.toUpperCase(ch);

        buffer.append(ch).append(aux);

        return buffer.toString();
    }
}
