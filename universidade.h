#pragma once
#include "departamento.h"
#include "listadedepartamentos.h"
#include "aluno.h"
#include "listadealunos.h"
#include <string>
using namespace std;
class ListaDeDepartamentos;
class Universidade
{
public:
    Universidade(string n = "");
    ~Universidade();
    string get_nome();
    void adiciona_aluno(Aluno* a);
    void adiciona_dep(Departamento* d);
    //void remove_dep(string n);
    void mostra_deps();
private:
    string nome;
    ListaDeDepartamentos* lista_dep;
    ListaDeAlunos* lista_alunos;
};