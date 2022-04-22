#pragma once
#include "universidade.h"
#include "departamento.h"
#include "elemuni.h"
class Universidade;
class Departamento;
class ElemDep;
class ListaDeUniversidades
{
public:
    void adiciona_universidade(Universidade* u);
    void remove_universidade(string n);
    void mostra_universidades();
    ElemUni* get_primeira_uni();
    ListaDeUniversidades();
    ~ListaDeUniversidades();
private:
    ElemUni* ultima_uni;
    ElemUni* primeira_uni;
};