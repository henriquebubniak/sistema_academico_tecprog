#pragma once
#include "departamento.h"
class Departamento;
class ElemDep
{
public:
    ElemDep();
    void adiciona_prox(ElemDep* d);
    void adiciona_anterior(ElemDep* d);
    void adiciona_departamento_apontado(Departamento* d);
    string get_nome();
    ElemDep* get_prox();
    ElemDep* get_anterior();
    Departamento* get_dep_apontado();

private:
    ElemDep* prox;
    ElemDep* anterior;
    Departamento* departamento_apontado;
};