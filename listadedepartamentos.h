#pragma once
#include "universidade.h"
#include "departamento.h"
#include "elemdep.h"
#include "listadeuniversidades.h"
#include <vector>
#include <sstream>
using namespace std;
class Universidade;
class Departamento;
class ElemDep;
class ListaDeUniversidades;
class ListaDeDepartamentos
{
public:
    void inicializa_universidade(Universidade* u);
    void adiciona_departamento(Departamento* d);
    void remove_departamento(string n);
    Departamento* localiza_dep(string n);
    void mostra_departamentos();
    ElemDep* get_primeiro_dep();
    void gravar_dados();
    void recuperar_dados(ListaDeUniversidades* lista_unis);
    ListaDeDepartamentos(Universidade* u = NULL);
    ~ListaDeDepartamentos();
private:
    ElemDep* ultimo_dep;
    ElemDep* primeiro_dep;
    Universidade* universidade;
};