#include "elemaluno.h"

ElemAluno::ElemAluno()
{
    prox = NULL;
    anterior = NULL;
    aluno_apontado = NULL;
    n_faltas = 0;
    p1 = 0;
    p2 = 0;
    p3 = 0;
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
void ElemAluno::incrementa_faltas()
{
    n_faltas++;
}

void ElemAluno::adiciona_nota_p1(float p)
{
    p1 = p;
}
void ElemAluno::adiciona_nota_p2(float p)
{
    p2 = p;
}
void ElemAluno::adiciona_nota_p3(float p)
{
    p3 = p;
}
int ElemAluno::get_faltas()
{
    return n_faltas;
}