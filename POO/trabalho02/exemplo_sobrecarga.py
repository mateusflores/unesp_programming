class Calculadora:
    def somar (self, a, b, c = 0):
        return a + b + c
    

calculadora = Calculadora()

print("Primeiro caso:")
print(calculadora.somar(5, 2))

print("Segundo caso:")
print(calculadora.somar(5, 2, 3))