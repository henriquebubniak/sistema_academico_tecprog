#pragma once
#include "disciplina.h"
#include <string>
#include <list>
#include <iostream>
using namespace std;
class Disciplina;
class Departamento
{
public:
    Departamento(string n = "");
    void inicializa_dep(string n_dep);
    string get_nome();
    void adiciona_disciplina(Disciplina* d);
    void mostra_disciplinas();
private:
    string nome;
    Disciplina* lista_disc;
};