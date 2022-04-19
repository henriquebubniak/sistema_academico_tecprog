#include "departamento.h"
#include "listadedisciplinas.h"

Departamento::Departamento(string n)
{
    nome = n;
    lista_disciplinas->inicializa_departamento(this);
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
void Departamento::adiciona_disciplina(Disciplina *d)
{
    lista_disciplinas->adiciona_disciplina(d);
}
void Departamento::mostra_disciplinas()
{
    lista_disciplinas->mostra_disciplinas();
}

void Departamento::remove_disciplina(string n)
{
   lista_disciplinas->remove_disciplina(n);
}