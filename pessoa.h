#pragma once

#include <stdio.h>
#include <string>
#include "tempo.h"
#include "universidade.h"

using namespace std;

class Pessoa
{
public:
    Pessoa (string n, int d, int m, int a);
    Pessoa();
    void calcula_idade(int diaA, int mesA, int anoA);
    void mostra_dados();
    void associa_uni(Universidade* u);
    void associa_dep(Departamento* dep);

private:
    string nome;
    unsigned diaN;
    unsigned mesN;
    unsigned anoN;
    unsigned idade;  
    Universidade* uni;
    Departamento* dep;
};