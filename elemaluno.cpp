#include "elemaluno.h"

ElemAluno::ElemAluno()
{
    prox = NULL;
    anterior = NULL;
    aluno_apontado = NULL;
}
void ElemAluno::adiciona_aluno_apontado(Aluno* a)
{
    aluno_apontado = a;
}
void ElemAluno::adiciona_prox(ElemAluno* a)
{
    prox = a;
}
void ElemAluno::adiciona_anterior(ElemAluno* a)
{
    anterior = a;
}
string ElemAluno::get_nome()
{
    return aluno_apontado->get_nome();
}

ElemAluno* ElemAluno::get_prox()
{
    return prox;
}
