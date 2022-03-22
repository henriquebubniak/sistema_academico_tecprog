#pragma once
#include "departamento.h"
#include <string>
using namespace std;

class Universidade
{
public:
    Universidade();
    Universidade(string n);
    string get_nome();
    void cria_dep(string n_dep);
    Departamento* get_dep();
private:
    string nome;
    Departamento dep;
};