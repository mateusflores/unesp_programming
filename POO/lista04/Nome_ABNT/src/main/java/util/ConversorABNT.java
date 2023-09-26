/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package util;

/**
 *
 * @author aluno
 */
public class ConversorABNT {
    private String name;
    private String[] tokens;

    public ConversorABNT(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    
    public String generateABNT() {
        tokens = name.split(" ");
        int totalTokens = tokens.length;
         
        StringBuilder abnt = new StringBuilder();
        
        abnt.append(tokens[totalTokens-1]);
        abnt.append(", ");
        
        for (int i=0; i<totalTokens-1; i++) {
            if (tokens[i].length() > 2) {
                abnt.append(tokens[i].charAt(0));
                abnt.append(".");
            }
        }
        return abnt.toString();   
    }
    
    
}
