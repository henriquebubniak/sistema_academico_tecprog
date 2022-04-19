#pragma once
#include "pessoa.h"
#include "universidade.h"
class Universidade;
class Departamento;
class Professor : public Pessoa
{
public:
    void associa_uni(Universidade* u);
    void associa_dep(Departamento* dep);
    void mostra_dados_academicos();
    Professor(string n, int d, int m, int a);
    Professor();
private:
    Universidade* uni;
    Departamento* dep;
};