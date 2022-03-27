#include "disciplina.h"
Disciplina::Disciplina(string n)
{
    nome = n;
    dep = NULL;
    prox = NULL;
}
Disciplina::Disciplina()
{
    nome = "";
    dep = NULL;
    prox = NULL;
}
string Disciplina::get_nome()
{
    return nome;
}
void Disciplina::adiciona_prox(Disciplina* d)
{
    prox = d;
}
Disciplina* Disciplina::get_prox()
{
    return prox;
}
void Disciplina::adiciona_dep(Departamento* d)
{
    dep = d;
}