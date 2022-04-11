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
    void adiciona_dep(Departamento *d);
    void adiciona_aluno(Aluno* a);
    void mostra_alunos();
    void incrementa_faltas(string n);
    void adiciona_nota_p1(string n, float p);
    void adiciona_nota_p2(string n, float p);
    void adiciona_nota_p3(string n, float p);
private:
    string nome;
    Departamento* dep;
    ElemAluno* lista_aluno;
    ElemAluno* primeiro_aluno;
};