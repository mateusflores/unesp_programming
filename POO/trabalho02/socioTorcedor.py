class Clube:
    def __init__(self, nome):
        self.nome = nome
        self.socios_torcedores = []

    def adicionar_socio_torcedor(self, socio_torcedor):
        self.socios_torcedores.append(socio_torcedor)

    def listar_socios_torcedores(self):
        print("Sócios-torcedores do", self.nome)
        for socio_torcedor in self.socios_torcedores:
            socio_torcedor.exibir_informacoes()
            print("---------------------------")

    def calcular_faturamento_mensal(self):
        faturamento = 0.0
        for socio_torcedor in self.socios_torcedores:
            faturamento += socio_torcedor.calcular_valor_mensalidade()
        return faturamento
    

class Torcedor:
    def __init__(self, nome, idade, categoria):
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
        

clube = Clube("Meu Clube")
socio1 = Torcedor("João", 25, "Básico")
socio2 = Torcedor("Maria", 30, "Premium")

clube.adicionar_socio_torcedor(socio1)
clube.adicionar_socio_torcedor(socio2)

clube.listar_socios_torcedores()
faturamento = clube.calcular_faturamento_mensal()
print("Faturamento mensal:", faturamento)