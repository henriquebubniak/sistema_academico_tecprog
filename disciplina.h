#pragma once
#include "departamento.h"
#include <string>
using namespace std;
class Departamento;
class Disciplina 
{
public:
    Disciplina(string n);
    Disciplina();
    string get_nome();
    void adiciona_prox(Disciplina* d);
    Disciplina* get_prox();
private:
    string nome;
    Departamento* dep;
    Disciplina* prox;
};