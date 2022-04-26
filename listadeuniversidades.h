#pragma once
#include <fstream>
#include "universidade.h"
#include "departamento.h"
#include "elemuni.h"
#include <vector>
using namespace std;
class Universidade;
class Departamento;
class ElemDep;
class ElemUni;
class ListaDeUniversidades
{
public:
    ListaDeUniversidades();
    ~ListaDeUniversidades();
    void adiciona_universidade(Universidade* u);
    void remove_universidade(string n);
    Universidade* localiza_uni(string n);
    void mostra_universidades();
    ElemUni* get_primeira_uni();
    void gravar_dados();
    void recuperar_dados();
private:
    ElemUni* ultima_uni;
    ElemUni* primeira_uni;
};