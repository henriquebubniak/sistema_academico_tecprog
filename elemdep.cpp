#include "elemdep.h"
#include "departamento.h"

ElemDep::ElemDep()
{
    prox = NULL;
    anterior = NULL;
    departamento_apontado = NULL;
}
void ElemDep::adiciona_departamento_apontado(Departamento* d)
{
    departamento_apontado = d;
}
void ElemDep::adiciona_prox(ElemDep* d)
{
    prox = d;
}
void ElemDep::adiciona_anterior(ElemDep* d)
{
    anterior = d;
}
string ElemDep::get_nome()
{
    return departamento_apontado->get_nome();
}
ElemDep* ElemDep::get_prox()
{
    return prox;
}
ElemDep* ElemDep::get_anterior()
{
    return anterior;
}
Departamento* ElemDep::get_dep_apontado()
{
    return departamento_apontado;
}