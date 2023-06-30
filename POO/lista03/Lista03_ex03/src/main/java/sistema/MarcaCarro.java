/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package sistema;

import entities.Carro;
import entities.Montadora;

/**
 *
 * @author aluno
 */
public class MarcaCarro {
    private Carro carro;
    private Montadora montadora;

    public MarcaCarro(Carro carro, Montadora montadora) {
        this.carro = carro;
        this.montadora = montadora;
    }

    public Carro getCarro() {
        return carro;
    }

    public void setCarro(Carro carro) {
        this.carro = carro;
    }

    public Montadora getMontadora() {
        return montadora;
    }

    public void setMontadora(Montadora montadora) {
        this.montadora = montadora;
    }
    
    
}
