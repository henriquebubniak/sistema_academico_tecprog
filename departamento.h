#pragma once
#include "disciplina.h"
#include "universidade.h"
#include "listadedisciplinas.h"
#include <string>
#include <list>
#include <iostream>
using namespace std;
class ListaDeDisciplinas;
class Universidade;
class Departamento
{
public:
    Departamento(string n = "");
    ~Departamento();
    void inicializa_dep(string n_dep);
    string get_nome();
    Universidade* get_uni();
    void adiciona_disciplina(Disciplina* d);
    void adiciona_uni(Universidade* u);
    void mostra_disciplinas();
    void remove_disciplina(string n);
private:
    string nome;
    Universidade* uni;
    ListaDeDisciplinas* lista_disciplinas;
};