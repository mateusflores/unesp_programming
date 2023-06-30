/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package br.rc.unesp.codificadorsenhas;

import br.rc.unesp.codificadorsenhas.util.Codificador;

/**
 *
 * @author aluno
 */
public class CodificadorSenhas {

    public static void main(String[] args) {
        String senha = "senha";
        Codificador cod = new Codificador();
        
        String senhaForte = cod.codificarSenha(senha);
        String senhaDecodificada = cod.decodificarSenha(senhaForte);
        
        System.out.println("Senha forte: " + senhaForte);
        System.out.println("Decodificada: " + senhaDecodificada);
    }
}
