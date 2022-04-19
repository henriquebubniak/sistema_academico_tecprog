#include "universidade.h"

Universidade::Universidade(string n)
{
    nome = n;
    lista_dep = new ListaDeDepartamentos;
    lista_dep->inicializa_universidade(this);
}
Universidade::~Universidade()
{
    delete lista_dep;
}
string Universidade::get_nome()
{
    return nome;
}
void Universidade::adiciona_dep(Departamento* d)
{
    lista_dep->adiciona_departamento(d);
    d->adiciona_uni(this);
}
/*void Universidade::remove_dep(string n)
{
    lista_dep->remove_departamento(n);
}*/
void Universidade::mostra_deps()
{
    lista_dep->mostra_departamentos();
}