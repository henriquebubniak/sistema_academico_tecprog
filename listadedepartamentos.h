#pragma once
#include "universidade.h"
#include "departamento.h"
#include "elemdep.h"
class Universidade;
class Departamento;
class ElemDep;
class ListaDeDepartamentos
{
public:
    void inicializa_universidade(Universidade* u);
    void adiciona_departamento(Departamento* d);
   // void remove_departamento(string n);
    void mostra_departamentos();
    ListaDeDepartamentos(Universidade* u = NULL);
    ~ListaDeDepartamentos();
private:
    ElemDep* ultimo_dep;
    ElemDep* primeiro_dep;
    Universidade* universidade;
};