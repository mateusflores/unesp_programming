class Impressora:
    def __init__(self, marca):
        self.marca = marca
        self.reservatorio = None
    
    def imprimir(self):
        if self.reservatorio == None:
            print("A impressora está sem tinta")
        else:
            print("Imprimindo...")

    def addTinta(self, tinta):
        self.reservatorio = tinta


class Tinta:
    def __init__(self, cor):
        self.cor = cor
    

impressora = Impressora("HP")
# Tentando imprimir
impressora.imprimir()

tinta = Tinta("Azul")
# Adicionando tinta
impressora.addTinta(tinta)

impressora.imprimir()

