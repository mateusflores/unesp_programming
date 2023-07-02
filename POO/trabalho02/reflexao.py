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


palavra = "Cachorro"
numero = 42
c = Cachorro("Bob")

# Obtendo os tipos
print(type(palavra))
print(type(numero))
print(type(c))

# Verificando se um objeto é uma instância de uma classe
print(isinstance(c, Cachorro))
print(isinstance(c, str))

# Obtendo o nome da classe de um objeto
nomeClasse = c.__class__.__name__
print(nomeClasse)

# Criando uma classe durante a execução do programa
def criarClasse(nomeClasse, atributos):
    return type(nomeClasse, (object,), atributos)

ClassePessoa = criarClasse('Pessoa', {'nome':'João', 'idade':15})

pessoa = ClassePessoa()
print(f"Nome: {pessoa.nome}\nIdade: {pessoa.idade} anos")
