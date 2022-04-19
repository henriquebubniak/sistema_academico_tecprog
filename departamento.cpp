#include "departamento.h"
#include "listadedisciplinas.h"
#include "universidade.h"

Departamento::Departamento(string n)
{
    nome = n;
    lista_disciplinas = new ListaDeDisciplinas;
    lista_disciplinas->inicializa_departamento(this);
}
Departamento::~Departamento()
{
    delete lista_disciplinas;
}
void Departamento::inicializa_dep(string n_dep)
{
    nome = n_dep;
    lista_disciplinas->inicializa_departamento(this);
}
string Departamento::get_nome()
{
    return nome;
}
Universidade* Departamento::get_uni()
{
    return uni;
}
void Departamento::adiciona_disciplina(Disciplina *d)
{
    lista_disciplinas->adiciona_disciplina(d);
}
void Departamento::adiciona_uni(Universidade* u)
{
    uni = u;
}
void Departamento::mostra_disciplinas()
{
    lista_disciplinas->mostra_disciplinas();
}

void Departamento::remove_disciplina(string n)
{
   lista_disciplinas->remove_disciplina(n);
}