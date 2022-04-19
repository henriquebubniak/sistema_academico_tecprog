#include "disciplina.h"
#include "professor.h"
Disciplina::Disciplina(string n):
lista_alunos(this)
{
    nome = n;
    dep = NULL;
}
Disciplina::Disciplina():
lista_alunos(this)
{
    nome = "";
    dep = NULL;
}
string Disciplina::get_nome()
{
    return nome;
}
void Disciplina::adiciona_dep(Departamento *d)
{
    dep = d;
}

void Disciplina::adiciona_aluno(Aluno *a)
{
   lista_alunos.adiciona_aluno(a);
}
void Disciplina::mostra_alunos()
{
    lista_alunos.mostra_alunos();
}

Disciplina::~Disciplina()
{
}

void Disciplina::incrementa_faltas(string n)
{
    lista_alunos.incrementa_faltas(n);
}
void Disciplina::adiciona_nota_p1(string n, float p)
{
    lista_alunos.adiciona_nota_p1(n, p);
}
void Disciplina::adiciona_nota_p2(string n, float p)
{
    lista_alunos.adiciona_nota_p2(n, p);
}
void Disciplina::adiciona_nota_p3(string n, float p)
{
    lista_alunos.adiciona_nota_p3(n, p);
}