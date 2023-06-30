package br.unesp.rc.lista04.exercicio03;

import br.unesp.rc.lista04.exercicio03.utils.PasswordUtils;

/**
 *
 * @author frank
 */
public class Demo {

    public static void main(String[] args) {
        String senha = "teste";

        System.out.println("Original: " + senha);
        
        String novaSenha = PasswordUtils.codec(senha, 1);
        System.out.println("Codificada: " + novaSenha);

        senha = PasswordUtils.codec(novaSenha, 0);
        System.out.println("Original: " + senha);
    }

}
