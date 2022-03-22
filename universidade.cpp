#include "universidade.h"

Universidade::Universidade(string n)
{
    nome = n;
}
Universidade::Universidade()
{
    nome = "";
}

string Universidade::get_nome()
{
    return nome;
}
void Universidade::cria_dep(string n_dep)
{
    dep.inicializa_dep(n_dep);
}

Departamento* Universidade::get_dep()
{
    return &dep;
}