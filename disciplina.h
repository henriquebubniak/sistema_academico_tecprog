#pragma once
#include "elemaluno.h"
#include <string>
using namespace std;
class Departamento;
class Disciplina 
{
public:
    Disciplina(string n);
    Disciplina();
    ~Disciplina();
    string get_nome();
    void adiciona_prox(Disciplina* d);
    Disciplina* get_prox();
    void adiciona_dep(Departamento *d);
    void adiciona_aluno(Aluno* a);
    void mostra_alunos();
private:
    string nome;
    Departamento* dep;
    Disciplina* prox;
    ElemAluno* lista_aluno;
    ElemAluno* primeiro_aluno;
};