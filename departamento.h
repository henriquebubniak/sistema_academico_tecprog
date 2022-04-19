#pragma once
#include "disciplina.h"
#include "listadedisciplinas.h"
#include <string>
#include <list>
#include <iostream>
using namespace std;
class ListaDeDisciplinas;
class Departamento
{
public:
    Departamento(string n = "");
    void inicializa_dep(string n_dep);
    string get_nome();
    void adiciona_disciplina(Disciplina* d);
    void mostra_disciplinas();
    void remove_disciplina(string n);
private:
    string nome;
    ListaDeDisciplinas* lista_disciplinas;
};