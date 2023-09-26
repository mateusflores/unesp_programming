class Clube:
    def _init_(self, nome):
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
