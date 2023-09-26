class Disciplina:
    def __init__(self, nomeDisciplina):
        self.nomeDisciplina = nomeDisciplina
    

class Aluno:
    def __init__(self, nome):
        self.nome = nome
        self.disciplinasMatriculadas = []
    
    def addDisciplina(self, disciplina):
        self.disciplinasMatriculadas.append(disciplina)


aluno = Aluno("Mateus")

d1 = Disciplina("Estrutura de Dados")
d2 = Disciplina("Programação Orientada a Objetos")
d3 = Disciplina("Cálculo Numérico II")

aluno.addDisciplina(d1)
aluno.addDisciplina(d2)
aluno.addDisciplina(d3)

print(f"O aluno {aluno.nome} está matriculado em:")
for disciplina in aluno.disciplinasMatriculadas:
    print("=>" + disciplina.nomeDisciplina)
