
class Animal:
    def __init__(self) -> None:
        pass

    def emitirSom(self):
        pass

class Cachorro(Animal):
    def __init__(self, nome):
        self.nome = nome

    def emitirSom(self):
        print("AU AU AU AU")

class Gato(Animal):
    def __init__(self, nome):
        self.nome = nome
    
    def emitirSom(self):
        print("Miau Miau Miau")


cachorro = Cachorro("Bob")
cachorro.emitirSom()

gato = Gato("Floquinho")
gato.emitirSom()
