#include "elemdisciplina.h"

ElemDisciplina::ElemDisciplina()
{
    prox = NULL;
    disciplina_apontada = NULL;
}
void ElemDisciplina::adiciona_disciplina_apontada(Disciplina* d)
{
    disciplina_apontada = d;
}
void ElemDisciplina::adiciona_prox(ElemDisciplina* d)
{
    prox = d;
}
string ElemDisciplina::get_nome()
{
    return disciplina_apontada->get_nome();
}

ElemDisciplina* ElemDisciplina::get_prox()
{
    return prox;
}
