class Torcedor:
    def _init_(self, nome, idade, categoria):
        self.nome = nome
        self.idade = idade
        self.categoria = categoria

    def exibir_informacoes(self):
        print("Nome:", self.nome)
        print("Idade:", self.idade)
        print("Categoria:", self.categoria)

    def calcular_valor_mensalidade(self):
        if self.categoria == "Básico":
            return 50.00
        elif self.categoria == "Premium":
            return 100.00
        else:
            return 0.00