#include "departamento.h"

Departamento::Departamento(string n)
{
    nome = n;
}
void Departamento::inicializa_dep(string n_dep)
{
    nome = n_dep;
}
string Departamento::get_nome()
{
    return nome;
}