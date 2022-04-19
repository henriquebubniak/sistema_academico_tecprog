#pragma once
#include "disciplina.h"
class ElemDisciplina
{
public:
    ElemDisciplina();
    void adiciona_prox(ElemDisciplina* d);
    void adiciona_anterior(ElemDisciplina* d);
    void adiciona_disciplina_apontada(Disciplina* d);
    string get_nome();
    ElemDisciplina* get_prox();
private:
    ElemDisciplina* prox;
    ElemDisciplina* anterior;
    Disciplina* disciplina_apontada;
};