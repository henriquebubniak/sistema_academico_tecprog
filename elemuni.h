#pragma once
#include "departamento.h"
class Departamento;
class ElemUni
{
public:
    ElemUni();
    void adiciona_prox(ElemUni* u);
    void adiciona_anterior(ElemUni* u);
    void adiciona_universidade_apontada(Universidade* u);
    string get_nome();
    ElemUni* get_prox();
    ElemUni* get_anterior();
    Universidade* get_uni_apontada();

private:
    ElemUni* prox;
    ElemUni* anterior;
    Universidade* universidade_apontada;
};