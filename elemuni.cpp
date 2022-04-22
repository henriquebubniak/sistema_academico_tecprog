#include "elemuni.h"
#include "departamento.h"

ElemUni::ElemUni()
{
    prox = NULL;
    anterior = NULL;
    universidade_apontada = NULL;
}
void ElemUni::adiciona_universidade_apontada(Universidade* u)
{
    universidade_apontada = u;
}
void ElemUni::adiciona_prox(ElemUni* u)
{
    prox = u;
}
void ElemUni::adiciona_anterior(ElemUni* u)
{
    anterior = u;
}
string ElemUni::get_nome()
{
    return universidade_apontada->get_nome();
}
ElemUni* ElemUni::get_prox()
{
    return prox;
}
ElemUni* ElemUni::get_anterior()
{
    return anterior;
}
Universidade* ElemUni::get_uni_apontada()
{
    return universidade_apontada;
}