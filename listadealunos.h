#pragma once
#include "elemaluno.h"
class Disciplina;
class ListaDeAlunos
{
public:
    void inicializa_disciplina(Disciplina* d);
    void adiciona_aluno(Aluno* a);
    void incrementa_faltas(string n);
    void mostra_alunos();
    void adiciona_nota_p1(string n, float p);
    void adiciona_nota_p2(string n, float p);
    void adiciona_nota_p3(string n, float p);
    ListaDeAlunos();
    ListaDeAlunos(Disciplina* d);
    ~ListaDeAlunos();
private:
    ElemAluno* lista_aluno;
    ElemAluno* primeiro_aluno;
    Disciplina* disciplina;
};